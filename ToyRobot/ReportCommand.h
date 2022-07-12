#pragma once

#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include "Command.h"
#include "Table.h"

class ReportCommand : public Command
{
public:
	bool Execute() const override;
	ReportCommand(Table* table) { m_table = table; }
private:
    Table* m_table;
};

#endif