#ifndef quaternion_h
#define quaternion_h

#include <Arduino.h>
#include <vector.h>

class quaternion{
	public:
		double square(double a);						//квадрат
		quaternion();									
	    quaternion(double angle, vector v_val);
		quaternion(vector v_val);
		quaternion normalize();
		quaternion conj();
		quaternion inverse();
		double length();
		double pi=3.14159265359;
		double w;
		vector v;
		quaternion operator+(quaternion q);
		quaternion operator-(quaternion q);
		quaternion operator*(quaternion one);
		quaternion operator^(double b);
};
#endif