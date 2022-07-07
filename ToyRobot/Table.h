#pragma once

#include <memory>

#include "Position.h"
#include "Robot.h"

class Table
{
public:

	std::weak_ptr<Robot> GetRobotReference() {
		return m_trackedRobot;
	}

	bool PlaceRobot(std::shared_ptr<Robot>& r) {
		bool isSuccessful = false;
		if (nullptr != r) {
			m_trackedRobot = r;
			isSuccessful = true;
		}
		return isSuccessful;
	}
	
	// TODO: Must move this logic to command classes instead
	/*
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
	*/

	bool IsInBounds(const Position& p) const {
		return (
			p.GetX() >= 0 &&
			p.GetX() < m_width &&
			p.GetY() >= 0 &&
			p.GetY() < m_length
		);
	}

	bool IsUnoccupuied(const Position& p) const {
		return (
			m_trackedRobot->GetPosition().GetX() != p.GetX() ||
			m_trackedRobot->GetPosition().GetY() != p.GetY()
		);
	}

private:
	unsigned int m_width;					// x-axis
	unsigned int m_length;					// y-axis
	std::shared_ptr<Robot> m_trackedRobot;	// pointer to current tracked robot
};

