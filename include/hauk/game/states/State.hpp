//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_STATE_HPP
#define HAUK_STATE_HPP


#include <hauk/game/resources/ResourceIdentifiers.hpp>

namespace hauk::game
{
	class Player;
}
namespace hauk::game::states
{
	class StateStack;
	class State
	{
	public:
		typedef std::unique_ptr<State> Ptr;

		struct Context
		{
			Context(sf::RenderWindow& window,
					resources::TextureHolder& textures, resources::FontHolder& fonts,
					Player& player);

			sf::RenderWindow* window;
			resources::TextureHolder* textures;
			resources::FontHolder * fonts;
			Player* player;
		};

		State(StateStack& stack, Context context);
		virtual ~State() = default;

		virtual void draw() = 0;
		virtual bool update(sf::Time dt) = 0;
		virtual bool handleEvent(const sf::Event& event) = 0;

	private:
		StateStack* m_stack;
		Context m_context;
	};

} // hauk::game::states

#endif //HAUK_STATE_HPP
