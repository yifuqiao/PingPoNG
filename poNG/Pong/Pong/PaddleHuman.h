#ifndef __PADDLE_HUMAN_H__
#define __PADDLE_HUMAN_H__

#include "PaddleBase.h"
class PaddleHuman : public PaddleBase
{
public:
	PaddleHuman(const Vec2& pos, float width, float height,float speed)
		: PaddleBase(pos,width,height,speed)
	{
		
	}
	void Update(float dt);
private:
};
#endif