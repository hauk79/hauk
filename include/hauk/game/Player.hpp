//
// Created by hauk on 2023-12-19.
//

#ifndef HAUK_GAME_PLAYER_HPP
#define HAUK_GAME_PLAYER_HPP


#include <SFML/Window/Event.hpp>

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

		virtual void assignKey(Action action, sf::Keyboard::Key key) = 0;
		[[nodiscard]] virtual sf::Keyboard::Key getAssignedKey(Action action) const = 0;

		virtual void setMissionStatus(MissionStatus status);
		[[nodiscard]] virtual MissionStatus getMissionStatus();

	private:
		MissionStatus m_currentMissionStatus;
	};

} // hauk::game

#endif //HAUK_GAME_PLAYER_HPP
