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
		explicit Entity(int hitpoints);

		void setVelocity(sf::Vector2f  velocity);
		void setVelocity(float vx, float vy);
		void accelerate(sf::Vector2f  velocity);
		void accelerate(float vx, float vy);
		[[nodiscard]] sf::Vector2f getVelocity() const;

		int getHitpoints() const;
		void repair(int points);
		void damage(int points);
		void destroy();
		virtual void remove();
		bool isDestroyed() const override;
	protected:
		void updateCurrent(sf::Time dt, input::CommandQueue& commands) override;

	private:
		sf::Vector2f m_velocity;
		int m_hitpoints;
	};

} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_ENTITY_HPP
