//
// Created by hauk on 2023-12-22.
//

#ifndef HAUK_GAME_INPUT_COMMAND_HPP
#define HAUK_GAME_INPUT_COMMAND_HPP


namespace hauk::game::entity
{
	class SceneNode;
}

namespace hauk::game::input
{

	struct Command
	{
		Command();

		std::function<void(entity::SceneNode&, sf::Time)> action;
		unsigned int category;
	};

} // hauk::game::input

#include "Command.inl"
#endif //HAUK_GAME_INPUT_COMMAND_HPP
