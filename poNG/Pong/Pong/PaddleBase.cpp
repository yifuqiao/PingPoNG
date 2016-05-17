#include "PaddleBase.h"
#include "GraphicsTools.h"

void PaddleBase::Update(float dt)
{

}

void PaddleBase::Render()
{
	GraphicsTools::DrawQuad(m_position.x,m_position.y,m_width,m_height);
}

void PaddleBase::SetDimensions( float width, float height )
{
	m_width = width;
	m_height = height;
}

void PaddleBase::Reset()
{
	m_fitness = 0;
	m_position.x = m_origX;
	m_position.y = m_origY;
}