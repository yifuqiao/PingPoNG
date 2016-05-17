#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "Types.h"

class GameObject
{
public:
	GameObject(const Vec2& pos,float speed)
		: m_position(pos), m_speed(speed)
	{
		
	}
	void SetPosition(const Vec2& pos) { m_position = pos; }
	void SetSpeed(float speed) { m_speed = speed; }

	Vec2& GetPosition() { return m_position; }
	const float GetSpeed() { return m_speed; }

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

protected:	
	Vec2 m_position;
	float m_speed;
};	

#endif