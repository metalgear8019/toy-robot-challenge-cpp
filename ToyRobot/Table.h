#pragma once

#ifndef TABLE_H
#define TABLE_H

#include "Position.h"
#include "Robot.h"

class Table
{
public:

	// Methods
	Robot* GetRobotReference();
	bool PlaceRobot(const Robot& robot);
	bool RemoveRobot();
	bool IsRobotPlaced() const;
	bool IsInBounds(const Position& p) const;
	bool Resize(int w, int l);

	// Constructors
	Table() : Table(0,0) {}
	Table(int w, int l) {
		if (!Resize(w, l)) {
			m_width = 0;
			m_length = 0;
		}
		m_trackedRobot = nullptr;
	}

	~Table() {
		RemoveRobot();
	}

private:
	int m_width;								// x-axis
	int m_length;								// y-axis
	Robot* m_trackedRobot;						// pointer to current tracked robot
};

#endif