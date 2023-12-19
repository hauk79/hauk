//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_STATESTACK_HPP
#define HAUK_STATESTACK_HPP


#include "State.hpp"
#include "StateIdentifiers.hpp"

namespace hauk::game::states
{
	class StateStack : private sf::NonCopyable
	{
	public:
		explicit StateStack(State::Context context);

		template <typename T>
		void registerStack(States::ID stateID);

		void update(sf::Time dt);

		[[nodiscard]] bool isEmpty() const
		{
			return m_stack.empty();
		}

	private:
		std::vector<State::Ptr> m_stack;
	};

} // hauk::game::states

#endif //HAUK_STATESTACK_HPP
