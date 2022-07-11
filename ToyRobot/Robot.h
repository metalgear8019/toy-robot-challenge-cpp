#pragma once

#include <string>

#include "Constants.h"
#include "Position.h"

class Robot
{
public:
	// Constructors
	Robot() : Robot(0, 0, DIRECTION::NORTH) {}
	Robot(const Position& p, const Direction& direction) : Robot(p.GetX(), p.GetY(), direction) {}
	Robot(int x, int y, const Direction& direction) {
		m_pos.SetX(x);
		m_pos.SetY(y);
		m_direction = direction;
	}

	// Getters
	const Position& GetPosition() { return m_pos; }
	const int& GetDirection() { return m_direction; }
	
	// Setters
	void SetPosition(const Position& p) { m_pos = p; }
	void SetDirection(const Direction& d) { m_direction = d; }

	// TODO: Remove rotation logic from this class, create dedicated Direction class
	// Manipulate rotation below
	void FaceLeft() {
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

	void FaceRight() {
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

	std::string ToString() {
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
	
private:
	Position m_pos;
	Direction m_direction;
};

