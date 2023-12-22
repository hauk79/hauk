//
// Created by hauk on 2023-12-21.
//

#ifndef HAUK_GAME_ENTITY_ENTITY_HPP
#define HAUK_GAME_ENTITY_ENTITY_HPP


#include "SceneNode.hpp"

namespace hauk::game::entity
{

	class Entity : public SceneNode
	{
	public:
		void setVelocity(sf::Vector2f  velocity);
		void setVelocity(float vx, float vy);
		void accelerate(sf::Vector2f  velocity);
		void accelerate(float vx, float vy);
		[[nodiscard]] sf::Vector2f getVelocity() const;

	private:
		void updateCurrent(sf::Time dt) override;

	private:
		sf::Vector2f m_velocity;
	};

} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_ENTITY_HPP
