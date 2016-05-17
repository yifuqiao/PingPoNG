#ifndef __PADDLE_BASE_H__
#define __PADDLE_BASE_H__

#include "GameObject.h"

class PaddleBase : public GameObject
{
public:
	PaddleBase(const Vec2& pos, float width, float height,float speed)
		: GameObject(pos,speed), m_width(width), m_height(height)
	{
		m_fitness = 0;
		m_origX = pos.x;
		m_origY = pos.y;
	}
	void SetDimensions(float width, float height);

	void MoveUp();
	void MoveDown();

	void Update(float dt);
	void Render();

	void IncFitness() { ++m_fitness; }
	void DecFitness() { --m_fitness; }
	int  GetFitness() { return m_fitness; }

	virtual void Reset();
protected:
	float m_origX, m_origY;
	float m_width, m_height;
	int m_fitness;
};

#endif