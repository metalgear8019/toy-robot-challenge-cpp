#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H

/// <summary>
/// Direction
///		A collection of possible direction definitions in a given plane.
/// 
/// Notes:
///		(1) Can add "UP" and "DOWN" for z-axis in a 3D plane.
/// </summary>
const enum DIRECTION {
	NORTH,
	EAST,
	WEST,
	SOUTH,
	UNKNOWN,
};
typedef int Direction;

#endif