//
// Created by hauk on 2024-02-15.
//

#ifndef HAUK_GAME_ENTITY_PARTICLE_HPP
#define HAUK_GAME_ENTITY_PARTICLE_HPP

namespace hauk::game::entity
{
	struct Particle
	{
		enum Type
		{
			Propellant,
			Smoke,
			ParticleCount,
		};

		sf::Vector2f position;
		sf::Color color;
		sf::Time lifetime;
	};
}

#endif //HAUK_GAME_ENTITY_PARTICLE_HPP
