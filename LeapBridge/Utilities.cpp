#include"pch.h"

#include"LeapSDK\include\Leap.h"

#include"Interface.h"
#include"Vector.h"
#include"Matrix.h"
#include"Frame.h"

namespace LeapBridge
{
	Vector^ LeapVectorToBridge(Leap::Vector& vector)
	{
		return ref new Vector(vector.x, vector.y, vector.z);
	}

	Leap::Vector BridgeToLeapVector(Vector^ vector)
	{
		return Leap::Vector(vector->X, vector->Y, vector->Z);
	}

	Matrix^ LeapMatrixToBridge(Leap::Matrix& matrix){
		return ref new Matrix(
			LeapVectorToBridge(matrix.xBasis),
			LeapVectorToBridge(matrix.yBasis),
			LeapVectorToBridge(matrix.zBasis),
			LeapVectorToBridge(matrix.origin));
	}

	Leap::Matrix BridgeToLeapMatrix(Matrix^ matrix){
		return Leap::Matrix(
			BridgeToLeapVector(matrix->XBasis),
			BridgeToLeapVector(matrix->YBasis),
			BridgeToLeapVector(matrix->ZBasis),
			BridgeToLeapVector(matrix->Origin));
	}

	const Leap::Frame& GetLeapFrameFromBridge(Frame^ frame){
		return frame->frame_;
	}
}