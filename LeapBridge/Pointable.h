#pragma once

#include"Interface.h"

#include"Enums.h"
#include"Vector.h"
#include"Frame.h"
#include"Utilities.h"

namespace LeapBridge
{
	public interface class IPointable
	{
	public:
		property int32 Id { virtual int32 get(); }
		property Frame^ Frame { virtual LeapBridge::Frame^ get(); }
		property Hand^ Hand { virtual LeapBridge::Hand^ get(); }
		property Vector^ TipPosition { virtual Vector^ get(); }
		property Vector^ TipVelocity { virtual Vector^ get(); }
		property Vector^ Direction {virtual Vector^ get(); }
		property float Width {virtual float get(); }
		property float length { virtual float get(); }
		property bool IsFinger {virtual bool get(); }
		property bool IsTool{virtual bool get(); }
		property bool IsValid{ virtual bool get(); }
		property Zone TouchZone { virtual Zone get(); }
		property float TouchDistance { virtual float get();  }
		property Vector^ StabilizedTipPosition { virtual Vector^ get();  }
		property float TimeVisible { virtual float get(); }
	};

#define IMPLEMENTS_INTERFACE_MEMBERS \
	property int32 Id { virtual int32 get() { return container_.id(); }} \
	property LeapBridge::Frame^ Frame { virtual LeapBridge::Frame^ get() { return LeapTypeToBridge<LeapBridge::Frame>(container_.frame()); } } \
	property Hand^ Hand { virtual LeapBridge::Hand^ get() { return LeapTypeToBridge<LeapBridge::Hand>(container_.hand()); }} \
	property Vector^ TipPosition { virtual Vector^ get() { return LeapVectorToBridge(container_.tipPosition()); }} \
	property Vector^ TipVelocity { virtual Vector^ get() { return LeapVectorToBridge(container_.tipVelocity()); }} \
	property Vector^ Direction { virtual Vector^ get() { return LeapVectorToBridge(container_.direction()); }} \
	property float Width { virtual float get() { return container_.width(); }} \
	property float length { virtual float get() { return container_.length(); }} \
	property bool IsFinger { virtual bool get() { return container_.isFinger(); }} \
	property bool IsTool { virtual bool get() { return container_.isTool(); }} \
	property bool IsValid { virtual bool get() { return container_.isValid(); }} \
	property Zone TouchZone { virtual Zone get() { return (Zone) container_.touchZone(); }} \
	property float TouchDistance { virtual float get() { return container_.touchDistance(); }} \
	property Vector^ StabilizedTipPosition { virtual Vector^ get() { return LeapVectorToBridge(container_.stabilizedTipPosition()); }} \
	property float TimeVisible { virtual float get() { return container_.timeVisible(); }}

	public ref class Pointable sealed : public IPointable
	{
		friend Pointable^ LeapTypeToBridge<Pointable>(Leap::Pointable&);

	public:
		IMPLEMENTS_INTERFACE_MEMBERS
	};
	public ref class Tool sealed : public IPointable
	{
		friend Tool^ LeapTypeToBridge<Tool>(Leap::Tool&);

	public:
		IMPLEMENTS_INTERFACE_MEMBERS
	};
	public ref class Finger sealed : public IPointable
	{
		friend Finger^ LeapTypeToBridge<Finger>(Leap::Finger&);

	public:
		IMPLEMENTS_INTERFACE_MEMBERS
	};
}