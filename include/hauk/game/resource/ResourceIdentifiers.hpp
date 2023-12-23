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
			Eagle,
			Raptor,
			Desert,
			TitleScreen,
			ButtonNormal,
			ButtonSelected,
			ButtonPressed,
		};

	}

	namespace Fonts
	{
		enum ID
		{
			Main,
		};
	}

	typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
	typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;
}

#endif //HAUK_GAME_RESOURCE_RESOURCEIDENTIFIERS_HPP
