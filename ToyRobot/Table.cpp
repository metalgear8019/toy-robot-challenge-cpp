#include "Table.h"

Robot* Table::GetRobotReference() {
	return m_trackedRobot;
}

bool Table::PlaceRobot(const Robot& robot) {
	if (nullptr != m_trackedRobot) {
		return false;
	}

	m_trackedRobot = new Robot(robot);
	return true;
}

bool Table::RemoveRobot() {
	if (nullptr == m_trackedRobot) {
		return false;
	}

	delete m_trackedRobot;
	m_trackedRobot = nullptr;
	return true;
}

bool Table::IsRobotPlaced() const {
	return (nullptr != m_trackedRobot);
}

bool Table::IsInBounds(const Position& p) const {
	return (
		p.GetX() >= 0 &&
		p.GetX() < m_width &&
		p.GetY() >= 0 &&
		p.GetY() < m_length
		);
}

bool Table::Resize(int w, int l) {
	if (w <= 0 || l <= 0) {
		return false;
	}

	m_width = w;
	m_length = l;
	return true;
}