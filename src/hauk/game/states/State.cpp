//
// Created by hauk on 2023-12-18.
//

#include "hauk/game/states/State.hpp"


namespace hauk::game::states
{
	State::Context::Context(sf::RenderWindow& window, resources::TextureHolder& textures, resources::FontHolder& fonts,
			Player& player)
			: window(&window)
			, textures(&textures)
			, fonts(&fonts)
			, player(&player)
	{
	}

	State::State(StateStack& stack, State::Context context)
	: m_stack(&stack)
	, m_context(context)
	{

	}
} // hauk::game::states
