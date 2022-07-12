#pragma once

#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"
#include "Table.h"

class MoveCommand : public Command
{
public:

	bool Execute() const override;
	MoveCommand(Table* table) { m_table = table; }
private:
    Table* m_table;
};

#endif