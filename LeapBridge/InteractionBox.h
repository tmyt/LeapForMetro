#pragma once

#include"LeapSDK\include\Leap.h"

#include"Vector.h"
#include"Utilities.h"

namespace LeapBridge
{
	public ref class InteractionBox sealed
	{
		friend InteractionBox^ LeapTypeToBridge<InteractionBox>(Leap::InteractionBox&);

	public:
		Vector^ NormalizePoint(Vector^ position, bool clamp){
			return LeapVectorToBridge(
				interactionBox_.normalizePoint(BridgeToLeapVector(position), clamp));
		}
		Vector^ NormalizePoint(Vector^ position){
			return NormalizePoint(position, true);
		}
		Vector^ DenormalizePoint(Vector^ normalizedPosition){
			return LeapVectorToBridge(
				interactionBox_.denormalizePoint(BridgeToLeapVector(normalizedPosition)));
		}
		property Vector^ Center{
			Vector^ get(){ return LeapVectorToBridge(interactionBox_.center()); }
		}
		property float Width{
			float get() { return interactionBox_.width(); }
		}
		property float Height{
			float get() { return interactionBox_.height(); }
		}
		property float Depth{
			float get() { return interactionBox_.depth(); }
		}
		property bool IsValid {
			bool get() { return interactionBox_.isValid(); }
		}
	};
}