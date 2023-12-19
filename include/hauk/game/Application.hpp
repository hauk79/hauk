//
// Created by hauk on 2023-11-30.
//

#ifndef HAUK_GAME_APPLICATION_H
#define HAUK_GAME_APPLICATION_H

#include <hauk/game/states/StateStack.hpp>
#include <hauk/game/resources/ResourceIdentifiers.hpp>

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

		sf::RenderWindow m_window;
		resources::TextureHolder m_textures;

		states::StateStack m_stateStack;
	};
} // hauk::game

#endif //HAUK_GAME_APPLICATION_H
