#include"pch.h"

#include"LeapSDK\include\Leap.h"

#include"Interface.h"
#include"Hand.h"
#include"Pointable.h"

using namespace LeapBridge;

IPointable^ Hand::Pointable(int32 id)
{
	return (IPointable^) LeapTypeToBridge<LeapBridge::Pointable>(hand_.pointable(id));
}
Finger^ Hand::Finger(int32 id)
{
	return LeapTypeToBridge<LeapBridge::Finger>(hand_.finger(id));
}
Tool^ Hand::Tool(int32 id)
{
	return LeapTypeToBridge<LeapBridge::Tool>(hand_.tool(id));
}
Vector^ Hand::Translation(LeapBridge::Frame^ sinceFrame)
{
	return LeapVectorToBridge(hand_.translation(GetLeapFrameFromBridge(sinceFrame)));
}
float Hand::TranslationProbability(LeapBridge::Frame^ sinceFrame)
{
	return hand_.translationProbability(GetLeapFrameFromBridge(sinceFrame));
}
Vector^ Hand::RotationAxis(LeapBridge::Frame^ sinceFrame)
{
	return LeapVectorToBridge(hand_.rotationAxis(GetLeapFrameFromBridge(sinceFrame)));
}
float Hand::RotationAngle(LeapBridge::Frame^ sinceFrame)
{
	return hand_.rotationAngle(GetLeapFrameFromBridge(sinceFrame));
}
float Hand::RotationAngle(LeapBridge::Frame^ sinceFrame, Vector^ axis)
{
	return hand_.rotationAngle(GetLeapFrameFromBridge(sinceFrame), BridgeToLeapVector(axis));
}
Matrix^ Hand::RotationMatrix(LeapBridge::Frame^ sinceFrame)
{
	return LeapMatrixToBridge(hand_.rotationMatrix(GetLeapFrameFromBridge(sinceFrame)));
}
float Hand::RotationProbability(LeapBridge::Frame^ sinceFrame)
{
	return hand_.rotationProbability(GetLeapFrameFromBridge(sinceFrame));
}
float Hand::ScaleFactor(LeapBridge::Frame^ sinceFrame)
{
	return hand_.scaleFactor(GetLeapFrameFromBridge(sinceFrame));
}
float Hand::ScaleProbability(LeapBridge::Frame^ sinceFrame)
{
	return hand_.scaleProbability(GetLeapFrameFromBridge(sinceFrame));
}