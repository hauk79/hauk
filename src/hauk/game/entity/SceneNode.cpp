//
// Created by hauk on 2023-12-21.
//

#include <hauk/game/util/util.hpp>
#include "hauk/game/input/Command.hpp"
#include "hauk/game/entity/SceneNode.hpp"



namespace hauk::game::entity
{
	SceneNode::SceneNode(unsigned int category)
	: m_children()
	, m_parent(nullptr)
	, m_defaultCategory(category)
	{

	}

	void SceneNode::attachChild(SceneNode::Ptr child)
	{
		child->m_parent = this;
		m_children.push_back(std::move(child));
	}

	SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
	{
		auto found = std::find_if(m_children.begin(), m_children.end(), [&] (Ptr& p) -> bool {
			return p.get() == &node;
		});
		assert(found != m_children.end());

		Ptr result = std::move(*found);
		result->m_parent = nullptr;
		m_children.erase(found);
		return result;
	}

	void SceneNode::update(sf::Time dt, input::CommandQueue& commands)
	{
		updateCurrent(dt, commands);
		updateChildren(dt, commands);
	}

	void SceneNode::updateCurrent(sf::Time dt, input::CommandQueue& commands)
	{
		// Do nothing by default
	}

	void SceneNode::updateChildren(sf::Time dt, input::CommandQueue& commands)
	{
		for (Ptr& child:m_children)
			child->update(dt, commands);
	}

	sf::Vector2f SceneNode::getWorldPosition() const
	{
		return getWorldTransform() * sf::Vector2f{};
	}

	sf::Transform SceneNode::getWorldTransform() const
	{
		sf::Transform transform {sf::Transform::Identity};

		for (const auto* node = this; node != nullptr; node = node->m_parent)
			transform = node->getTransform() * transform;

		return transform;
	}

	void SceneNode::onCommand(const input::Command& command, sf::Time dt)
	{
		// Command current node, if category matches
		if (command.category & getCategory())
			command.action(*this, dt);

		// Command children
		for (Ptr& child:m_children)
			child->onCommand(command, dt);
	}

	unsigned int SceneNode::getCategory() const
	{
		return m_defaultCategory;
	}

	void SceneNode::checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs)
	{
		checkNodeCollision(sceneGraph, collisionPairs);

		for (Ptr& child:sceneGraph.m_children)
			checkSceneCollision(*child, collisionPairs);
	}

	void SceneNode::checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs)
	{
		if (this != &node && collision(*this, node) && !isDestroyed() && !node.isDestroyed())
			collisionPairs.insert(std::minmax(this, &node));

		for (Ptr& child:m_children)
			child->checkNodeCollision(node, collisionPairs);
	}

	void SceneNode::removeWrecks()
	{
		// Remove all children which request so
		auto wreckfieldBegin = std::remove_if(m_children.begin(), m_children.end(),
				std::mem_fn(&SceneNode::isMarkedForRemoval));
		m_children.erase(wreckfieldBegin, m_children.end());

		// Call function recursively for all remaining children
		std::for_each(m_children.begin(), m_children.end(), std::mem_fn(&SceneNode::removeWrecks));
	}

	sf::FloatRect SceneNode::getBoundingRect() const
	{
		return sf::FloatRect();
	}

	bool SceneNode::isMarkedForRemoval() const
	{
		// By default, remove node if entity is destroyed
		return isDestroyed();
	}

	bool SceneNode::isDestroyed() const
	{
		// By default, scene node needn't be removed
		return false;
	}

	void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// Apply transform of current node
		states.transform *= getTransform();

		// Draw node and children with changed transform
		drawCurrent(target, states);
		drawChildren(target, states);

		// Draw bounding rectangle - disabled by default
		drawBoundingRect(target, states);
	}

	void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// Do nothing by default
	}

	void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (const auto& child:m_children)
			child->draw(target, states);
	}

	void SceneNode::drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const
	{
		sf::FloatRect rect = getBoundingRect();

		sf::RectangleShape shape;
		shape.setPosition(sf::Vector2f(rect.left, rect.top));
		shape.setSize(sf::Vector2f(rect.width, rect.height));
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineColor(sf::Color::Green);
		shape.setOutlineThickness(1.f);

		target.draw(shape);
	}

	bool collision(const SceneNode& lhs, const SceneNode& rhs)
	{
		return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
	}

	float distance(const SceneNode& lhs, const SceneNode& rhs)
	{
		return  util::length(lhs.getWorldPosition() - rhs.getWorldPosition());
	}
} // hauk::game::entity
