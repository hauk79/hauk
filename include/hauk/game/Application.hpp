//
// Created by hauk on 2023-11-30.
//

#ifndef HAUK_GAME_APPLICATION_H
#define HAUK_GAME_APPLICATION_H

#include <hauk/game/state/StateStack.hpp>
#include <hauk/game/resource/ResourceIdentifiers.hpp>

namespace hauk::game
{
	class Application
	{
		static const sf::Time TimePerFrame;
	public:
		explicit Application(Player* player);
		void run();

	private:
		void processInput();
		void update(sf::Time dt);
		void render();

		void updateStatistics(sf::Time dt);

		sf::RenderWindow m_window;
		resource::FontHolder m_fonts;

		sf::Text m_staticsText;

	protected:
		resource::TextureHolder m_textures;

		state::StateStack m_stateStack;
	};
} // hauk::game

#endif //HAUK_GAME_APPLICATION_H
