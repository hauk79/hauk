//
// Created by hauk on 2023-12-22.
//

#include "hauk/game/input/CommandQueue.hpp"



namespace hauk::game::input
{
	void CommandQueue::push(const Command& command)
	{
		m_queue.push(command);
	}

	Command CommandQueue::pop()
	{
		Command command = m_queue.front();
		m_queue.pop();
		return command;
	}

	bool CommandQueue::isEmpty() const
	{
		return m_queue.empty();
	}
} // hauk::game::input
