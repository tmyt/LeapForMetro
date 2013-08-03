#pragma once

#include<cmath>

#include"Vector.h"

namespace LeapBridge
{
	public ref class Matrix
	{
		Vector^ xBasis_, ^yBasis_, ^zBasis_, ^origin_;

	public:
		property Vector^ XBasis { Vector^ get() { return xBasis_; }}
		property Vector^ YBasis { Vector^ get() { return yBasis_; }}
		property Vector^ ZBasis { Vector^ get() { return zBasis_; }}
		property Vector^ Origin { Vector^ get() { return origin_; }}

		Matrix(){
			xBasis_ = ref new Vector(1, 0, 0);
			yBasis_ = ref new Vector(0, 1, 0);
			zBasis_ = ref new Vector(0, 0, 1);
			origin_ = ref new Vector(0, 0, 0);
		}
		Matrix(Matrix^ other){
			xBasis_ = ref new Vector(other->xBasis_);
			yBasis_ = ref new Vector(other->yBasis_);
			zBasis_ = ref new Vector(other->zBasis_);
			origin_ = ref new Vector(other->origin_);
		}
		Matrix(Vector^ xBasis, Vector^ yBasis, Vector^ zBasis)
		{
			xBasis_ = ref new Vector(xBasis);
			yBasis_ = ref new Vector(yBasis);
			zBasis_ = ref new Vector(zBasis);
			origin_ = ref new Vector(0, 0, 0);
		}
		Matrix(Vector^ xBasis, Vector^ yBasis, Vector^ zBasis, Vector^ origin)
		{
			xBasis_ = ref new Vector(xBasis);
			yBasis_ = ref new Vector(yBasis);
			zBasis_ = ref new Vector(zBasis);
			origin_ = ref new Vector(origin);
		}
		Matrix(Vector^ axis, float angleRadians)
		{
			origin_ = ref new Vector(0, 0, 0);
			SetRotation(axis, angleRadians);
		}
		Matrix(Vector^ axis, float angleRadians, Vector^ translation)
		{
			origin_ = ref new Vector(translation);
			SetRotation(axis, angleRadians);
		}

		static property Matrix^ Identity { Matrix^ get() { return ref new Matrix(); }}

		void SetRotation(Vector^ axis, float angleRadiant)
		{
			Vector^ n = axis->Normalized;
			float s = std::sin(angleRadiant);
			float c = std::cos(angleRadiant);
			float C = (1 - c);
			xBasis_ = ref new Vector(n->X * n->X * C + c, n->X * n->Y * C - n->Z * s, n->X * n->Z * C + n->Y * s);
			yBasis_ = ref new Vector(n->Y * n->X * C + n->Z * s, n->Y * n->Y * C + c, n->Y * n->Z * C - n->X * s);
			zBasis_ = ref new Vector(n->Z * n->X * C - n->Y * s, n->Z * n->Y * C + n->X * s, n->Z * n->Z * C + c);
		}
		/** çÏÇËÇ©ÇØ... **/
	};
}