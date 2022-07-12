#pragma once

#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include <iostream>

#include "Command.h"
#include "Table.h"

class ReportCommand : public Command
{
public:
    ReportCommand(Table* table) {
        m_table = table;
    }

    bool Execute() const override {
        // Return false if robot is not yet added
        if (!m_table->IsRobotPlaced()) {
            // No valid robot target
            std::cout << "> No robot added yet. Please execute PLACE command." << std::endl;
            return false;
        }

        std::cout << "> " << m_table->GetRobotReference()->ToString() << std::endl;
        return true;
    }
private:
    Table* m_table;
};

#endif