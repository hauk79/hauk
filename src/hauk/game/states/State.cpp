//
// Created by hauk on 2023-12-18.
//

#include "hauk/game/states/State.hpp"



namespace hauk::game::states
{
	State::Context::Context(sf::RenderWindow& window)
	: window{&window}
	{

	}
} // hauk::game::states
