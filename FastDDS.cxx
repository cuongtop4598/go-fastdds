#include "FastDDS.h"
#include "./example/shape/Shape.h"
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/qos/PublisherQos.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>

#include <thread>
#include <chrono>

using namespace eprosima::fastdds::dds;

extern "C" void *FastddsCreateParticipant(char *name)
{
    DomainParticipantQos pqos;
    pqos.name(name);
    return (void *)DomainParticipantFactory::get_instance()->create_participant(0, pqos);
}

extern "C" void *FastddsNewTypeSupport(void *pubsubTypeGenerated)
{
    return (void *)new eprosima::fastdds::dds::TypeSupport((eprosima::fastdds::dds::TopicDataType *)pubsubTypeGenerated);
}

extern "C" void *FastddsRegisterType(void *participant, void *typeSupport)
{
    auto returnCode = ((eprosima::fastdds::dds::TypeSupport *)typeSupport)->register_type((eprosima::fastdds::dds::DomainParticipant *)participant);
    std::cout << returnCode.RETCODE_ERROR << std::endl;
}

extern "C" void *FastddsCreatePublisher(void *participant)
{
    return (void *)((eprosima::fastdds::dds::DomainParticipant *)participant)->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);
}

extern "C" void *FastddsCreateTopic(void *participant, void *typeSupport, char *topicName)
{
    return (void *)((eprosima::fastdds::dds::DomainParticipant *)participant)->create_topic(topicName, ((eprosima::fastdds::dds::TypeSupport *)typeSupport)->get_type_name(), TOPIC_QOS_DEFAULT);
}

extern "C" void *FastddsCreatePublisherListener() 
{
    return (void *) new PubListener();
}

extern "C" void *FastddsCreateWriter(void* publisher, void* topic, void* listener)
{
    return (void*)((eprosima::fastdds::dds::Publisher *)publisher)->create_datawriter((eprosima::fastdds::dds::Topic*)topic, DATAWRITER_QOS_DEFAULT, (eprosima::fastdds::dds::DataWriterListener*)listener);
}

extern "C" void *FastddsSendMessage(void* writer, void* listener_ , void* data)
{
    while (((PubListener*)listener_)->matched == 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(250)); // Sleep 250 ms
        std::cout << "sending..." << std::endl;
    }

    if(((eprosima::fastdds::dds::DataWriter*)writer)->write(data)) 
    {
        std::cout << "Send OK" << std::endl;
    } else {
        std::cout << "Send FAIL" << std::endl;
    }
}


void PubListener::on_publication_matched(
        eprosima::fastdds::dds::DataWriter*,
        const eprosima::fastdds::dds::PublicationMatchedStatus& info)
{
    std::cout << info.current_count << std::endl;
    if (info.current_count_change == 1)
    {
        matched = info.total_count;
        std::cout << "DataWriter matched." << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        matched = info.total_count;
        std::cout << "DataWriter unmatched." << std::endl;
    }
    else
    {
        std::cout << info.current_count_change
                  << " is not a valid value for PublicationMatchedStatus current count change" << std::endl;
    }
}

void SubListener::on_data_available(
    DataReader *reader)
{
    // Take data
    Shape st;
    SampleInfo info;

    if (reader->take_next_sample(&st, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.valid_data)
        {
            // Print your structure data here.
            ++samples;
            std::cout << "Sample received, count=" << samples << std::endl;
            std::cout << "Shape color: " << st.color() << " x: "  <<  st.position_x() << " " << "y: " << st.position_y() << std::endl;
        }
        else
        {
            std::cout << info.view_state << std::endl;
        }
    }
}

void SubListener::on_subscription_matched(
    DataReader *,
    const SubscriptionMatchedStatus &info)
{
    if (info.current_count_change == 1)
    {
        matched = info.total_count;
        std::cout << "Subscriber matched." << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        matched = info.total_count;
        std::cout << "Subscriber unmatched." << std::endl;
    }
    else
    {
        std::cout << info.current_count_change
                  << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
    }
}

extern "C" void *FastddsCreateSubscriberListener() 
{
    return (void *) new SubListener();
}

extern "C" void *FastddsCreateSubscriber(void *participant)
{
    return  (void *)((eprosima::fastdds::dds::DomainParticipant *)participant)->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);
}

extern "C" void *FastddsCreateDataReader(void *subscriber,void* topic, void* subListener)
{
    DataReaderQos rqos = DATAREADER_QOS_DEFAULT;
    rqos.reliability().kind = RELIABLE_RELIABILITY_QOS;
    return (void*)((eprosima::fastdds::dds::Subscriber*)subscriber)->create_datareader((eprosima::fastdds::dds::Topic*)topic, rqos, (SubListener*)subListener);
}