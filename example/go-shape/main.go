package main

import (
	"fmt"
	"go-fastdds"
)

func main() {
	//************PUBLISHER**********************
	pa_ := fastdds.NewParticipant("Participant_pub")
	type_ := fastdds.NewTypeSupport()
	fastdds.RegisterType(pa_, type_)
	pub_ := fastdds.CreatePublisher(pa_)
	topic_ := fastdds.CreateTopic(pa_, type_, "ShapeTopic")
	listener_ := fastdds.NewPubListener()
	fmt.Println(listener_)
	writer_ := fastdds.CreateWriter(pub_, topic_, listener_)
	for {
		shape := fastdds.NewShape("red")
		fastdds.SendMessage(writer_, listener_, shape)
	}
	//************SUBSCRIBER**********************
	// pa_ := fastdds.NewParticipant("Participant_sub")
	// type_ := fastdds.NewTypeSupport()
	// fastdds.RegisterType(pa_, type_)
	// topic_ := fastdds.CreateTopic(pa_, type_, "ShapeTopic")
	// sub_ := fastdds.NewSubscriber(pa_)
	// lis_ := fastdds.NewSubscriberListener()
	// go fastdds.CreateDataReader(sub_, topic_, lis_)
	// var ch chan int
	// <-ch // locking
}
