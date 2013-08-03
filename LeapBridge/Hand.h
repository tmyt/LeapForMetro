#pragma once

#include"LeapSDK\include\Leap.h"

#include"Interface.h"
#include"Frame.h"
#include"Pointable.h"
#include"Utilities.h"
#include"Vector.h"

namespace LeapBridge
{
	public ref class Hand sealed
	{
		friend Hand^ LeapTypeToBridge<Hand>(Leap::Hand&);

	public:
		property int32 Id{ int32 get(){ return hand_.id(); } }
		property Frame^ Frame { LeapBridge::Frame^ get() { return LeapTypeToBridge<LeapBridge::Frame>(hand_.frame()); }}
		property Windows::Foundation::Collections::IVectorView<Pointable^>^ Pointables {
			Windows::Foundation::Collections::IVectorView<Pointable^>^ get(){
				return LeapCollectionToBridge<LeapBridge::Pointable>(hand_.pointables());
			}
		}
		property Windows::Foundation::Collections::IVectorView <Finger^>^ Fingers{
			Windows::Foundation::Collections::IVectorView <Finger^>^ get(){
				return LeapCollectionToBridge<LeapBridge::Finger>(hand_.fingers());
			}
		}
		property Windows::Foundation::Collections::IVectorView <Tool^>^ Tools{
			Windows::Foundation::Collections::IVectorView <Tool^>^ get(){
				return LeapCollectionToBridge<LeapBridge::Tool>(hand_.tools());
			}
		}
		property Vector^ PalmPosition{
			Vector^ get() { return LeapVectorToBridge(hand_.palmPosition()); }
		}
		property Vector^ StabilizedPalmPosition{
			Vector^ get() { return LeapVectorToBridge(hand_.stabilizedPalmPosition()); }
		}
		property Vector^ PalmVelocity{
			Vector^ get() { return LeapVectorToBridge(hand_.palmVelocity()); }
		}
		property Vector^ PalmNormal{
			Vector^ get() { return LeapVectorToBridge(hand_.palmNormal()); }
		}
		property Vector^ Direction{
			Vector^ get() { return LeapVectorToBridge(hand_.direction()); }
		}
		property Vector^ SphereCenter{
			Vector^ get() { return LeapVectorToBridge(hand_.sphereCenter()); }
		}
		property float SphereRadius { float get(){ return hand_.sphereRadius(); }}
		property float TimeVisible { float get() { return hand_.timeVisible(); }}
		property bool IsValid { bool get() { return hand_.isValid(); } }

		IPointable^ Pointable(int32 id);
		Finger^ Finger(int32 id);
		Tool^ Tool(int32 id);
		Vector^ Translation(LeapBridge::Frame^ sinceFrame);
		float TranslationProbability(LeapBridge::Frame^ sinceFrame);
		Vector^ RotationAxis(LeapBridge::Frame^ sinceFrame);
		float RotationAngle(LeapBridge::Frame^ sinceFrame);
		float RotationAngle(LeapBridge::Frame^ sinceFrame, Vector^ axis);
		Matrix^ RotationMatrix(LeapBridge::Frame^ sinceFrame);
		float RotationProbability(LeapBridge::Frame^ sinceFrame);
		float ScaleFactor(LeapBridge::Frame^ sinceFrame);
		float ScaleProbability(LeapBridge::Frame^ sinceFrame);
	};

}