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
		SceneAirLayer		= 1 << 0,
		PlayerAircraft 		= 1 << 1,
		AlliedAircraft 		= 1 << 2,
		EnemyAircraft 		= 1 << 3,
		Pickup				= 1 << 4,
		AlliedProjectile	= 1 << 5,
		EnemyProjectile		= 1 << 6,
	};
}

#endif //HAUK_GAME_ENTITY_CATEGORY_HPP
