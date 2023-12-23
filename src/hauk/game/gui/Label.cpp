//
// Created by hauk on 2023-12-23.
//

#include "hauk/game/gui/Label.hpp"



namespace hauk::game::gui
{
	Label::Label(const std::string& text, const resource::FontHolder& fonts)
	: m_text(text, fonts.get(resource::Fonts::Main), 16)
	{

	}

	bool Label::isSelectable() const
	{
		return false;
	}

	void Label::handleEvent(const sf::Event& event)
	{
	}

	void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(m_text, states);
	}

	void Label::setText(const std::string& text)
	{
		m_text.setString(text);
	}
} // hauk::game::gui
