//
// Created by hauk on 2023-12-19.
//

#ifndef HAUK_GAME_PLAYER_HPP
#define HAUK_GAME_PLAYER_HPP

#include <hauk/game/input/Command.hpp>

namespace hauk::game::input
{
	class CommandQueue;
}
namespace hauk::game
{

	class Player
	{
	public:
		typedef std::size_t Action;
		typedef std::size_t MissionStatus;

		Player();

		virtual void handleEvent(const sf::Event& event, input::CommandQueue& commands) = 0;
		virtual void handleRealtimeInput(input::CommandQueue& commands) = 0;

		virtual void assignKey(Action action, sf::Keyboard::Key key);
		[[nodiscard]] virtual sf::Keyboard::Key getAssignedKey(Action action) const;

		virtual void setMissionStatus(MissionStatus status);
		[[nodiscard]] virtual MissionStatus getMissionStatus();

	protected:
		std::map<sf::Keyboard::Key, Action> m_keyBinding;
		std::map<Action, input::Command> m_actionBinding;

	private:
		MissionStatus m_currentMissionStatus;
	};

} // hauk::game

#endif //HAUK_GAME_PLAYER_HPP
