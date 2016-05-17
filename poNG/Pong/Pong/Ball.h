#ifndef __BALL_H__
#define __BALL_H__

#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball()
		: GameObject(Vec2(0,0),30)
	{
		m_radius = 1;
		m_vel = Vec2(1,1);
	}
	void SetRadius(float rad) { m_radius = rad; }
	void Update(float dt);
	void Render();
	void Bounce();
	float GetRadius() const;
private:

	float m_radius;
	Vec2 m_vel;
};

#endif