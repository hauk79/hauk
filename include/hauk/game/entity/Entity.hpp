//
// Created by hauk on 2023-12-21.
//

#ifndef HAUK_GAME_ENTITY_ENTITY_HPP
#define HAUK_GAME_ENTITY_ENTITY_HPP



namespace hauk::game::entity
{

	class Entity
	{
	public:
		void setVelocity(sf::Vector2f  velocity);
		void setVelocity(float vx, float vy);
		[[nodiscard]] sf::Vector2f getVelocity() const;
	private:
		sf::Vector2f m_velocity;
	};

} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_ENTITY_HPP
