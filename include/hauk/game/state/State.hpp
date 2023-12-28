//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_GAME_STATE_STATE_HPP
#define HAUK_GAME_STATE_STATE_HPP


#include <hauk/game/resource/ResourceIdentifiers.hpp>
#include "StateIdentifiers.hpp"

namespace hauk::game
{
	class Player;
}
namespace hauk::game::state
{
	class StateStack;
	class State
	{
	public:
		typedef std::unique_ptr<State> Ptr;

		struct Context
		{
			Context(sf::RenderWindow& window,
					resource::TextureHolder& textures, resource::FontHolder& fonts,
					Player* player);

			sf::RenderWindow* window;
			resource::TextureHolder* textures;
			resource::FontHolder * fonts;
			Player* player;
		};

		State(StateStack& stack, Context context);
		virtual ~State() = default;

		virtual void draw() = 0;
		virtual bool update(sf::Time dt) = 0;
		virtual bool handleEvent(const sf::Event& event) = 0;
	protected:
		void requestStackPush(States::ID stateID);
		void requestStackPop();
		void requestStateClear();

		[[nodiscard]] Context getContext() const
		{
			return m_context;
		}
	private:
		StateStack* m_stack;
		Context m_context;
	};

} // hauk::game::state

#endif //HAUK_GAME_STATE_STATE_HPP
