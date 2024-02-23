//
// Created by hauk on 2024-02-23.
//

#ifndef HAUK_ANIMATION_HPP
#define HAUK_ANIMATION_HPP



namespace hauk::game::entity
{

	class Animation : public sf::Drawable, public sf::Transformable
	{
	public:
		Animation();
		explicit Animation(const sf::Texture& texture);

		void setTexture(const sf::Texture& texture);
		const sf::Texture* getTexture() const;

		void setFrameSize(sf::Vector2i frameSize);
		sf::Vector2i getFrameSize() const;

		void setNumFrames(std::size_t numFrames);
		std::size_t getNumFrames() const;

		void setDuration(sf::Time duration);
		sf::Time getDuration() const;

		void setRepeating(bool flag);
		bool isRepeating() const;

		void restart();
		bool isFinished() const;

		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;

		void update(sf::Time dt);

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::Sprite m_sprite;
		sf::Vector2i m_frameSize;
		std::size_t m_numFrames;
		std::size_t m_currentFrame;
		sf::Time m_duration;
		sf::Time m_elapsedTime;
		bool m_repeat;
	};

} // hauk::game::entity

#endif //HAUK_ANIMATION_HPP
