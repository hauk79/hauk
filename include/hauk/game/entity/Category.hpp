//
// Created by hauk on 2023-12-22.
//

#ifndef HAUK_GAME_ENTITY_CATEGORY_HPP
#define HAUK_GAME_ENTITY_CATEGORY_HPP

namespace hauk::game::entity::Category
{
	enum Type
	{
		None 				= 0,
		ParticleSystem		= 1 << 16,
	};
}

#endif //HAUK_GAME_ENTITY_CATEGORY_HPP
