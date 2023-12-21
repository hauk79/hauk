//
// Created by hauk on 2023-12-21.
//

#ifndef HAUK_SPRITENODE_HPP
#define HAUK_SPRITENODE_HPP


#include "SceneNode.hpp"

namespace hauk::game::entity
{

	class SpriteNode : public SceneNode
	{
	public:
		explicit SpriteNode(const sf::Texture& texture);
		SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);

	private:
		void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Sprite m_sprite;
	};

} // hauk::game::entity

#endif //HAUK_SPRITENODE_HPP
