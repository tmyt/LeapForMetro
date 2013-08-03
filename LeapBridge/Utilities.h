#pragma once

#include"LeapSDK\include\Leap.h"

#include"Interface.h"
#include"Vector.h"

namespace LeapBridge
{
	Vector^ LeapVectorToBridge(Leap::Vector& vector);
	Leap::Vector BridgeToLeapVector(Vector^ vector);

	Matrix^ LeapMatrixToBridge(Leap::Matrix& matrix);
	Leap::Matrix BridgeToLeapMatrix(Matrix^ matrix);

	const Leap::Frame& GetLeapFrameFromBridge(Frame^ frame);

	template<typename T, typename U>
	T^ LeapTypeToBridge(U& from)
	{
		return ref new T(from);
	}

	template<typename T, typename U>
	Windows::Foundation::Collections::IVectorView<T^>^ LeapCollectionToBridge(U& collection)
	{
		auto list = ref new Platform::Collections::Vector<T^>();
		for (auto object : collection){ 
			list->Append(LeapTypeToBridge<T>(object)); 
		}
		return list->GetView();
	}
}