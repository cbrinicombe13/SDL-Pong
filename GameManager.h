#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <iostream>

#include "Screen.h"
#include "Paddle.h"
#include "Ball.h"
#include "Player.h"

namespace Pong {

class GameManager {
public:
	const static int PRELAUNCH_TIME = 10;
public:
	GameManager();
	void showPreLaunch();
	void processCollisions(Ball &ball, Paddle &paddle1, Paddle &paddle2);
	void updateScore(Ball &ball, Player &player1, Player &player2);
	bool processEvents(Player &player1, Player &player2, Paddle &paddle1, Paddle &paddle2);
};

} /* namespace Pong */

#endif /* GAMEMANAGER_H_ */
