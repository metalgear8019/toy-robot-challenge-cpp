#pragma once

#ifndef RIGHTCOMMAND_H
#define RIGHTCOMMAND_H

#include <iostream>

#include "Command.h"
#include "Table.h"

class RightCommand : public Command
{
public:
    RightCommand(Table* table) {
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
        m_table->GetRobotReference()->FaceRight();
        return true;
    }
private:
    Table* m_table;
};

#endif