//
// Created by hauk on 2024-02-13.
//

#ifndef HAUK_GAME_ENTITY_PARTICLENODE_HPP
#define HAUK_GAME_ENTITY_PARTICLENODE_HPP


#include <hauk/game/resource/ResourceIdentifiers.hpp>
#include "SceneNode.hpp"
#include "Particle.hpp"

namespace hauk::game::entity
{

	class ParticleNode : public SceneNode
	{
	public:
		ParticleNode(Particle::Type type, const resource::TextureHolder& textures);

		void addParticle(sf::Vector2f position);
		Particle::Type getParticleType() const;
		unsigned int getCategory() const override;

	private:
		void updateCurrent(sf::Time dt, input::CommandQueue& commands) override;
		void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

		void addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
		void computeVertices() const;

	private:
		std::deque<Particle> m_particles;
		const sf::Texture& m_texture;
		Particle::Type m_type;

		mutable sf::VertexArray m_vertexArray;
		mutable bool m_needsVertexUpdate;
	};

} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_PARTICLENODE_HPP
