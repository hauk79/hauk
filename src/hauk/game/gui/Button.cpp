//
// Created by hauk on 2023-12-23.
//

#include <hauk/game/util/util.hpp>
#include "hauk/game/gui/Button.hpp"



namespace hauk::game::gui
{
	Button::Button(const resource::FontHolder& fonts, const resource::TextureHolder& textures)
	: m_callback()
	, m_normalTexture(textures.get(resource::Textures::ButtonNormal))
	, m_selectedTexture(textures.get(resource::Textures::ButtonSelected))
	, m_pressedTexture(textures.get(resource::Textures::ButtonPressed))
	, m_sprite()
	, m_text("", fonts.get(resource::Fonts::Main), 16)
	, m_isToggle(false)
	{
		m_sprite.setTexture(m_normalTexture);

		sf::FloatRect bounds = m_sprite.getLocalBounds();
		m_text.setPosition(bounds.width / 2.f, bounds.height / 2.f);
	}

	void Button::setCallback(Button::Callback callback)
	{
		m_callback = std::move(callback);
	}

	void Button::setText(const std::string& text)
	{
		m_text.setString(text);
		util::centerOrigin(m_text);
	}

	void Button::setToggle(bool flag)
	{
		m_isToggle = flag;
	}

	bool Button::isSelectable() const
	{
		return true;
	}

	void Button::select()
	{
		Component::select();
		m_sprite.setTexture(m_selectedTexture);
	}

	void Button::deselect()
	{
		Component::deselect();
		m_sprite.setTexture(m_normalTexture);
	}

	void Button::handleEvent(const sf::Event& event)
	{
	}

	void Button::activate()
	{
		Component::activate();

		// If we are toggle then we should show that the button is pressed and thus "toggled".
		if (m_isToggle)
			m_sprite.setTexture(m_pressedTexture);

		if (m_callback)
			m_callback();

		// If we are not a toggle then deactivate the button since we are just momentarily activated.
		if (!m_isToggle)
			deactivate();
	}

	void Button::deactivate()
	{
		Component::deactivate();

		if (m_isToggle)
		{
			// Reset texture to right one depending on if we are selected or not.
			if (isSelected())
				m_sprite.setTexture(m_selectedTexture);
			else
				m_sprite.setTexture(m_normalTexture);
		}
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(m_sprite, states);
		target.draw(m_text, states);
	}
} // hauk::game::gui
