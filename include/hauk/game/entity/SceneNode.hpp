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
		typedef std::pair<SceneNode*, SceneNode*> Pair;

		explicit SceneNode(unsigned int category = Category::None);

		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);

		void update(sf::Time dt, input::CommandQueue& commands);

		sf::Vector2f getWorldPosition() const;
		sf::Transform getWorldTransform() const;

		void onCommand(const input::Command& command, sf::Time dt);
		virtual unsigned int getCategory() const;

		void checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
		void checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
		virtual sf::FloatRect getBoundingRect() const;
		virtual bool isMarkedForRemoval() const;
		virtual bool isDestroyed() const;
	private:
		virtual void updateCurrent(sf::Time dt, input::CommandQueue& commands);
		void updateChildren(sf::Time dt, input::CommandQueue& commands);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;


		std::vector<Ptr> m_children;
		SceneNode* m_parent;
		unsigned int m_defaultCategory;
	};

	bool collision(const SceneNode& lhs, const SceneNode& rhs);
	float distance(const SceneNode& lhs, const SceneNode& rhs);
} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_SCENENODE_HPP
