#pragma once

namespace LeapBridge
{
	interface class IPointable;

	partial ref class Controller sealed {

	};
	partial ref class Frame sealed {
		Leap::Frame frame_;
		Frame(Leap::Frame& frame);
	};
	partial ref class Gesture sealed {
		Gesture(Leap::Gesture&){}
	};
	partial ref class Config sealed {

	};
	partial ref class Device sealed {

	};
	partial ref class Screen sealed {

	};
	partial ref class Hand sealed {
		Leap::Hand hand_;
		Hand(Leap::Hand& hand){ hand_ = hand; }
	};
	partial ref class Pointable sealed {
		Pointable(Leap::Pointable& from){ container_ = from; }
		Leap::Pointable container_;
	};
	partial ref class Finger sealed {
		Finger(Leap::Finger& from){ container_ = from; }
		Leap::Finger container_;
	};
	partial ref class Tool sealed {
		Tool(Leap::Tool& from){ container_ = from; }
		Leap::Tool container_;
	};
	partial ref class InteractionBox sealed {
		Leap::InteractionBox interactionBox_;
		InteractionBox(Leap::InteractionBox& interactionBox) 
			: interactionBox_(interactionBox){}
	};

	// LeapMath
	partial ref class Vector sealed {

	};
	partial ref class Matrix sealed {

	};
}