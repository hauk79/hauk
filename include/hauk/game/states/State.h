//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_STATE_H
#define HAUK_STATE_H



namespace hauk::game::states
{

	class State
	{
	public:
		struct Context
		{
			explicit Context(sf::RenderWindow& window);

			sf::RenderWindow* window;
		};
	};

} // hauk::game::states

#endif //HAUK_STATE_H
