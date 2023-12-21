//
// Created by hauk on 2023-12-21.
//

#include "hauk/game/entity/SpriteNode.hpp"



namespace hauk::game::entity
{
	SpriteNode::SpriteNode(const sf::Texture& texture)
	: m_sprite(texture)
	{

	}

	SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect)
	: m_sprite(texture, textureRect)
	{

	}

	void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_sprite, states);
	}
} // hauk::game::entity
