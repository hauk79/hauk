//
// Created by hauk on 2023-12-29.
//

#ifndef HAUK_GAME_ENTITY_TEXTNODE_HPP
#define HAUK_GAME_ENTITY_TEXTNODE_HPP


#include <hauk/game/resource/ResourceIdentifiers.hpp>
#include "SceneNode.hpp"

namespace hauk::game::entity
{

	class TextNode : public SceneNode
	{
	public:
		explicit TextNode(const resource::FontHolder& fonts, const std::string& text);

		void setString(const std::string& text);

	private:
		void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Text m_text;
	};

} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_TEXTNODE_HPP
