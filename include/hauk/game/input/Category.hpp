//
// Created by hauk on 2023-12-22.
//

#ifndef HAUK_GAME_INPUT_CATEGORY_HPP
#define HAUK_GAME_INPUT_CATEGORY_HPP

namespace hauk::game::input::Category
{
	enum Type
	{
		None 			= 0,
		SceneAirLayer	= 1 << 0,
		PlayerAircraft 	= 1 << 1,
		AlliedAircraft 	= 1 << 2,
		EnemyAircraft 	= 1 << 3,
	};
}

#endif //HAUK_GAME_INPUT_CATEGORY_HPP
