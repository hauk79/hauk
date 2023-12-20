//
// Created by hauk on 2023-12-20.
//

#ifndef HAUK_GAME_UTIL_INL
#define HAUK_GAME_UTIL_INL

namespace hauk::game::util
{
	template<typename T>
	void centerOrigin(T& target)
	{
		auto bounds = target.getLocalBounds();
		target.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	}
}

#endif //HAUK_GAME_UTIL_INL
