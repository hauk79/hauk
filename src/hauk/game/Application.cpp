//
// Created by hauk on 2023-11-30.
//

#include "hauk/game/Application.h"

namespace hauk::game
{
	Application::Application()
	: m_window(sf::VideoMode(640, 480), "Application", sf::Style::Close)
	{
	}
} // hauk::game
