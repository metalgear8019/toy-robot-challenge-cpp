#include "ReportCommand.h"

#include <iostream>

bool ReportCommand::Execute() const {
	// Return false if robot is not yet added
	if (!m_table->IsRobotPlaced()) {
		// No valid robot target
		std::cout << "> No robot added yet. Please execute PLACE command." << std::endl;
		return false;
	}

	std::cout << "> " << m_table->GetRobotReference()->ToString() << std::endl;
	return true;
}