//
// Created by hauk on 2023-12-23.
//

#ifndef HAUK_GAME_GUI_CONTAINER_HPP
#define HAUK_GAME_GUI_CONTAINER_HPP


#include "Component.hpp"

namespace hauk::game::gui
{

	class Container : public Component
	{
	public:
		typedef std::shared_ptr<Container> Ptr;

		Container();

		void pack(Component::Ptr component);

		bool isSelectable() const override;
		void handleEvent(const sf::Event& event) override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		bool hasSelection() const;
		void select(std::size_t index);
		void selectNext();
		void selectPrevious();

		std::vector<Component::Ptr> m_children;
		int m_selectedChild;
	};

} // hauk::game::gui

#endif //HAUK_GAME_GUI_CONTAINER_HPP
