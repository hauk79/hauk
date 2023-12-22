//
// Created by hauk on 2023-12-22.
//

#ifndef HAUK_GAME_INPUT_COMMANDQUEUE_HPP
#define HAUK_GAME_INPUT_COMMANDQUEUE_HPP


#include "Command.hpp"

namespace hauk::game::input
{

	class CommandQueue
	{
	public:
		void push(const Command& command);
		Command pop();
		[[nodiscard]] bool isEmpty() const;
	private:
		std::queue<Command> m_queue;
	};

} // hauk::game::input

#endif //HAUK_GAME_INPUT_COMMANDQUEUE_HPP
