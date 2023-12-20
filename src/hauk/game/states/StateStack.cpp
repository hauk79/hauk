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
		// Iterate from top to bottom, stop as soon as update() returns false
		for (auto itr{m_stack.rbegin()}; itr != m_stack.rend(); ++itr)
		{
			if (!(*itr)->update(dt))
				break;
		}

		applyPendingChange();
	}

	void StateStack::draw()
	{
		// Draw all active states from bottom to top
		for (auto& state : m_stack)
		{
			state->draw();
		}
	}

	void StateStack::handleEvent(const sf::Event& event)
	{
		// Iterate from top to bottom, stop as soon as handleEvent() returns false
		for (auto itr = m_stack.rbegin(); itr != m_stack.rend(); ++itr)
		{
			if (!(*itr)->handleEvent(event))
				break;
		}

		applyPendingChange();
	}

	void StateStack::pushState(States::ID stateID)
	{
		m_pendingList.emplace_back(Push, stateID);
	}

	bool StateStack::isEmpty() const
	{
		return m_stack.empty();
	}

	void StateStack::applyPendingChange()
	{

	}

	StateStack::PendingChange::PendingChange(StateStack::Action action, States::ID stateID)
	: action(action)
	, stateID(stateID)
	{

	}
} // hauk::game::states
