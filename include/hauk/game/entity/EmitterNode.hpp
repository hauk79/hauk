//
// Created by hauk on 2024-02-15.
//

#ifndef HAUK_GAME_ENTITY_EMITTERNODE_HPP
#define HAUK_GAME_ENTITY_EMITTERNODE_HPP


#include "SceneNode.hpp"
#include "Particle.hpp"

namespace hauk::game::entity
{

	class EmitterNode : public SceneNode
	{
	public:
		explicit EmitterNode(Particle::Type type);

	private:
		void updateCurrent(sf::Time dt, input::CommandQueue& commands) override;

		void emitParticles(sf::Time dt);

		sf::Time m_accumulatedTime;
		Particle::Type m_type;
		class ParticleNode* m_particleSystem;
	};

} // entity

#endif //HAUK_GAME_ENTITY_EMITTERNODE_HPP
