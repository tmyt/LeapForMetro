#include"pch.h"

#include "LeapBridge.h"
#include "Utilities.h"

using namespace LeapBridge;

Controller::Controller()
{
	bridge_ = new ListenerBridge(this);
	controller_.addListener(*bridge_);
}

Controller::~Controller()
{
	controller_.removeListener(*bridge_);
	delete bridge_;
}

Frame^ Controller::GetFrame(int history)
{
	auto frame = controller_.frame(history);
	return LeapTypeToBridge<LeapBridge::Frame>(frame);
}
