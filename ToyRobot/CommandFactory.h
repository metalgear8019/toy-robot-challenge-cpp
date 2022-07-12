#pragma once

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Constants.h"
#include "Command.h"
#include "Table.h"

class CommandFactory
{
public:
	Command* CreateCommand(CommandCode, Table* , std::string);
};

#endif