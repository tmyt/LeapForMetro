#include"pch.h"

#include"LeapBridge.h"
#include"Utilities.h"

using namespace LeapBridge;

Frame::Frame(Leap::Frame& frame)
{
	frame_ = frame;
}

Hand^ Frame::Hand(int32 id){
	return LeapTypeToBridge<LeapBridge::Hand>(frame_.hand(id));
}
Pointable^ Frame::Pointable(int32 id){
	return LeapTypeToBridge<LeapBridge::Pointable>(frame_.pointable(id));
}
Finger^ Frame::Finger(int32 id){
	return LeapTypeToBridge<LeapBridge::Finger>(frame_.finger(id));
}
Tool^ Frame::Tool(int32 id){
	return LeapTypeToBridge<LeapBridge::Tool>(frame_.tool(id));
}
Gesture^ Frame::Gesture(int32 id){
	return LeapTypeToBridge<LeapBridge::Gesture>(frame_.gesture(id));
}
Vector^ Frame::Translation(Frame^ sinceFrame)
{
	return LeapVectorToBridge(frame_.translation(sinceFrame->frame_));
}
Vector^ Frame::RotationAxis(Frame^ sinceFrame)
{
	return LeapVectorToBridge(frame_.rotationAxis(sinceFrame->frame_));
}
Matrix^ Frame::RotationMatrix(Frame^ sinceFrame)
{
	//return LeapMatrixToBridge(frame_.rotationMatrix(sinceFrame->frame_));
	return nullptr;
}
Windows::Foundation::Collections::IVectorView<LeapBridge::Gesture^> ^ Frame::GesturesFrom(Frame^ sinceFrame)
{
	return LeapCollectionToBridge<LeapBridge::Gesture>(frame_.gestures(sinceFrame->frame_));
}
float Frame::TranslationProbability(Frame^ sinceFrame){
	return frame_.translationProbability(sinceFrame->frame_);
}
float Frame::RotationAngle(Frame^ sinceFrame){
	return frame_.rotationAngle(sinceFrame->frame_);
}
float Frame::RotationProbability(Frame^ sinceFrame){
	return frame_.rotationProbability(sinceFrame->frame_);
}
float Frame::ScaleFactor(Frame^ sinceFrame){
	return frame_.scaleFactor(sinceFrame->frame_);
}
float Frame::ScaleProbability(Frame^ sinceFrame){
	return frame_.scaleProbability(sinceFrame->frame_);
}