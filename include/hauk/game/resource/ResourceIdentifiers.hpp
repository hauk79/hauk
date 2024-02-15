//
// Created by hauk on 2023-12-19.
//

#ifndef HAUK_GAME_RESOURCE_RESOURCEIDENTIFIERS_HPP
#define HAUK_GAME_RESOURCE_RESOURCEIDENTIFIERS_HPP

#include "ResourceHolder.hpp"

namespace hauk::game::resource
{
	namespace Textures
	{
		enum ID
		{
			Buttons = 100000,
			Particle,
		};

	}

	namespace Fonts
	{
		enum ID
		{
			Main = 100000,
		};
	}

	typedef ResourceHolder<sf::Texture, size_t> TextureHolder;
	typedef ResourceHolder<sf::Font, size_t> FontHolder;
}

#endif //HAUK_GAME_RESOURCE_RESOURCEIDENTIFIERS_HPP
