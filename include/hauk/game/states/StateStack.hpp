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
		enum Action
		{
			Push,
			Pop,
			Clear,
		};

		explicit StateStack(State::Context context);

		template <typename T>
		void registerStack(States::ID stateID);

		void update(sf::Time dt);

		void pushState(States::ID stateID);

		[[nodiscard]] bool isEmpty() const;

	private:
		struct PendingChange
		{
			explicit PendingChange(Action action, States::ID stateID = States::None);

			Action action;
			States::ID stateID;
		};
		std::vector<State::Ptr> m_stack;
		std::vector<PendingChange> m_pendingList;

		State::Context m_context;
		std::map<States::ID, std::function<State::Ptr()>> m_factories;
	};

	template<typename T>
	void StateStack::registerStack(States::ID stateID)
	{
		m_factories[stateID] = [this]()
		{
			return State::Ptr(new T(*this, m_context));
		};
	}
} // hauk::game::states

#endif //HAUK_STATESTACK_HPP
