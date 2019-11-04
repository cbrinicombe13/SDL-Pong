#include <iostream>
#include <math.h>

#include <SDL.h>

#include "GameManager.h"

using namespace std;
using namespace Pong;

// Currently running at ~ 25Hz, changing screen width or speed causes scoring collisions to not occur
// Uses ~ 30% of CPU power so fine.

/*
 * TODO:
 * 	- Win conditions
 * 	- Scale all sizes to the screen dimensions
 * 	- Inputs for difficulty, length of game etc.
 * 	- Pause function
 * 	- Look at inheritance! (maybe Paddle and Ball can extend Screen) or using arrays to pass around key object data
 * 	- Look at encapsulation and removing standard namespace dependency
 * 	- Game managers
 * 	- Fix bugs with weird paddle collisions
 */

int main() {

// Start GameManager:

	GameManager gm;

// Create screen:

	Screen screen;

// Create paddles, ball and players:

	Paddle paddle1(Paddle::SCREEN_TO_PADDLE, Screen::SCREEN_HEIGHT / 2, 1);
	Paddle paddle2(Screen::SCREEN_WIDTH - (Paddle::SCREEN_TO_PADDLE + Paddle::PADDLE_WIDTH), Screen::SCREEN_HEIGHT / 2, 2);

	Ball ball(Screen::SCREEN_WIDTH / 2, Screen::SCREEN_HEIGHT / 2);

	Player player1;
	Player player2;

// Initialise screen:

	if (!screen.init()) {
		cout << "Error initialising screen .." << endl;
	}

	gm.showPreLaunch();

	bool notQuit = true;

//////// END OF SETUP ////////

	while(notQuit) {

	// Increment the counter for the refresh rate tracker:

		screen.rRate++;

	// Clear the current screen to allow new render:

		screen.clear();

	// Draw mid-line and borders:

		for (int x = (Screen::SCREEN_WIDTH/2 - Screen::MIDLINE_WIDTH/2); x < (Screen::SCREEN_WIDTH/2 + Screen::MIDLINE_WIDTH/2); x++) {
			for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
				screen.setPixel(x, y, 255, 255, 255);
			}
		}

		int borderYPositions[2] = {0, Screen::SCREEN_HEIGHT - Screen::BORDER_WIDTH};

		for (int i = 0; i < sizeof(borderYPositions)/sizeof(int); i++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				for (int y = borderYPositions[i]; y < borderYPositions[i] + Screen::BORDER_WIDTH; y++) {
					screen.setPixel(x, y, 255, 255, 255);
				}
			}
		}

	// Re-draw paddles:

		for (int x = 0; x < Paddle::PADDLE_WIDTH; x++) {
			for (int y = -(Paddle::PADDLE_HEIGHT/2); y < Paddle::PADDLE_HEIGHT/2; y++) {
				screen.setPixel(paddle1.m_xpos + x, paddle1.m_ypos + y, 255, 192, 203); // Pink
			}
		}

		for (int x = 0; x < Paddle::PADDLE_WIDTH; x++) {
			for (int y = -(Paddle::PADDLE_HEIGHT/2); y < Paddle::PADDLE_HEIGHT/2; y++) {
				screen.setPixel(paddle2.m_xpos + x, paddle2.m_ypos + y, 135, 206, 235); // Light blue
			}
		}

	// Re-draw ball:

		for (int r = 0; r < Ball::BALL_RADIUS; r++) {
			for (int theta = 0; theta < 720; theta++) {

				int polarX = r * cos(theta);
				int polarY = r * sin(theta);

				screen.setPixel(ball.m_xpos + polarX, ball.m_ypos + polarY, 255, 165, 0);
			}
		}

	// Move ball:

		ball.move();

	// Process collisions:

		gm.processCollisions(ball, paddle1, paddle2);

	// Update score:

		gm.updateScore(ball, player1, player2);

	// Update screen:

		screen.update();

	// Process events:

		if(!gm.processEvents(player1, player2, paddle1, paddle2)) {
			notQuit = false;
		}

	} /* GAME LOOP */

	screen.close();

	return 0;
}
