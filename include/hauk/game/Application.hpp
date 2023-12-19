//
// Created by hauk on 2023-11-30.
//

#ifndef HAUK_GAME_APPLICATION_H
#define HAUK_GAME_APPLICATION_H

#include <hauk/game/states/StateStack.hpp>
#include <hauk/game/resources/ResourceIdentifiers.hpp>
#include "Player.hpp"

namespace hauk::game
{
	class Application
	{
		static const sf::Time TimePerFrame;
	public:
		Application();
		void run();

	private:
		void processInput();
		void update(sf::Time dt);
		void render();

		void updateStatistics(sf::Time dt);
		void registerStates();

		sf::RenderWindow m_window;
		resources::TextureHolder m_textures;
		resources::FontHolder m_fonts;
		Player m_player;

		states::StateStack m_stateStack;

		sf::Text m_staticsText;
	};
} // hauk::game

#endif //HAUK_GAME_APPLICATION_H
