#pragma once

#include <iostream>

#include "Command.h"
#include "Table.h"

class LeftCommand : public Command
{
public:
    LeftCommand(Table* table) {
        m_table = table;
    }

    bool Execute() const override {
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
private:
    // TODO: Change primitive pointer
    Table* m_table;
};
