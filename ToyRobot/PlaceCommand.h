#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

#include "Command.h"
#include "Table.h"

class PlaceCommand : public Command
{
public:
    PlaceCommand(Table* table, std::string args) {
        m_table = table;
        m_args = args;
    }

    bool Execute() const override {
        // Return false if robot is already placed
        if (m_table->IsRobotPlaced()) {
            // Robot already added
            std::cout << "> Robot already added!" << std::endl;
            return false;
        }

        // Split arguments and validate number of inputs
        std::vector<std::string> splitArgs = splitInputs(m_args);
        if (splitArgs.size() != 3) {
            // Invalid param count
            std::cout << "> PLACE expects 3 parameters: PosX, PosY, DIRECTION" << std::endl;
            return false;
        }

        // Deserializing string arguments
        Position argPos;
        Direction argDir = DIRECTION::UNKNOWN;
        
        if (!parsePosition(argPos, splitArgs[0], splitArgs[1])) {
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

        if (!parseDirection(argDir, splitArgs[2])) {
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

    std::vector<std::string> splitInputs(std::string args) const {
        std::vector<std::string> result;
        std::stringstream argsStream(args);
        std::string arg;

        while (std::getline(argsStream, arg, ',')) {
            result.push_back(arg);
        }

        return result;
    }

    bool parsePosition(Position& outPos, std::string inX, std::string inY) const {
        bool isSuccessful = true;
        try {
            outPos.SetX(stoi(inX));
            outPos.SetY(stoi(inY));
        }
        catch (std::exception&) { isSuccessful = false; }
        return isSuccessful;
    }

    bool parseDirection(Direction& outDir, std::string inDir) const {
        // TODO: Remove whitespace before comparing
        bool isSuccessful = true;
        try {
            std::transform(inDir.begin(), inDir.end(), inDir.begin(), ::toupper);
            if (inDir.compare("NORTH") == 0) {
                outDir = DIRECTION::NORTH;
            } else if (inDir.compare("EAST") == 0) {
                outDir = DIRECTION::EAST;
            } else if (inDir.compare("WEST") == 0) {
                outDir = DIRECTION::WEST;
            } else if (inDir.compare("SOUTH") == 0) {
                outDir = DIRECTION::SOUTH;
            } else {
                isSuccessful = false;
            }
        }
        catch (std::exception&) { isSuccessful = false; }
        return isSuccessful;
    }
};
