#include "pch.h"
#include "../ToyRobot/Position.h"

TEST(PositionTest, ConstructorTest) {
	Position testPos(1, 2);

	EXPECT_EQ(testPos.GetX(), 1);
	EXPECT_EQ(testPos.GetY(), 2);
}

TEST(PositionTest, DefaultConstructorTest) {
	Position testPos;

	EXPECT_EQ(testPos.GetX(), 0);
	EXPECT_EQ(testPos.GetY(), 0);
}

TEST(PositionTest, MoveNorthTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::NORTH);

	EXPECT_EQ(testPos.GetX(), 456);
	EXPECT_EQ(testPos.GetY(), 226);
}

TEST(PositionTest, MoveEastTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::EAST);

	EXPECT_EQ(testPos.GetX(), 457);
	EXPECT_EQ(testPos.GetY(), 227);
}

TEST(PositionTest, MoveWestTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::WEST);

	EXPECT_EQ(testPos.GetX(), 455);
	EXPECT_EQ(testPos.GetY(), 227);
}

TEST(PositionTest, MoveSouthTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::SOUTH);

	EXPECT_EQ(testPos.GetX(), 456);
	EXPECT_EQ(testPos.GetY(), 228);
}

TEST(PositionTest, MoveUnknownTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::UNKNOWN);

	EXPECT_EQ(testPos.GetX(), 456);
	EXPECT_EQ(testPos.GetY(), 227);
}

TEST(PositionTest, MoveNorthVariableTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::NORTH, 500);

	EXPECT_EQ(testPos.GetX(), 456);
	EXPECT_EQ(testPos.GetY(), -273);
}

TEST(PositionTest, MoveEastVariableTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::EAST, 500);

	EXPECT_EQ(testPos.GetX(), 956);
	EXPECT_EQ(testPos.GetY(), 227);
}

TEST(PositionTest, MoveWestVariableTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::WEST, 500);

	EXPECT_EQ(testPos.GetX(), -44);
	EXPECT_EQ(testPos.GetY(), 227);
}

TEST(PositionTest, MoveSouthVariableTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::SOUTH, 500);

	EXPECT_EQ(testPos.GetX(), 456);
	EXPECT_EQ(testPos.GetY(), 727);
}

TEST(PositionTest, MoveUnknownVariableTest) {
	Position testPos(456, 227);
	testPos.MoveTowards(DIRECTION::UNKNOWN, 500);

	EXPECT_EQ(testPos.GetX(), 456);
	EXPECT_EQ(testPos.GetY(), 227);
}