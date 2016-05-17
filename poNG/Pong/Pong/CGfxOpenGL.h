#ifndef __GL_COMPONENT
#define __GL_COMPONENT

#define PI 3.14159
#define TWO_PI PI*2.0
#define HALF_PI PI/2.0

#include "Ball.h"
class PaddleBase;

enum PlayerType
{
	HUMAN,
	AI,

	TOTAL
};

class CGfxOpenGL
{
private:

	int m_windowWidth;
	int m_windowHeight;

	float mx,my;
	PaddleBase* m_paddles[2];
	Ball m_ball;
public:
	CGfxOpenGL();
	virtual ~CGfxOpenGL();

	bool Init();
	bool Shutdown();
	
	void SetupProjection(int width, int height);
	void SetMousePosition(float x, float y)
	{ 
		mx = x;
		my = y;
	}
	void Prepare(float dt);
	void Render();
};

#endif