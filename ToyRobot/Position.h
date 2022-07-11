#pragma once

#include "Constants.h"

/// <summary>
/// Position.h
///		Contains the coordinate data of a given entity.
/// 
/// Notes:
///		(1) Can add "m_z" for a 3rd coordinate data in a 3D plane.
///		(2) Negative position values are allowed in this class.
/// </summary>
class Position
{
public:
	// Main constructor
	Position(int x, int y) {
		m_x = x;
		m_y = y;
	}

	// Other constructors for default values
	Position() : Position(0, 0) {}

	// Getters
	int GetX() const { return m_x; }
	int GetY() const { return m_y; }

	// Setters
	void SetX(const int& x) { m_x = x; }
	void SetY(const int& y) { m_y = y; }

	// Setter with direction check
	void MoveTowards(const Direction& direction) {
		MoveTowards(direction, 1);
	}

	// Setter with direction check + variable distance
	void MoveTowards(const Direction& direction, const int& distance) {
		switch (direction) {
		case DIRECTION::NORTH:	m_y -= distance; break;
		case DIRECTION::EAST:	m_x += distance; break;
		case DIRECTION::WEST:	m_x -= distance; break;
		case DIRECTION::SOUTH:	m_y += distance; break;
		default:
			// unsupported direction, do nothing
			break;
		}
	}

private:
	int m_x;
	int m_y;
};
