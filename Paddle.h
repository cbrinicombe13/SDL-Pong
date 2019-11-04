#ifndef PADDLE_H_
#define PADDLE_H_

#include "Ball.h"

namespace Pong {

class Paddle {
public:
	const static int PADDLE_WIDTH = 15;
	const static int PADDLE_HEIGHT = 90;
	const static int SCREEN_TO_PADDLE = 10; // Gap between screen and paddles
	const static int PADDLE_SPEED = 20;
	int m_xpos; // x position of paddle
	int m_ypos; // y position of paddle
	int m_id;
public:
	Paddle(int xpos, int ypos, int id): m_xpos(xpos), m_ypos(ypos), m_id(id) {};
};

} /* namespace Pong */

#endif /* PADDLE_H_ */
