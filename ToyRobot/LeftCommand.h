#pragma once

#ifndef LEFTCOMMAND_H
#define LEFTCOMMAND_H

#include "Command.h"
#include "Table.h"

class LeftCommand : public Command
{
public:
	bool Execute() const override;
	LeftCommand(Table* table) { m_table = table; }
private:
    Table* m_table;
};

#endif