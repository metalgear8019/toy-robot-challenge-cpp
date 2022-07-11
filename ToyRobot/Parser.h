#pragma once

#include <string>
#include <sstream>
#include <algorithm>

#include "Command.h"
#include "PlaceCommand.h"
#include "MoveCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "ReportCommand.h"
#include "Table.h"

class Parser
{
public:
	bool ParseCommand(std::string strInput) {
		std::stringstream strInputStream(strInput);
		std::string strCmd;

		if (!std::getline(strInputStream, strCmd, ' ')) {
			// No command inputted
			std::cout << "> No command inputted!" << std::endl;
			return false;
		}

		Command* cmd;
		std::transform(strCmd.begin(), strCmd.end(), strCmd.begin(), ::toupper);
		if (strCmd.compare("PLACE") == 0) {
			std::string strArgs = strInput;
			strArgs.erase(0, 5);
			cmd = new PlaceCommand(m_table, strArgs);
		} else if (strCmd.compare("MOVE") == 0) {
			cmd = new MoveCommand(m_table);
		} else if (strCmd.compare("LEFT") == 0) {
			cmd = new LeftCommand(m_table);
		} else if (strCmd.compare("RIGHT") == 0) {
			cmd = new RightCommand(m_table);
		} else if (strCmd.compare("REPORT") == 0) {
			cmd = new ReportCommand(m_table);
		} else {
			// Unrecognized command
			std::cout << "> Unrecognized command." << std::endl;
			return false;
		}

		if (cmd->Execute()) {
			delete cmd;
			return true;
		}

		// Command execution failed
		return false;
	}

	Parser() {
		m_table = new Table(5, 5);
	}

	~Parser() {
		delete m_table;
	}
private:
	Table* m_table;
};

