#pragma once

#ifndef ROBOT_H
#define ROBOT_H

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
	const Direction& GetDirection() { return m_direction; }
	
	// Setters
	void SetPosition(const Position& p) { m_pos = p; }
	void SetDirection(const Direction& d) { m_direction = d; }

	// Other methods
	void FaceLeft();
	void FaceRight();
	std::string ToString();
	
private:
	Position m_pos;
	Direction m_direction;
};

#endif