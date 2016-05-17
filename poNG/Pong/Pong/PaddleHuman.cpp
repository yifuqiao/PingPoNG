#include "PaddleHuman.h"
#include "InputHandler.h"

void PaddleHuman::Update(float dt)
{
	if(InputHandler::Get()->IsPressed('W'))
	{
		m_position.y -= m_speed * dt; 
	}
	else if(InputHandler::Get()->IsPressed('S'))
	{
		m_position.y += m_speed * dt;
	}
}
