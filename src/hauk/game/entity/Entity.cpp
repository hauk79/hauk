//
// Created by hauk on 2023-12-21.
//

#include "hauk/game/entity/Entity.hpp"



namespace hauk::game::entity
{
	Entity::Entity(int hitpoints) : m_hitpoints(hitpoints)
	{
	}

	void Entity::setVelocity(sf::Vector2f velocity)
	{
		m_velocity = velocity;
	}

	void Entity::setVelocity(float vx, float vy)
	{
		m_velocity.x = vx;
		m_velocity.y = vy;
	}

	void Entity::accelerate(sf::Vector2f velocity)
	{
		m_velocity += velocity;
	}

	void Entity::accelerate(float vx, float vy)
	{
		m_velocity.x += vx;
		m_velocity.y += vy;
	}

	sf::Vector2f Entity::getVelocity() const
	{
		return m_velocity;
	}

	int Entity::getHitpoints() const
	{
		return m_hitpoints;
	}

	void Entity::repair(int points)
	{
		assert(points > 0);

		m_hitpoints += points;
	}

	void Entity::damage(int points)
	{
		assert(points > 0);

		m_hitpoints -= points;
	}

	void Entity::destroy()
	{
		m_hitpoints = 0;
	}

	bool Entity::isDestroyed() const
	{
		return m_hitpoints <= 0;
	}

	void Entity::updateCurrent(sf::Time dt)
	{
		move(m_velocity * dt.asSeconds());
	}
} // hauk::game::entity
