//
// Created by hauk on 2023-12-21.
//

#ifndef HAUK_GAME_ENTITY_SCENENODE_HPP
#define HAUK_GAME_ENTITY_SCENENODE_HPP



namespace hauk::game::entity
{

	class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
	{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;

		SceneNode();

		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);

		void update(sf::Time dt);

		sf::Vector2f getWorldPosition() const;
		sf::Transform getWorldTransform() const;

	private:
		virtual void updateCurrent(sf::Time dt);
		void updateChildren(sf::Time dt);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;


		std::vector<Ptr> m_children;
		SceneNode* m_parent;
	};

} // hauk::game::entity

#endif //HAUK_GAME_ENTITY_SCENENODE_HPP
