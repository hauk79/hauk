//
// Created by hauk on 2023-12-23.
//

#ifndef HAUK_GAME_GUI_BUTTON_HPP
#define HAUK_GAME_GUI_BUTTON_HPP


#include <hauk/game/resource/ResourceIdentifiers.hpp>
#include "Component.hpp"

namespace hauk::game::gui
{

	class Button : public Component
	{
	public:
		typedef std::shared_ptr<Button> Ptr;
		typedef std::function<void()> Callback;

		Button(const resource::FontHolder& fonts, const resource::TextureHolder& textures);

		void setCallback(Callback callback);
		void setText(const std::string& text);
		void setToggle(bool flag);

		bool isSelectable() const override;

		void select() override;

		void deselect() override;

		void activate() override;

		void deactivate() override;

		void handleEvent(const sf::Event& event) override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		Callback  m_callback;
		const sf::Texture& m_normalTexture;
		const sf::Texture& m_selectedTexture;
		const sf::Texture& m_pressedTexture;
		sf::Sprite m_sprite;
		sf::Text m_text;
		bool m_isToggle;
	};

} // hauk::game::gui

#endif //HAUK_GAME_GUI_BUTTON_HPP
