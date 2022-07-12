#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H

const enum DIRECTION {
	UNKNOWN,
	NORTH,
	EAST,
	WEST,
	SOUTH,
};
typedef int Direction;

const enum COMMAND_CODE {
	CMD_UNKNOWN,
	CMD_PLACE,
	CMD_MOVE,
	CMD_LEFT,
	CMD_RIGHT,
	CMD_REPORT,
	CMD_EXIT,
};
typedef int CommandCode;

#endif