//
// Created by hauk on 2024-01-12.
//

#include <hauk/game/Player.hpp>

namespace hauk::game
{

	Player::Player()
	: m_currentMissionStatus{}
	{
	}

	void Player::assignKey(Action action, sf::Keyboard::Key key)
	{
		// Remove all keys that already map to action
		for (auto itr = m_keyBinding.begin(); itr != m_keyBinding.end();)
		{
			if (itr->second == action)
				m_keyBinding.erase(itr++);
			else
				++itr;
		}

		// Insert new binding
		m_keyBinding[key] = action;
	}

	sf::Keyboard::Key Player::getAssignedKey(Action action) const
	{
		for (auto pair:m_keyBinding)
		{
			if (pair.second == action)
				return pair.first;
		}

		return sf::Keyboard::Unknown;
	}

	void Player::setMissionStatus(MissionStatus status)
	{
		m_currentMissionStatus = status;
	}

	Player::MissionStatus Player::getMissionStatus()
	{
		return m_currentMissionStatus;
	}
}
