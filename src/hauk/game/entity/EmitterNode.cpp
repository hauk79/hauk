//
// Created by hauk on 2024-02-15.
//

#include "hauk/game/entity/EmitterNode.hpp"
#include "hauk/game/entity/ParticleNode.hpp"



namespace hauk::game::entity
{
	EmitterNode::EmitterNode(Particle::Type type)
	: SceneNode()
	, m_accumulatedTime(sf::Time::Zero)
	, m_type{type}
	, m_particleSystem{}
	{

	}

	void EmitterNode::updateCurrent(sf::Time dt, input::CommandQueue& commands)
	{
		if (m_particleSystem)
		{
			emitParticles(dt);
		}
		else
		{
			// Find particle node with the same type as emitter node
			auto finder = [this] (ParticleNode& container, sf::Time)
			{
				if (container.getParticleType() == m_type)
					m_particleSystem = &container;
			};

			input::Command command;
			command.category = Category::ParticleSystem;
			command.action = input::derivedAction<ParticleNode>(finder);

			commands.push(command);
		}
	}

	void EmitterNode::emitParticles(sf::Time dt)
	{
		const float emissionRate{30.f};
		const sf::Time interval{sf::seconds(1.f)/emissionRate};

		m_accumulatedTime += dt;

		while (m_accumulatedTime > interval)
		{
			m_accumulatedTime -= interval;
			m_particleSystem->addParticle(getWorldPosition());
		}
	}
} // hauk::game::entity
