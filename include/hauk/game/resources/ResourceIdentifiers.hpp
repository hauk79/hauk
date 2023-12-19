//
// Created by hauk on 2023-12-19.
//

#ifndef HAUK_RESOURCEIDENTIFIERS_HPP
#define HAUK_RESOURCEIDENTIFIERS_HPP

#include <SFML/Graphics/Texture.hpp>
#include "ResourceHolder.hpp"

namespace hauk::game::resources
{
	namespace Textures
	{
		enum ID
		{
			Eagle,
			Raptor,
			Desert,
			TitleScreen,
		};

	}

	typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
}

#endif //HAUK_RESOURCEIDENTIFIERS_HPP
