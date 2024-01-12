//
// Created by hauk on 2023-12-20.
//

#ifndef HAUK_GAME_STATE_STATESTACK_INL
#define HAUK_GAME_STATE_STATESTACK_INL

namespace hauk::game::state
{
	template<typename T>
	void StateStack::registerState(State::ID stateID)
	{
		m_factories[stateID] = [this]()
		{
			return State::Ptr(new T(*this, m_context));
		};
	}
}

#endif //HAUK_GAME_STATE_STATESTACK_INL
