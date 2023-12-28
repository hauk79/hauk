//
// Created by hauk on 2023-12-20.
//

#ifndef HAUK_GAME_UTIL_HPP
#define HAUK_GAME_UTIL_HPP

namespace hauk::game::util
{
	template <typename T>
	void centerOrigin(T& target);

	// Convert enumerators to strings
	std::string toString(sf::Keyboard::Key key);
}

#include "util.inl"
#endif //HAUK_GAME_UTIL_HPP
