//
// Created by hauk on 2024-02-29.
//

#ifndef HAUK_BLOOMEFFECT_HPP
#define HAUK_BLOOMEFFECT_HPP


#include <hauk/game/resource/ResourceIdentifiers.hpp>
#include "PostEffect.hpp"

namespace hauk::game::effect
{

	class BloomEffect : public PostEffect
	{
	public:
		BloomEffect();

		void apply(const sf::RenderTexture& input, sf::RenderTarget& output) override;

	private:
		typedef std::array<sf::RenderTexture, 2> RenderTexutreArray;

		void prepareTextures(sf::Vector2u size);

		void filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
		void blurMultipass(RenderTexutreArray& renderTextures);
		void blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
		void downsample(const sf::RenderTexture& input, sf::RenderTexture& output);
		void add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& output);

		resource::ShaderHolder m_shaders;

		sf::RenderTexture m_brightnessTexture;
		RenderTexutreArray m_firstPassTextures;
		RenderTexutreArray m_secondPassTextures;
	};

} // hauk::game::effect

#endif //HAUK_BLOOMEFFECT_HPP
