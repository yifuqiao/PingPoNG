#ifndef __TYPES_H__
#define __TYPES_H__

#include <math.h>
struct Vec2
{
	Vec2(float x = 0,float y = 0)
		: x(x), y(y)
	{
	}
	float len() 
	{
		return sqrt(x*x + y*y);
	}
	Vec2 operator-(const Vec2& rhs)
	{
		Vec2 ret = rhs;
		ret.x -= this->x;
		ret.y -= this->y;
		return ret;
	}
	float x,y;
};

#endif