//
// Created by hauk on 2023-12-21.
//

#include "hauk/game/input/Category.hpp"
#include "hauk/game/input/Command.hpp"
#include "hauk/game/entity/SceneNode.hpp"



namespace hauk::game::entity
{
	SceneNode::SceneNode()
	: m_children()
	, m_parent(nullptr)
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

	void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// Apply transform of current node
		states.transform *= getTransform();

		// Draw node and children with changed transform
		drawCurrent(target, states);
		drawChildren(target, states);
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
		return game::input::Category::Scene;
	}

} // hauk::game::entity
