#pragma once

#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include <iostream>
#include <vector>

#include "Command.h"
#include "Parser.h"
#include "Table.h"

class PlaceCommand : public Command
{
public:
    PlaceCommand(Table* table, std::string args) {
        m_table = table;
        m_args = args;
    }

    bool Execute() const override {
        Parser parser;

        // Return false if robot is already placed
        if (m_table->IsRobotPlaced()) {
            // Robot already added
            std::cout << "> Robot already added!" << std::endl;
            return false;
        }

        // Split arguments and validate number of inputs
        std::vector<std::string> splitArgs = parser.SplitInputs(m_args, ',');
        if (splitArgs.size() != 3) {
            // Invalid param count
            std::cout << "> PLACE expects 3 parameters: PosX, PosY, DIRECTION" << std::endl;
            return false;
        }

        // Deserializing string arguments
        Position argPos;
        Direction argDir = DIRECTION::UNKNOWN;
        
        if (!parser.ParsePosition(argPos, splitArgs[0], splitArgs[1])) {
            // Invalid parameter for position
            std::cout << "> Invalid position parameter." << std::endl;
            return false;
        }

        if (!m_table->IsInBounds(argPos)) {
            // Robot cannot move out of bounds
            std::cout << "> Cannot place robot outside the table." << std::endl;
            return false;
        }

        if (!m_table->IsUnoccupuied(argPos)) {
            // Robot cannot move to occupied cells
            std::cout << "> Cannot place robot due to existing entity in specified position." << std::endl;
            return false;
        }

        if (!parser.ParseDirection(argDir, splitArgs[2])) {
            // Invalid parameter for direction
            std::cout << "> Invalid direction parameter." << std::endl;
            return false;
        }

        // Add newly created robot
        m_table->PlaceRobot(Robot(argPos, argDir));
        return true;
    }
private:
    // TODO: Change primitive pointer
    Table* m_table;
    std::string m_args;
};

#endif