#include "PaddleAI.h"
#include "Ball.h"

void PaddleAI::Update(float dt)
{
	if(m_position.y > m_pBall->GetPosition().y)
		m_position.y -= m_speed * dt;
	if(m_position.y < m_pBall->GetPosition().y)
		m_position.y += m_speed * dt;
}

void PaddleAI::Reset()
{
	if(!m_isVictorious || m_fitness > m_lastFitness)
		m_fitnessDir *= -1;
	m_lastFitness = m_fitness;
	m_speed += m_fitnessDir;
	PaddleBase::Reset();
}