//
// Created by hauk on 2023-12-21.
//

#ifndef HAUK_GAME_ENTITY_SCENENODE_HPP
#define HAUK_GAME_ENTITY_SCENENODE_HPP


#include <hauk/game/input/CommandQueue.hpp>
#include "Category.hpp"

namespace hauk::game::input
{
	struct Command;
}

namespace hauk::game::entity
{

	class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
	{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;

		explicit SceneNode(unsigned int category = Category::None);

		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);

		void update(sf::Time dt, input::CommandQueue& commands);

		sf::Vector2f getWorldPosition() const;
		sf::Transform getWorldTransform() const;

		void onCommand(const input::Command& command, sf::Time dt);
		virtual unsigned int getCategory() const;
	private:
		virtual void updateCurrent(sf::Time dt, input::CommandQueue& commands);
		void updateChildren(sf::Time dt, input::CommandQueue& commands);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;


		std::vector<Ptr> m_children;
		SceneNode* m_parent;
		unsigned int m_defaultCategory;
	};

} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_SCENENODE_HPP
