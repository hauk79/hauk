//
// Created by hauk on 2023-11-30.
//

#include <hauk/game/Player.hpp>
#include "hauk/game/Application.hpp"

namespace hauk::game
{
	const sf::Time Application::TimePerFrame{sf::seconds(1.f/60.f)};

	Application::Application(Player* player)
	: m_window(sf::VideoMode(1024, 768), "Application", sf::Style::Close)
	, m_stateStack(state::State::Context{ m_window, m_textures, m_fonts, player})
	, m_staticsText()
	{
		m_window.setKeyRepeatEnabled(false);

		m_fonts.load(resource::Fonts::Main, "media/hauk/font/Sansation.ttf");

		m_textures.load(resource::Textures::Buttons, "media/hauk/textures/Buttons.png");

		m_staticsText.setFont(m_fonts.get(resource::Fonts::Main));
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

				// Check inside this loop, because stack might be empty before update() call
				if (m_stateStack.isEmpty())
					m_window.close();
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
			m_stateStack.handleEvent(event);

			if (event.type == sf::Event::Closed)
				m_window.close();
		}
	}

	void Application::update(sf::Time dt)
	{
		m_stateStack.update(dt);
	}

	void Application::render()
	{
		m_window.clear();

		m_stateStack.draw();

		m_window.setView(m_window.getDefaultView());
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
