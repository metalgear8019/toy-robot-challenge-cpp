#pragma once

#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
	virtual ~Command() {}
	virtual bool Execute() const = 0;
};

#endif