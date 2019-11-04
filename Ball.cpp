#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Ball.h"

namespace Pong {

Ball::Ball(int xpos, int ypos) {

	m_xpos = xpos;
	m_ypos = ypos;

	setRandomDirection();

}

void Ball::setRandomDirection() {

	int randXInt = (rand()) % 2;
	int randYInt = (rand()) % 2;

	if (randXInt == 0) {
		m_xspeed = -BALL_XSPEED;
	}
	else if (randXInt == 1) {
		m_xspeed = BALL_XSPEED;
	}

	if (randYInt == 0) {
		m_yspeed = -BALL_YSPEED;
	}
	else if (randYInt == 1) {
		m_yspeed = BALL_YSPEED;
	}
}

void Ball::move() {

	// Change position:

	m_xpos += m_xspeed;
	m_ypos += m_yspeed;

	// Bounce at top/bottom edges:

	if ((m_ypos + BALL_RADIUS) >= Screen::SCREEN_HEIGHT || (m_ypos - BALL_RADIUS) <= 0) {

		m_yspeed = -m_yspeed;

	}

	// Reset if hits left/right edges:

	else if ((m_xpos + BALL_RADIUS) > Screen::SCREEN_WIDTH || (m_xpos - BALL_RADIUS) < 0) {

		m_xpos = Screen::SCREEN_WIDTH/2;
		m_ypos = Screen::SCREEN_HEIGHT/2;

		SDL_Delay(2000);

		setRandomDirection();

	}
}

} /* namespace Pong */
