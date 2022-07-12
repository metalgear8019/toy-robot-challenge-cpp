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

	bool IsUnoccupuied(const Position& p) const {
		if (nullptr == m_trackedRobot) {
			return true;
		}

		return (
			m_trackedRobot->GetPosition().GetX() != p.GetX() ||
			m_trackedRobot->GetPosition().GetY() != p.GetY()
		);
	}

	std::string GenerateStringDisplay() {
		std::string strDisplay = "";

		for (int l = 0; l < m_length; l++) {
			strDisplay += generateHorizontalBorder(m_width);

			for (int w = 0; w < m_width; w++) {
				strDisplay += "| ";

				// Display a character "R" where the tracked robot exists
				if (!IsUnoccupuied(Position(l, w))) {
					strDisplay += "R";
				} else {
					strDisplay += " ";
				}
				
				strDisplay += " ";
			}

			// End line only if m_width is > 0
			if (m_width > 0)
				strDisplay += "|\n";
		};

		// End line only if m_length is > 0
		if (m_length > 0)
			strDisplay += generateHorizontalBorder(m_width);

		return strDisplay;
	}

	Table() {
		m_width = 0;
		m_length = 0;
		m_trackedRobot = nullptr;
	}

	Table(int l, int w) {
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
	// TODO: Change primitive pointer
	Robot* m_trackedRobot = nullptr;					// pointer to current tracked robot

	std::string	generateHorizontalBorder(int grid_width) {
		std::string strBorder = "";

		// Do not generate if grid_width is invalid
		if (grid_width <= 0)
			return strBorder;

		for (int w = 0; w < grid_width; w++) {
			strBorder += "+---";
		}

		strBorder += "+\n";
		return strBorder;
	}
};

#endif