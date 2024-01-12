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

	void Player::setMissionStatus(MissionStatus status)
	{
		m_currentMissionStatus = status;
	}

	Player::MissionStatus Player::getMissionStatus()
	{
		return m_currentMissionStatus;
	}
}
