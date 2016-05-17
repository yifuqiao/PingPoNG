#ifndef __PADDLE_AI_H__
#define __PADDLE_AI_H__

#include "PaddleBase.h"
class Ball;

class PaddleAI : public PaddleBase
{
public:
	PaddleAI(const Vec2& pos, float width, float height,float speed)
		: PaddleBase(pos,width,height,speed),m_isVictorious(false),
		  m_fitnessDir(1),m_lastFitness(0)
	{
	}

	void SetBall(Ball* pBall)
	{
		m_pBall = pBall;
	}

	void SetWinLose(bool winLose)
	{
		m_isVictorious = winLose;
	}
	
	void Update(float dt);
	void Reset();
private:
	Ball* m_pBall;
	bool m_isVictorious;
	int m_fitnessDir;
	int m_lastFitness;
};

#endif