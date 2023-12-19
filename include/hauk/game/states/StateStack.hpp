//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_STATESTACK_HPP
#define HAUK_STATESTACK_HPP


#include "State.hpp"

namespace hauk::game::states
{
	class StateStack : private sf::NonCopyable
	{
	public:
		explicit StateStack(State::Context context);
	};

} // hauk::game::states

#endif //HAUK_STATESTACK_HPP
