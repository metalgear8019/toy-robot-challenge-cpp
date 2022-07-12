#pragma once

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Constants.h"
#include "Command.h"
#include "PlaceCommand.h"
#include "MoveCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "ReportCommand.h"
#include "Table.h"

class CommandFactory
{
public:
	Command* CreateCommand(CommandCode cmdCode, Table* table, std::string rawCmdInput) {
		Command* cmd = nullptr;
		switch (cmdCode)
		{
		case CMD_PLACE:
			rawCmdInput.erase(0, 5); // Removing "PLACE" before passing as argument
			cmd = new PlaceCommand(table, rawCmdInput);
			break;
		case CMD_MOVE:
			cmd = new MoveCommand(table);
			break;
		case CMD_LEFT:
			cmd = new LeftCommand(table);
			break;
		case CMD_RIGHT:
			cmd = new RightCommand(table);
			break;
		case CMD_REPORT:
			cmd = new ReportCommand(table);
			break;
		default:
			std::cout << "> Unrecognized command." << std::endl;
			break;
		}
		return cmd;
	}
};

#endif