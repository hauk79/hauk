//
// Created by hauk on 2023-12-29.
//

#include <hauk/game/util/util.hpp>
#include "hauk/game/entity/TextNode.hpp"



namespace hauk::game::entity
{
	TextNode::TextNode(const resource::FontHolder& fonts, const std::string& text)
	{
		m_text.setFont(fonts.get(resource::Fonts::Main));
		m_text.setCharacterSize(20);
		setString(text);
	}

	void TextNode::setString(const std::string& text)
	{
		m_text.setString(text);
		util::centerOrigin(m_text);
	}

	void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_text, states);
	}
} // hauk::game::entity
