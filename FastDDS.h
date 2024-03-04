#ifdef __cplusplus
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>

class PubListener : public eprosima::fastdds::dds::DataWriterListener
{
public:
    PubListener() = default;

    ~PubListener() override = default;

    void on_publication_matched(
        eprosima::fastdds::dds::DataWriter *writer,
        const eprosima::fastdds::dds::PublicationMatchedStatus &info) override;

    int matched = 0;
};

class SubListener : public eprosima::fastdds::dds::DataReaderListener
{
public:
    SubListener() = default;
    ~SubListener() override = default;
    
    void on_data_available(
        eprosima::fastdds::dds::DataReader *reader) override;

    void on_subscription_matched(
        eprosima::fastdds::dds::DataReader *reader,
        const eprosima::fastdds::dds::SubscriptionMatchedStatus &info) override;

    int matched = 0;
    uint32_t samples = 0;
};
extern "C"
{
#endif

    void *FastddsCreateParticipant(char *name);
    void *FastddsNewTypeSupport(void *pubsubTypeGenerated);
    void *FastddsRegisterType(void *participant, void *typeSupport);
    void *FastddsCreatePublisher(void *participant);
    void *FastddsCreateTopic(void *participant, void *typeSupport, char *topicName);
    void *FastddsCreateWriter(void *publisher, void *topic, void *pubListener);
    void *FastddsCreatePublisherListener();
    void *FastddsCreateSubscriberListener();
    void *FastddsCreateSubscriber(void *participant);
    void *FastddsCreateDataReader(void *subscriber, void* topic, void* subListener);
    void *FastddsSendMessage(void *writer, void *listener, void *data);
#ifdef __cplusplus
}

#endif