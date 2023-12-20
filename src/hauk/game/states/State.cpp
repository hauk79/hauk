//
// Created by hauk on 2023-12-18.
//

#include "hauk/game/states/State.hpp"
#include "hauk/game/states/StateStack.hpp"


namespace hauk::game::states
{
	State::Context::Context(sf::RenderWindow& window, resources::TextureHolder& textures, resources::FontHolder& fonts,
			Player& player)
			: window(&window)
			, textures(&textures)
			, fonts(&fonts)
			, player(&player)
	{
	}

	State::State(StateStack& stack, State::Context context)
	: m_stack(&stack)
	, m_context(context)
	{

	}

	void State::requestStackPush(States::ID stateID)
	{
		m_stack->pushState(stateID);
	}

	void State::requestStackPop()
	{
		m_stack->popState();
	}

	void State::requestStateClear()
	{
		m_stack->clearStates();
	}
} // hauk::game::states
