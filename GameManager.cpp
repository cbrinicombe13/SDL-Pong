#include "GameManager.h"

using namespace std;

namespace Pong {

GameManager::GameManager() {
	// TODO Auto-generated constructor stub

}

void GameManager::showPreLaunch() {

	SDL_Delay(1000);

	cout << "Controls :" << endl;
	cout << endl << "==================================================================" << endl;
	cout << endl << "Paddle up:   a                                      Paddle up:   k" << endl;
	cout << endl << "Paddle down: s                                      Paddle down: l" << endl;
	cout << endl << "Quit: q" << endl;
	cout << endl << "==================================================================" << endl;

	printf("\nStarting in ..\n\n%d\n", PRELAUNCH_TIME);

	for (int time = PRELAUNCH_TIME - 1; time > 0; time--) {
		SDL_Delay(1000);
		printf("%d\n", time);
	}

}

void GameManager::processCollisions(Ball &ball, Paddle &paddle1, Paddle &paddle2) {

	bool collisionPaddle1 = ((ball.m_xpos - Ball::BALL_RADIUS)
			<= (paddle1.m_xpos + Paddle::PADDLE_WIDTH / 2)
			&& ball.m_ypos >= (paddle1.m_ypos - Paddle::PADDLE_HEIGHT / 2)
			&& ball.m_ypos <= (paddle1.m_ypos + Paddle::PADDLE_HEIGHT / 2));

	bool collisionPaddle2 = ((ball.m_xpos + Ball::BALL_RADIUS)
			>= (paddle2.m_xpos - Paddle::PADDLE_WIDTH / 2)
			&& ball.m_ypos >= (paddle2.m_ypos - Paddle::PADDLE_HEIGHT / 2)
			&& ball.m_ypos <= (paddle2.m_ypos + Paddle::PADDLE_HEIGHT / 2));

	if (collisionPaddle1 || collisionPaddle2) {
		ball.m_xspeed = -ball.m_xspeed;
	}
}

void GameManager::updateScore(Ball &ball, Player &player1, Player &player2) {

	bool player1scored = (ball.m_xpos + Ball::BALL_RADIUS) >= Screen::SCREEN_WIDTH;
	bool player2scored = (ball.m_xpos - Ball::BALL_RADIUS) <= 0;

	if (player1scored || player2scored) {

		cout << "============" << endl;
		cout << "!! SCORED !!" << endl;
		cout << "============" << endl;

		if (player1scored) {
			player1.m_score++;
			cout << endl << player1.m_name << ": " << player1.m_score << "\t"
					<< player2.m_name << ": " << player2.m_score << endl;
		}

		else if (player2scored) {
			player2.m_score++;
			cout << endl << player1.m_name << ": " << player1.m_score << "\t"
					<< player2.m_name << ": " << player2.m_score << endl;
		}
	}
}

bool GameManager::processEvents(Player &player1, Player &player2, Paddle &paddle1, Paddle &paddle2) {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {

			case SDLK_q: // Quit
				cout << "==================" << endl;
				cout << "!! FINAL SCORES !!" << endl;
				cout << "==================" << endl;
				cout << endl << player1.m_name << ": " << player1.m_score
						<< "\t" << player2.m_name << ": " << player2.m_score
						<< endl;
				return false;
				break;
			case SDLK_a: // Paddle 1 move down
				if ((paddle1.m_ypos + Paddle::PADDLE_HEIGHT)
						<= Screen::SCREEN_HEIGHT) {
					paddle1.m_ypos += Paddle::PADDLE_SPEED;
				}
				break;
			case SDLK_s: // Paddle 1 move up
				if ((paddle1.m_ypos - Paddle::PADDLE_HEIGHT) >= 0) {
					paddle1.m_ypos -= Paddle::PADDLE_SPEED;
				}
				break;
			case SDLK_k: // Paddle 2 move down
				if ((paddle2.m_ypos + Paddle::PADDLE_HEIGHT)
						<= Screen::SCREEN_HEIGHT) {
					paddle2.m_ypos += Paddle::PADDLE_SPEED;
				}
				break;
			case SDLK_l: // Paddle 2 move up
				if ((paddle2.m_ypos - Paddle::PADDLE_HEIGHT) >= 0) {
					paddle2.m_ypos -= Paddle::PADDLE_SPEED;
				}
				break;

			} /* switch */
		} /* if */
	} /* while */
	return true;
}

} /* namespace Pong */
