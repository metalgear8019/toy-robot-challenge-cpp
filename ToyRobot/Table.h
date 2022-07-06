#pragma once

#include "Position.h"
#include "Robot.h"

class Table
{
public:
	// TODO: Get rid of traditional pointer "Robot*"

	bool PlaceRobot(Robot* r) {
		bool isSuccessful = false;
		if (nullptr != r) {
			m_trackedRobot = r;
			isSuccessful = true;
		}
		return isSuccessful;
	}

	bool MoveRobot() {
		int currentDir = m_trackedRobot->GetDirection();
		Position currentPos = m_trackedRobot->GetPosition();
		Position newPos = currentPos;
		newPos.MoveTowards(currentDir);

		// Check if next position will be still in bounds
		if (newPos.GetX() >= 0 &&
			newPos.GetX() < m_width &&
			newPos.GetY() >= 0 &&
			newPos.GetY() < m_length) {
			
			// Update robot position
			m_trackedRobot->Move();
			return true;
		}

		return false;
	}

	Robot* GetRobotInfo() { return m_trackedRobot; }

private:
	unsigned int m_width;	// x-axis
	unsigned int m_length;	// y-axis
	Robot* m_trackedRobot;	// pointer to current tracked robot
};

