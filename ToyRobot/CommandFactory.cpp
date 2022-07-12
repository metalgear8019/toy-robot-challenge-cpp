#include "CommandFactory.h"
#include "PlaceCommand.h"
#include "MoveCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "ReportCommand.h"

#include <iostream>

Command* CommandFactory::CreateCommand(CommandCode cmdCode, Table* table, std::string rawCmdInput) {
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