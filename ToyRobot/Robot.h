#pragma once

#include "Constants.h"
#include "Position.h"
#include "Table.h"

class Robot
{
public:
	// Constructors
	Robot(const Position& p, int direction) : Robot(p.GetX(), p.GetY(), direction) {}
	Robot(int x, int y, int direction) {
		m_pos.SetX(x);
		m_pos.SetY(y);
		m_direction = direction;
	}

	// Getters
	const Position& GetPosition() { return m_pos; }
	const int& GetDirection() { return m_direction; }

	// Update methods below
	void Move() {
		m_pos.MoveTowards(m_direction);
	}

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
	
private:
	Position m_pos;
	int m_direction;
};

