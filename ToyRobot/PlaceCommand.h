#pragma once

#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include "Command.h"
#include "Table.h"

class PlaceCommand : public Command
{
public:
	bool Execute() const override;
	PlaceCommand(Table* table, std::string args) {
		m_table = table;
		m_args = args;
	}
private:
    Table* m_table;
    std::string m_args;
};

#endif