//
// Created by hauk on 2023-12-22.
//

#include <hauk/game/input/Category.hpp>
#include "hauk/game/input/Command.hpp"



namespace hauk::game::input
{
	Command::Command()
	: action()
	, category(Category::None)
	{

	}
} // hauk::game::input
