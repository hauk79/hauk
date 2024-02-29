//
// Created by hauk on 2024-02-29.
//

#ifndef HAUK_POSTEFFECT_HPP
#define HAUK_POSTEFFECT_HPP



namespace hauk::game::effect
{

	class PostEffect : sf::NonCopyable
	{
	public:
		virtual ~PostEffect();
		virtual void apply(const sf::RenderTexture& input, sf::RenderTarget& output) = 0;

		static bool isSupported();

	protected:
		static void applyShader(const sf::Shader& shader, sf::RenderTarget& output);
	};

} // hauk::game::effect

#endif //HAUK_POSTEFFECT_HPP
