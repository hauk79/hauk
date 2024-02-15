//
// Created by hauk on 2024-02-15.
//

#ifndef HAUK_GAME_DATA_PARTICLEDATA_HPP
#define HAUK_GAME_DATA_PARTICLEDATA_HPP



namespace hauk::game::data
{

	struct ParticleData
	{
		sf::Color color;
		sf::Time lifetime;
	};

	std::vector<ParticleData> initializePaticleData();
} // hauk::game::data

#endif //HAUK_GAME_DATA_PARTICLEDATA_HPP
