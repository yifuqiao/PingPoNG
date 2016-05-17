#include "GameManager.h"
#include "Types.h"
#include "GraphicsTools.h"
#include "PaddleBase.h"

#define SCREEN_EDGE_X 40
#define MAX_FITNESS 10

#include "PaddleAI.h"

void GameManager::SetPlayers(PaddleBase* ai,PaddleBase* human,Ball* ball)
{
	m_pHumanPaddle = human;
	m_pBall = ball;
	m_pAiPaddle = ai;
	static_cast<PaddleAI*>(m_pAiPaddle)->SetBall(m_pBall);
}

void GameManager::PlayerScore()
{
	m_pHumanPaddle->IncFitness();
	if(m_pHumanPaddle->GetFitness() >= MAX_FITNESS)
		ResetGame();
}

void GameManager::AIScore()
{
	m_pAiPaddle->IncFitness();
	if(m_pAiPaddle->GetFitness() >= MAX_FITNESS)
		ResetGame();
}
void GameManager::ResetGame()
{
	bool AIWin = false;
	if(m_pAiPaddle->GetFitness() > m_pHumanPaddle->GetFitness())
		AIWin = true;
	((PaddleAI*)m_pAiPaddle)->SetWinLose(AIWin);

	m_pAiPaddle->Reset();
	m_pHumanPaddle->Reset();
}
void GameManager::Update(float dt)
{
	Vec2 pos = m_pBall->GetPosition();
	if(GraphicsTools::CollideBallPaddle(m_pBall,m_pAiPaddle) || 
	   GraphicsTools::CollideBallPaddle(m_pBall,m_pHumanPaddle))
	{
		m_pBall->Bounce();
		return;
	}

	if(pos.x > SCREEN_EDGE_X) 
	{
		PlayerScore();
		m_pBall->SetPosition(Vec2(0,0));
		m_pBall->Bounce();
		Sleep(100);
	}

	else if(pos.x < -SCREEN_EDGE_X)
	{
		AIScore();
		m_pBall->SetPosition(Vec2(0,0));
		m_pBall->Bounce();
		Sleep(100);
	}
}

GameManager* GameManager::Get()
{
	static GameManager singleton;
	return &singleton;
}

