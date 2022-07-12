#include "Robot.h"

void Robot::FaceLeft() {
	switch (m_direction)
	{
	case DIRECTION::NORTH:	m_direction = DIRECTION::WEST; break;
	case DIRECTION::EAST:	m_direction = DIRECTION::NORTH; break;
	case DIRECTION::WEST:	m_direction = DIRECTION::SOUTH; break;
	case DIRECTION::SOUTH:	m_direction = DIRECTION::EAST; break;
	default:
		// do nothing
		break;
	}
}

void Robot::FaceRight() {
	switch (m_direction)
	{
	case DIRECTION::NORTH:	m_direction = DIRECTION::EAST; break;
	case DIRECTION::EAST:	m_direction = DIRECTION::SOUTH; break;
	case DIRECTION::WEST:	m_direction = DIRECTION::NORTH; break;
	case DIRECTION::SOUTH:	m_direction = DIRECTION::WEST; break;
	default:
		// do nothing
		break;
	}
}

std::string Robot::ToString() {
	std::string strDir;
	switch (m_direction)
	{
	case DIRECTION::NORTH:	strDir = " NORTH"; break;
	case DIRECTION::EAST:	strDir = " EAST"; break;
	case DIRECTION::WEST:	strDir = " WEST"; break;
	case DIRECTION::SOUTH:	strDir = " SOUTH"; break;
	default:
		strDir = " UNKNOWN";
		break;
	}

	return
		std::to_string(m_pos.GetX()) + "," +
		std::to_string(m_pos.GetY()) + strDir;
}
