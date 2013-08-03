#pragma once

#include"LeapSDK\include\Leap.h"

#include"Utilities.h"
#include"Hand.h"
#include"Pointable.h"
#include"LeapBridge.h"

namespace LeapBridge
{
	public ref class Frame sealed
	{
		friend Frame^ LeapTypeToBridge<Frame>(Leap::Frame&);
		friend const Leap::Frame& GetLeapFrameFromBridge(Frame^ frame);
	public:
		property uint64 Id{
			uint64 get(){ return frame_.id(); }
		}
		property uint64 TimeStamp{
			uint64 get(){ return frame_.timestamp(); }
		}
		property Windows::Foundation::Collections::IVectorView<Hand^>^ Hands
		{
			Windows::Foundation::Collections::IVectorView<Hand^> ^ get()
			{
				return LeapCollectionToBridge<LeapBridge::Hand>(frame_.hands());
			}
		}
		property Windows::Foundation::Collections::IVectorView<Pointable^> ^ Pointables
		{
			Windows::Foundation::Collections::IVectorView<Pointable^> ^get()
			{
				return LeapCollectionToBridge<LeapBridge::Pointable>(frame_.pointables());
			}
		}
		property Windows::Foundation::Collections::IVectorView<Finger^> ^ Fingers
		{
			Windows::Foundation::Collections::IVectorView<Finger^> ^ get()
			{
				return LeapCollectionToBridge<LeapBridge::Finger>(frame_.fingers());
			}
		}
		property Windows::Foundation::Collections::IVectorView<Tool^> ^ Tools
		{
			Windows::Foundation::Collections::IVectorView<Tool^> ^ get()
			{
				return LeapCollectionToBridge<LeapBridge::Tool>(frame_.tools());
			}
		}
		property Windows::Foundation::Collections::IVectorView<Gesture^>^ Gestures
		{
			Windows::Foundation::Collections::IVectorView<Gesture^>^ get()
			{
				return LeapCollectionToBridge<LeapBridge::Gesture>(frame_.gestures());
			}
		}
		property InteractionBox^ InteractionBox{
			LeapBridge::InteractionBox^ get(){
				return LeapTypeToBridge<LeapBridge::InteractionBox>(frame_.interactionBox());
			}
		}
		property float CurrentFramesPerSecond{
			float get(){
				return frame_.currentFramesPerSecond();
			}
		}
		property bool IsValid{
			bool get(){
				return frame_.isValid();
			}
		}

		Windows::Foundation::Collections::IVectorView<LeapBridge::Gesture^> ^GesturesFrom(Frame^ sinceFrame);
		float TranslationProbability(Frame^ sinceFrame);
		float RotationAngle(Frame^ sinceFrame);
		float RotationProbability(Frame^ sinceFrame);
		float ScaleFactor(Frame^ sinceFrame);
		float ScaleProbability(Frame^ sinceFrame);
		Hand^ Hand(int32 id);
		Pointable^ Pointable(int32 id);
		Finger^ Finger(int32 id);
		Tool^ Tool(int32 id);
		Gesture^ Gesture(int32 id);
		Vector^ Translation(Frame^ sinceFrame);
		Vector^ RotationAxis(Frame^ sinceFrame);
		Matrix^ RotationMatrix(Frame^ sinceFrame);
	};
}