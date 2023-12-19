//
// Created by hauk on 2023-11-30.
//

#include "hauk/game/Application.hpp"

namespace hauk::game
{
	const sf::Time Application::TimePerFrame{sf::seconds(1.f/60.f)};

	Application::Application()
	: m_window(sf::VideoMode(640, 480), "Application", sf::Style::Close)
	, m_stateStack(states::State::Context{m_window, m_textures, m_fonts, m_player})
	, m_staticsText()
	{
		m_fonts.load(resources::Fonts::Main, "media/hauk/fonts/Sansation.ttf");

		m_staticsText.setFont(m_fonts.get(resources::Fonts::Main));
		m_staticsText.setPosition(5.f, 5.f);
		m_staticsText.setCharacterSize(10u);
	}

	void Application::run()
	{
		sf::Clock clock{};
		sf::Time timeSinceLastUpdate{sf::Time::Zero};

		while (m_window.isOpen())
		{
			sf::Time dt = clock.restart();
			timeSinceLastUpdate += dt;
			while (timeSinceLastUpdate > TimePerFrame)
			{
				timeSinceLastUpdate -= TimePerFrame;

				processInput();
				update(TimePerFrame);
			}

			updateStatistics(dt);
			render();
		}
	}

	void Application::processInput()
	{
		sf::Event event{};
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}
	}

	void Application::update(sf::Time dt)
	{

	}

	void Application::render()
	{
		m_window.clear();

		m_window.draw(m_staticsText);

		m_window.display();
	}

	void Application::updateStatistics(sf::Time dt)
	{
		static sf::Time statisticsUpdateTime{};
		static std::size_t statisticsNumFrames{};

		statisticsUpdateTime += dt;
		statisticsNumFrames += 1;
		if (statisticsUpdateTime >= sf::seconds(1.f))
		{
			m_staticsText.setString("FPS: " + std::to_string(statisticsNumFrames));

			statisticsUpdateTime -= sf::seconds(1.f);
			statisticsNumFrames = 0;
		}
	}
} // hauk::game
