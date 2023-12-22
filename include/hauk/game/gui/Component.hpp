//
// Created by hauk on 2023-12-22.
//

#ifndef HAUK_GAME_GUI_COMPONENT_HPP
#define HAUK_GAME_GUI_COMPONENT_HPP



namespace hauk::game::gui
{

	class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
	{
	public:
		typedef std::shared_ptr<Component> Ptr;

		Component();

		~Component() override;

		virtual bool isSelectable() const = 0;
		bool isSelected() const;
		virtual void select();
		virtual void deselect();
		virtual bool isActive() const;
		virtual void activate();
		virtual void deactivate();
		virtual void handleEvent(const sf::Event& event) = 0;
	private:
		bool m_isSelected;
		bool m_isActive;
	};

} // hauk::game::gui

#endif //HAUK_GAME_GUI_COMPONENT_HPP
