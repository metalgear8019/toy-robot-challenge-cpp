#pragma once

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <regex>

#include "Constants.h"
#include "Position.h"

class Parser
{
public:
	CommandCode ParseCommand(std::string strInput) {
		std::stringstream strInputStream(strInput);
		std::string strCmd;

		if (!std::getline(strInputStream, strCmd, ' ')) {
			// No command inputted
			return CMD_UNKNOWN;
		}

		std::transform(strCmd.begin(), strCmd.end(), strCmd.begin(), ::toupper);
		if (strCmd.compare("PLACE") == 0) {
			return CMD_PLACE;
		} else if (strCmd.compare("MOVE") == 0) {
			return CMD_MOVE;
		} else if (strCmd.compare("LEFT") == 0) {
			return CMD_LEFT;
		} else if (strCmd.compare("RIGHT") == 0) {
			return CMD_RIGHT;
		} else if (strCmd.compare("REPORT") == 0) {
			return CMD_REPORT;
		} else if (strCmd.compare("EXIT") == 0) {
			return CMD_EXIT;
		} else {
			// Unrecognized command
			return CMD_UNKNOWN;
		}
	}

	std::vector<std::string> SplitInputs(std::string args, char delim) const {
		std::vector<std::string> result;
		std::stringstream argsStream(args);
		std::string arg;

		while (std::getline(argsStream, arg, delim)) {
			result.push_back(arg);
		}

		return result;
	}

	std::string RemoveLeadingAndTrailingWhitespaces(const std::string& str) const {
		std::string result = str;
		std::regex leadingRegex("^\\s+");
		std::regex trailingRegex("\\s+$");
		result = std::regex_replace(result, leadingRegex, "");
		result = std::regex_replace(result, trailingRegex, "");
		return result;
	}

	bool ParsePosition(Position& outPos, std::string inX, std::string inY) const {
		bool isSuccessful = true;
		try {
			outPos.SetX(stoi(inX));
			outPos.SetY(stoi(inY));
		}
		catch (std::exception&) { isSuccessful = false; }
		return isSuccessful;
	}

	bool ParseDirection(Direction& outDir, std::string inDir) const {
		bool isSuccessful = true;
		try {
			// Remove leading & trailing whitespace and convert to upper case
			inDir = RemoveLeadingAndTrailingWhitespaces(inDir);
			std::transform(inDir.begin(), inDir.end(), inDir.begin(), ::toupper);

			if (inDir.compare("NORTH") == 0) {
				outDir = DIRECTION::NORTH;
			}
			else if (inDir.compare("EAST") == 0) {
				outDir = DIRECTION::EAST;
			}
			else if (inDir.compare("WEST") == 0) {
				outDir = DIRECTION::WEST;
			}
			else if (inDir.compare("SOUTH") == 0) {
				outDir = DIRECTION::SOUTH;
			}
			else {
				isSuccessful = false;
			}
		}
		catch (std::exception&) { isSuccessful = false; }
		return isSuccessful;
	}

	Parser() {}
};

#endif