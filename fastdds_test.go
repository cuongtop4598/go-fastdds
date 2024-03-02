package fastdds

import "testing"

func Test(t *testing.T) {
	pa_ := NewParticipant("Participant_pub")
	type_ := NewTypeSupport()
	RegisterType(pa_, type_)
	pub_ := CreatePublisher(pa_)
	topic_ := CreateTopic(pa_, type_, "ShapeTopic")
	listener_ := NewPubListener()
	writer_ := CreateWriter(pub_, topic_, listener_)
	shape := NewShape("red")
	SendMessage(writer_, listener_, shape)
}
