#pragma once

#ifndef TABLE_H
#define TABLE_H

#include <memory>
#include <string>

#include "Position.h"
#include "Robot.h"

class Table
{
public:

	Robot* GetRobotReference() {
		return m_trackedRobot;
	}

	bool PlaceRobot(const Robot& robot) {
		if (nullptr != m_trackedRobot) {
			return false;
		}

		m_trackedRobot = new Robot(robot);
		return true;
	}

	bool RemoveRobot() {
		if (nullptr == m_trackedRobot) {
			return false;
		}

		delete m_trackedRobot;
		return true;
	}

	bool IsRobotPlaced() {
		return (nullptr != m_trackedRobot);
	}

	bool IsInBounds(const Position& p) const {
		return (
			p.GetX() >= 0 &&
			p.GetX() < m_width &&
			p.GetY() >= 0 &&
			p.GetY() < m_length
		);
	}

	Table() {
		m_width = 0;
		m_length = 0;
		m_trackedRobot = nullptr;
	}

	Table(int w, int l) {
		m_width = w;
		m_length = l;
		m_trackedRobot = nullptr;
	}

	~Table() {
		RemoveRobot();
	}

private:
	int m_width = 0;							// x-axis
	int m_length = 0;							// y-axis
	Robot* m_trackedRobot = nullptr;			// pointer to current tracked robot
};

#endif