package main

import (
	"fmt"
	"go-fastdds"
)

func main() {
	pa_ := fastdds.NewParticipant("Participant_pub")
	type_ := fastdds.NewTypeSupport()
	fastdds.RegisterType(pa_, type_)
	pub_ := fastdds.CreatePublisher(pa_)
	topic_ := fastdds.CreateTopic(pa_, type_, "ShapeTopic")
	listener_ := fastdds.NewPubListener()
	fmt.Println(listener_)
	writer_ := fastdds.CreateWriter(pub_, topic_, listener_)
	shape := fastdds.NewShape("red")
	fastdds.SendMessage(writer_, listener_, shape)
}
