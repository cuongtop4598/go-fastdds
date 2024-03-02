#ifdef __cplusplus
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include "./example/shape/ShapePubSubTypes.h"
#include "./example/shape/ShapePubSubTypes.cxx"
#include "./example/shape/Shape.h"
#include "./example/shape/Shape.cxx"
extern "C"
{
#endif
void *NewPubSubType();
void *NewShape(char* color);
#ifdef __cplusplus
}

#endif