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
} // hauk::game::states
