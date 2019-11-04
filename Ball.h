#ifndef BALL_H_
#define BALL_H_

namespace Pong {

class Ball {
public:
	const static int BALL_RADIUS = 10;
	const static int BALL_XSPEED = 3;
	const static int BALL_YSPEED = BALL_XSPEED; // Currently same speed in x and y.
	int m_xpos;
	int m_ypos;
	int m_xspeed;
	int m_yspeed;
public:
	Ball(int xpos, int ypos);
	void setRandomDirection();
	void move();
};

} /* namespace Pong */

#endif /* BALL_H_ */
