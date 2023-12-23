//
// Created by hauk on 2023-12-23.
//

#ifndef HAUK_GAME_GUI_LABEL_HPP
#define HAUK_GAME_GUI_LABEL_HPP


#include <hauk/game/resource/ResourceIdentifiers.hpp>
#include "Component.hpp"

namespace hauk::game::gui
{

	class Label : public Component
	{
	public:
		typedef std::shared_ptr<Label> Ptr;

		Label(const std::string& text, const resource::FontHolder& fonts);

		bool isSelectable() const override;

		void handleEvent(const sf::Event& event) override;

		void setText(const std::string& text);
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Text m_text;
	};

} // hauk::game::gui

#endif //HAUK_GAME_GUI_LABEL_HPP
