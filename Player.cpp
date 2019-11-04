#include <iostream>

#include "Player.h"

namespace Pong {

Player::Player():
		m_score(0), m_name("") {

	std::string name;

	std::cout << "Enter player name > " << std::flush;

	std::cin >> name;

	m_name = name;

}

} /* namespace Pong */
