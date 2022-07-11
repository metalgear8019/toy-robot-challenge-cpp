#pragma once

#include <iostream>

#include "Command.h"
#include "Table.h"

class MoveCommand : public Command
{
public:
    MoveCommand(Table* table) {
        m_table = table;
    }

    bool Execute() const override {
        // Return false if robot is not yet added
        if (!m_table->IsRobotPlaced()) {
            // No valid robot target
            std::cout << "> No robot added yet. Please execute PLACE command." << std::endl;
            return false;
        }

        Position nextPos(m_table->GetRobotReference()->GetPosition());
        Direction currDir = m_table->GetRobotReference()->GetDirection();

        // Check if next position is valid
        nextPos.MoveTowards(currDir);
        
        if (!m_table->IsInBounds(nextPos)) {
            // Robot cannot move out of bounds
            std::cout << "> Cannot move outside the table." << std::endl;
            return false;
        }

        if (!m_table->IsUnoccupuied(nextPos)) {
            // Robot cannot move to occupied cells
            std::cout << "> Cannot move due to existing entity in specified position." << std::endl;
            return false;
        }

        // Update actual robot position
        m_table->GetRobotReference()->SetPosition(nextPos);
        return true;
    }
private:
    // TODO: Change primitive pointer
    Table* m_table;
};
