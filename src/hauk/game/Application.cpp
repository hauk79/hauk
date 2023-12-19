//
// Created by hauk on 2023-11-30.
//

#include "hauk/game/Application.h"

namespace hauk::game
{
	const sf::Time Application::TimePerFrame{sf::seconds(1.f/60.f)};

	Application::Application()
	: m_window(sf::VideoMode(640, 480), "Application", sf::Style::Close)
	, m_stateStack(states::State::Context{m_window})
	{
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

		m_window.display();
	}
} // hauk::game
