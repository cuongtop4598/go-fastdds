#ifdef __cplusplus
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>

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
extern "C"
{
#endif

void *FastddsCreateParticipant(char* name);
void *FastddsNewTypeSupport(void *pubsubTypeGenerated);
void *FastddsRegisterType(void* participant, void* typeSupport);
void *FastddsCreatePublisher(void* participant);
void *FastddsCreateTopic(void* participant, void* typeSupport,char* topicName);
void *FastddsCreateWriter(void* publisher, void* topic, void* listener);
void *FastddsCreatePublisherListener();
void *FastddsSendMessage(void* writer, void *listener, void* data);
#ifdef __cplusplus
}

#endif