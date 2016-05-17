#ifndef __GRAPHICS_TOOLS_H__
#define __GRAPHICS_TOOLS_H__

#include "Ball.h"
#include "PaddleBase.h"
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

namespace GraphicsTools
{
	static bool CollideBallPaddle(Ball* ball, PaddleBase* paddle)
	{
		Vec2 dir = ball->GetPosition() - paddle->GetPosition();
		float len2 = dir.len();
		float rad = ball->GetRadius();
		if(len2 < rad + 5)
			return true;
		return false;
	}
	static void DrawCircle(float x,float z,float radius)
	{
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x,0,z);
		for(float angle = 0; angle < 360; angle += 5)
		{
			float _x = x + sinf(angle) * radius;
			float _z = z + cosf(angle) * radius;
			glVertex3f(_x,0,_z);
		}
		glEnd();
		glPopMatrix();
	}

	static void DrawQuad(float x,float z,float width,float height)
	{
		glBegin(GL_QUADS);
			glVertex3f(x - width,0,z - height);
			glVertex3f(x + width,0,z - height);
			glVertex3f(x + width,0,z + height);
			glVertex3f(x - width,0,z + height);
		glEnd();
	}
};

#endif