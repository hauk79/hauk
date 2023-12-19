//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_STATE_HPP
#define HAUK_STATE_HPP


#include <hauk/game/resources/ResourceIdentifiers.hpp>

namespace hauk::game::states
{

	class State
	{
	public:
		struct Context
		{
			Context(sf::RenderWindow& window, resources::TextureHolder& textures);

			sf::RenderWindow* window;
			resources::TextureHolder* textures;
		};
	};

} // hauk::game::states

#endif //HAUK_STATE_HPP
