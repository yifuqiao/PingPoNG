#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

class PaddleBase;
class Ball;

class GameManager
{
public:
	static GameManager* Get();

	void SetPlayers(PaddleBase* ai,PaddleBase* human,Ball* ball);

	void Update(float dt);
	void ResetGame();
private:
	void PlayerScore();
	void AIScore();

	Ball* m_pBall;
	PaddleBase* m_pAiPaddle;
	PaddleBase* m_pHumanPaddle;
};

#endif