#include "LeftCommand.h"

#include <iostream>

bool LeftCommand::Execute() const {
	// Return false if robot is not yet added
	if (!m_table->IsRobotPlaced()) {
		// No valid robot target
		std::cout << "> No robot added yet. Please execute PLACE command." << std::endl;
		return false;
	}

	// Update actual robot direction
	m_table->GetRobotReference()->FaceLeft();
	return true;
}