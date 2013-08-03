#include"pch.h"

#include"LeapBridge.h"

using namespace LeapBridge;

void ListenerBridge::onInit(const Leap::Controller&)
{
	listener_->OnInit();
}

void ListenerBridge::onConnect(const Leap::Controller&)
{
	listener_->OnConnect();
}

void ListenerBridge::onDisconnect(const Leap::Controller&)
{
	listener_->OnDisconnect();
}

void ListenerBridge::onExit(const Leap::Controller&)
{
	listener_->OnExit();
}

void ListenerBridge::onFrame(const Leap::Controller&)
{
	listener_->OnFrame();
}

void ListenerBridge::onFocusGained(const Leap::Controller&)
{
	listener_->OnFocusGained();
}

void ListenerBridge::onFocusLost(const Leap::Controller&)
{
	listener_->OnFocusLost();
}
