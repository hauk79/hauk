//
// Created by hauk on 2023-12-18.
//

#include "hauk/game/states/StateStack.hpp"



namespace hauk::game::states
{
	StateStack::StateStack(State::Context context)
	: m_stack()
	, m_pendingList()
	, m_context(context)
	, m_factories()
	{

	}

	void StateStack::update(sf::Time dt)
	{

	}

	bool StateStack::isEmpty() const
	{
		return m_stack.empty();
	}

	void StateStack::pushState(States::ID stateID)
	{
		m_pendingList.emplace_back(Push, stateID);
	}

	StateStack::PendingChange::PendingChange(StateStack::Action action, States::ID stateID)
	: action(action)
	, stateID(stateID)
	{

	}
} // hauk::game::states
