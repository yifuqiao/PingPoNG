#include "Ball.h"
#include "GraphicsTools.h"

#define SCREEN_EDGE_Y 28
#define SHIFT_DIST 6

void Ball::Update(float dt)
{
	m_position.x += m_vel.x * m_speed * dt;
	m_position.y += m_vel.y * m_speed * dt;
	if(m_position.y > SCREEN_EDGE_Y || m_position.y < -SCREEN_EDGE_Y)
	{
		m_vel.y *= -1;
		m_position.y += m_vel.y * SHIFT_DIST;
	}
}

void Ball::Render()
{
	GraphicsTools::DrawCircle(m_position.x,m_position.y,m_radius);
}

float Ball::GetRadius() const
{
	return m_radius;
}

void Ball::Bounce()
{
	m_vel.x *= -1;
	m_position.x += m_vel.x * SHIFT_DIST;
}
