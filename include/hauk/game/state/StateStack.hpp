//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_GAME_STATE_STATESTACK_HPP
#define HAUK_GAME_STATE_STATESTACK_HPP


#include "State.hpp"
#include "StateIdentifiers.hpp"

namespace hauk::game::state
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
		void registerState(State::ID stateID);

		void update(sf::Time dt);
		void draw();
		void handleEvent(const sf::Event& event);

		void pushState(State::ID stateID);
		void popState();
		void clearStates();

		[[nodiscard]] bool isEmpty() const;

	private:
		State::Ptr createState(State::ID stateID);
		void applyPendingChange();

		struct PendingChange
		{
			explicit PendingChange(Action action, State::ID stateID = States::None);

			Action action;
			State::ID stateID;
		};
		std::vector<State::Ptr> m_stack;
		std::vector<PendingChange> m_pendingList;

		State::Context m_context;
		std::map<State::ID, std::function<State::Ptr()>> m_factories;
	};
} // hauk::game::state

#include "StateStack.inl"
#endif //HAUK_GAME_STATE_STATESTACK_HPP
