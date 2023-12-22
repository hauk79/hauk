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
		virtual void handleEvent(const sf::Event& event, input::CommandQueue& commands) = 0;
		virtual void handleRealtimeInput(input::CommandQueue& commands) = 0;
	};

} // hauk::game

#endif //HAUK_GAME_PLAYER_HPP
