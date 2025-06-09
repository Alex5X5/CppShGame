#pragma once
#include <math.h>
#include <string.h>

#define typedef Vector3d {}


namespace shgame::logic::math
{
	struct Vector3d {
		public:
			double x;
			double y;
			double z;

			const int Size = 12;

			//static const Vector3d X = Vector3d(1, 0, 0);
			//static const Vector3d Y = new(0, 1, 0);
			//static const Vector3d Z = new(0, 0, 1);
			//static readonly Vector3d Zero = new(0, 0, 0);

			//static implicit operator Vector3f(Vector3d ? v) =>
			//	new(
			//		(float)System.Math.Floor(v != null ? v.Value.x : 0),
			//		(float)System.Math.Floor(v != null ? v.Value.y : 0),
			//		(float)System.Math.Floor(v != null ? v.Value.z : 0)
			//		);

			Vector3d(double _x, double _y, double _z)
			{
				x = _x;
				y = _y;
				z = _z;
			};

			Vector3d() : Vector3d(0, 0, 0){};

			//Vector3d(Vector3d vector);

			//Vector3d(double[] values) {
			//	set(values[0], values[1], values[2]);
			//}

			Vector3d* set(double x_, double y_, double z_)
			{
				x = x_;
				y = y_;
				z = z_;
				return this;
			}

			Vector3d* set(Vector3d vector)
			{
				return set(vector.x, vector.y, vector.z);
			}

			Vector3d* set(Vector3d* vector)
			{
				return set(vector->x, vector->y, vector->z);
			}

			Vector3d Cpy() const
			{
				return *this;
			}

			Vector3d* add(Vector3d vector)
			{
				return add(vector.x, vector.y, vector.z);
			}

			Vector3d* add(double _x, double _y, double _z)
			{
				return set(x + _x, y + _y, z + _z);
			}

			Vector3d* add(double values)
			{
				return set(x + values, y + values, z + values);
			}

			Vector3d* sub(Vector3d a_vec)
			{
				return Sub(a_vec.x, a_vec.y, a_vec.z);
			}

			Vector3d* sub(double _x, double _y, double _z) {
				return set(x - _x, y - _y, z - _z);
			}

			Vector3d* Sub(double value)
			{
				return set(x - value, y - value, z - value);
			}

			Vector3d* scl(double scalar)
			{
				return set(x * scalar, y * scalar, z * scalar);
			}

			Vector3d* scl(Vector3d a_vec)
			{
				return set(x * a_vec.x, y * a_vec.y, z * a_vec.z);
			}

			Vector3d* scl(double vx, double vy, double vz)
			{
				return set(x * vx, y * vy, z * vz);
			}

			Vector3d* mulAdd(Vector3d vec, double scalar)
			{
				x += vec.x * scalar;
				y += vec.y * scalar;
				z += vec.z * scalar;
				return this;
			}

			Vector3d* mulAdd(Vector3d vec, Vector3d mulVec)
			{
				x += vec.x * mulVec.x;
				y += vec.y * mulVec.y;
				z += vec.z * mulVec.z;
				return this;
			}

			static double len(double x, double y, double z)
			{
				return sqrt(x * x + y * y + z * z);
			}

			double len() const
			{
				return sqrt(x * x + y * y + z * z);
			}

			static double len2(double x, double y, double z)
			{
				return x * x + y * y + z * z;
			}

			double len2() const
			{
				return x * x + y * y + z * z;
			}

			bool idt(Vector3d vector) const
			{
				return x == vector.x && y == vector.y && z == vector.z;
			}

			static double dst(double x1, double y1, double z1, double x2, double y2, double z2)
			{
				double a = x2 - x1;
				double b = y2 - y1;
				double c = z2 - z1;
				return (double)sqrt(a * a + b * b + c * c);
			}

			double dst(Vector3d vector) const
			{
				double a = vector.x - x;
				double b = vector.y - y;
				double c = vector.z - z;
				return (double)sqrt(a * a + b * b + c * c);
			}

			double dst(double _x, double _y, double _z)
			{
				double a = _x - x;
				double b = _y - y;
				double c = _z - z;
				return (double)sqrt(a * a + b * b + c * c);
			}

			static double dst2(double x1, double y1, double z1, double x2, double y2, double z2)
			{
				double a = x2 - x1;
				double b = y2 - y1;
				double c = z2 - z1;
				return a * a + b * b + c * c;
			}

			double dst2(Vector3d* point) const
			{
				double a = point->x - x;
				double b = point->y - y;
				double c = point->z - z;
				return a * a + b * b + c * c;
			}

			double dst2(double _x, double _y, double _z)
			{
				double a = _x - x;
				double b = _y - y;
				double c = _z - z;
				return a * a + b * b + c * c;
			}

			Vector3d* Nor()
			{
				double l = len2();
				if (l == 0 || l == 1)
					return this;
				return scl(1 / (double)sqrt(l));
			}

			static double Dot(double x1, double y1, double z1, double x2, double y2, double z2)
			{
				return x1 * x2 + y1 * y2 + z1 * z2;
			}

			double Dot(Vector3d* vector)
			{
				return x * vector->x + y * vector->y + z * vector->z;
			}

			double Dot(double _x, double _y, double _z)
			{
				return x * _x + y * _y + z * _z;
			}

			Vector3d* Crs(Vector3d* vector)
			{
				return set(y * vector->z - z * vector->y, z * vector->x - x * vector->z, x * vector->y - y * vector->x);
			}

			Vector3d* Crs(double _x, double _y, double _z)
			{
				return set(y * _z - z * _y, z * _x - x * _z, x * _y - y * _x);
			}

			const char* toString()
			{
				return "(" + (char)x + '|' + (char)y + '|' + (char)z + ')';
			}

			Vector3d* limit(double limit) {
				return limit2(limit * limit);
			}

			Vector3d* limit2(double limit)
			{
				double len = len2();
				if (len > limit) {
					scl(sqrt(limit / len));
				}
				return this;
			}

			Vector3d* setLength(double len)
			{
				return setLength2(len * len);
			}

			Vector3d* setLength2(double l)
			{
				double oldLen2 = len2();
				return oldLen2 == 0 || oldLen2 == l ? this : scl((double)sqrt(l / oldLen2));
			}

			Vector3d* setZero()
			{
				x = 0;
				y = 0;
				z = 0;
				return this;
			}
		};
}