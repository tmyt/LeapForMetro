#pragma once

#include"LeapSDK\include\Leap.h"

namespace LeapBridge
{
	// Enums
	public enum class GestureType : int {
		Invalid = Leap::Gesture::TYPE_INVALID,
		Swipe = Leap::Gesture::TYPE_SWIPE,
		Circle = Leap::Gesture::TYPE_CIRCLE,
		ScreenTap = Leap::Gesture::TYPE_SCREEN_TAP,
		KeyTap = Leap::Gesture::TYPE_KEY_TAP,
	};
	[Platform::Metadata::Flags]
	public enum class PolicyFlag : unsigned int {
		Default = Leap::Controller::POLICY_DEFAULT,
		BackgroundFrames = Leap::Controller::POLICY_BACKGROUND_FRAMES,
	};
	public enum class Zone {
		None = Leap::Pointable::ZONE_NONE,
		Hovering = Leap::Pointable::ZONE_HOVERING,
		Touching = Leap::Pointable::ZONE_TOUCHING,
	};
}