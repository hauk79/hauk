//
// Created by hauk on 2024-02-15.
//

#include <hauk/game/entity/Particle.hpp>
#include "hauk/game/data/ParticleData.hpp"



namespace hauk::game::data
{
	std::vector<ParticleData> initializePaticleData()
	{
		using entity::Particle;
		std::vector<ParticleData> data{Particle::ParticleCount};

		data[Particle::Propellant].color = sf::Color{255, 255, 50};
		data[Particle::Propellant].lifetime = sf::seconds(.6f);

		data[Particle::Smoke].color = sf::Color{50, 50, 50};
		data[Particle::Smoke].lifetime = sf::seconds(4.f);

		return data;
	}
} // hauk::game::data
