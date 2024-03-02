package fastdds

// #include "FastDDS.h"
// #include "types.h"
// #cgo CXXFLAGS: -std=c++11
// #cgo CFLAGS: -I. -I/usr/local/include
// #cgo LDFLAGS: -lfastcdr -lfastrtps -lcrypto
import "C"

import (
	"unsafe"
)

func NewParticipant(name string) unsafe.Pointer {
	return C.FastddsCreateParticipant(C.CString(name))
}

func NewTypeSupport() unsafe.Pointer {
	pubsubTypeGenerated := newPubSubType()
	return C.FastddsNewTypeSupport(pubsubTypeGenerated)
}

func RegisterType(participant unsafe.Pointer, typeSupport unsafe.Pointer) unsafe.Pointer {
	return C.FastddsRegisterType(participant, typeSupport)
}

func CreatePublisher(participant unsafe.Pointer) unsafe.Pointer {
	return C.FastddsCreatePublisher(participant)
}

func CreateTopic(participant unsafe.Pointer, typeSupport unsafe.Pointer, topicName string) unsafe.Pointer {
	return C.FastddsCreateTopic(participant, typeSupport, C.CString(topicName))
}

func CreateWriter(publisher unsafe.Pointer, topic unsafe.Pointer, listener unsafe.Pointer) unsafe.Pointer {
	return C.FastddsCreateWriter(publisher, topic, listener)
}

func SendMessage(writer unsafe.Pointer, listener unsafe.Pointer, data unsafe.Pointer) unsafe.Pointer {
	return C.FastddsSendMessage(writer, listener, data)
}

func NewPubListener() unsafe.Pointer {
	return C.FastddsCreatePublisherListener()
}

func NewShape(color string) unsafe.Pointer {
	return C.NewShape(C.CString(color))
}

func newPubSubType() unsafe.Pointer {
	return C.NewPubSubType()
}
