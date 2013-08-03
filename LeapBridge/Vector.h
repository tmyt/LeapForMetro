#pragma once

namespace LeapBridge
{
	public ref class Vector sealed
	{
	private:
		float x_, y_, z_;
	public:
		Vector() : x_(0), y_(0), z_(0){}
		Vector(float x, float y, float z) : x_(x), y_(y), z_(z){}
		Vector(Vector^ vector) : x_(vector->X), y_(vector->Y), z_(vector->Z){}

		property float X{ float get(){ return x_; }}
		property float Y{ float get(){ return y_; }}
		property float Z{ float get(){ return z_; }}

		static property Vector^ Zero { Vector^ get(){ return ref new Vector(); } }
		static property Vector^ XAxis { Vector^ get(){ return ref new Vector(1, 0, 0); } }
		static property Vector^ YAxis { Vector^ get(){ return ref new Vector(0, 1, 0); }}
		static property Vector^ ZAxis { Vector^ get(){ return ref new Vector(0, 0, 1); }}

		static property Vector^ Left { Vector^ get(){ return ref new Vector(-1, 0, 0); }}
		static property Vector^ Right { Vector^ get() { return XAxis; } }
		static property Vector^ Down { Vector^ get() { return ref new Vector(0, -1, 0); }}
		static property Vector^ Up { Vector^ get() { return YAxis; }}
		static property Vector^ Forward { Vector^ get() { return ref new Vector(0, 0, -1); }}
		static property Vector^ Backward { Vector^ get() { return ZAxis; }}

		float Magnitude(){
			return std::sqrt(X*X + Y*Y + Z*Z);
		}
		float MagnitudeSquared(){
			return X*X + Y*Y + Z*Z;
		}
		float DistanceTo(Vector^ other) {
			return std::sqrt((x_ - other->x_)*(x_ - other->x_) +
				(y_ - other->y_)*(y_ - other->y_) +
				(z_ - other->z_)*(z_ - other->z_));
		}
		float AngleTo(Vector^ other) {
			float denom = MagnitudeSquared() * other->MagnitudeSquared();
			if (denom <= 0.0f) {
				return 0.0f;
			}
			return std::acos(Dot(other) / std::sqrt(denom));
		}
		property float Pitch {
			float get(){
				return std::atan2(y_, -z_);
			}
		}
		property float Yaw {
			float get(){
				return std::atan2(x_, -z_);
			}
		}
		property float Roll {
			float get() {
				return std::atan2(x_, -y_);
			}
		}
		float Dot(Vector^ other) {
			return (x_ * other->x_) + (y_ * other->y_) + (z_ * other->z_);
		}
		Vector^ Cross(Vector^ other) {
			return ref new Vector((y_ * other->z_) - (z_ * other->y_),
				(z_ * other->x_) - (x_ * other->z_),
				(x_ * other->y_) - (y_ * other->x_));
		}
		property Vector^ Normalized {
			Vector^ get(){
				float denom = MagnitudeSquared();
				if (denom <= 0.0f) {
					return Vector::Zero;
				}
				denom = 1.0f / std::sqrt(denom);
				return ref new Vector(x_ * denom, y_ * denom, z_ * denom);
			}
		}
		Vector^ Negate() {
			return ref new Vector(-x_, -y_, -z_);
		}
		Vector^ Add(Vector^ other)  {
			return ref new Vector(x_ + other->x_, y_ + other->y_, z_ + other->z_);
		}
		Vector^ Substract(Vector^ other)  {
			return ref new Vector(x_ - other->x_, y_ - other->y_, z_ - other->z_);
		}

		/** çÏÇËÇ©ÇØ... **/
	};

}