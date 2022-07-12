#pragma once

#ifndef RIGHTCOMMAND_H
#define RIGHTCOMMAND_H

#include "Command.h"
#include "Table.h"

class RightCommand : public Command
{
public:
	bool Execute() const override;
	RightCommand(Table* table) { m_table = table; }
private:
    Table* m_table;
};

#endif