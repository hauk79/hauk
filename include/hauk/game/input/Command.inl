//
// Created by hauk on 2023-12-22.
//

#ifndef HAUK_GAME_INPUT_COMMAND_INL
#define HAUK_GAME_INPUT_COMMAND_INL

namespace hauk::game::input
{
	template <typename GameObject, typename Function>
	std::function<void(entity::SceneNode&, sf::Time)> derivedAction(Function fn)
	{
		return [=] (entity::SceneNode& node, sf::Time dt)
		{
			// Check if cast is safe
			assert(dynamic_cast<GameObject*>(&node) != nullptr);

			// Downcast node and invoke function on it
			fn(static_cast<GameObject&>(node), dt);
		};

	}
}

#endif //HAUK_GAME_INPUT_COMMAND_INL
