#pragma once

class Command
{
public:
	virtual ~Command() {}
	virtual bool Execute() const = 0;
};
