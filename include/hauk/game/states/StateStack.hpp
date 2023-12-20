//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_GAME_STATES_STATESTACK_HPP
#define HAUK_GAME_STATES_STATESTACK_HPP


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
		void registerState(States::ID stateID);

		void update(sf::Time dt);
		void draw();
		void handleEvent(const sf::Event& event);

		void pushState(States::ID stateID);
		void popState();
		void clearStates();

		[[nodiscard]] bool isEmpty() const;

	private:
		State::Ptr createState(States::ID stateID);
		void applyPendingChange();

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
} // hauk::game::states

#include "StateStack.inl"
#endif //HAUK_GAME_STATES_STATESTACK_HPP
