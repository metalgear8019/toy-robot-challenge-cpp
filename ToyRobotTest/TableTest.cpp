#include "pch.h"
#include "../ToyRobot/Position.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/Table.h"

TEST(TableTest, AddRobotTest) {
	Table t;

	Robot r1;
	Robot r2(Position(-5, -7), UNKNOWN);
	Robot r3(1, 2, SOUTH);

	EXPECT_TRUE(!t.IsRobotPlaced());
	EXPECT_EQ(t.GetRobotReference(), nullptr);

	t.PlaceRobot(r1);
	EXPECT_TRUE(t.IsRobotPlaced());
	EXPECT_NE(t.GetRobotReference(), nullptr);
	EXPECT_EQ(t.GetRobotReference()->GetDirection(), NORTH);
	EXPECT_EQ(t.GetRobotReference()->GetPosition().GetX(), 0);
	EXPECT_EQ(t.GetRobotReference()->GetPosition().GetY(), 0);

	t.RemoveRobot();
	EXPECT_TRUE(!t.IsRobotPlaced());
	EXPECT_EQ(t.GetRobotReference(), nullptr);

	t.PlaceRobot(r2);
	EXPECT_TRUE(t.IsRobotPlaced());
	EXPECT_NE(t.GetRobotReference(), nullptr);
	EXPECT_EQ(t.GetRobotReference()->GetDirection(), UNKNOWN);
	EXPECT_EQ(t.GetRobotReference()->GetPosition().GetX(), -5);
	EXPECT_EQ(t.GetRobotReference()->GetPosition().GetY(), -7);

	t.RemoveRobot();
	EXPECT_TRUE(!t.IsRobotPlaced());
	EXPECT_EQ(t.GetRobotReference(), nullptr);

	t.PlaceRobot(r3);
	EXPECT_TRUE(t.IsRobotPlaced());
	EXPECT_NE(t.GetRobotReference(), nullptr);
	EXPECT_EQ(t.GetRobotReference()->GetDirection(), SOUTH);
	EXPECT_EQ(t.GetRobotReference()->GetPosition().GetX(), 1);
	EXPECT_EQ(t.GetRobotReference()->GetPosition().GetY(), 2);
}

TEST(TableTest, BoundaryTest) {
	Table t1(5, 5);
	Table t2(5, 0);

	Position pos1(4, 2);
	Position pos2(0, 0);
	Position pos3(2, 5);
	Position pos4(-1, 3);

	EXPECT_TRUE(t1.IsInBounds(pos1));
	EXPECT_TRUE(t1.IsInBounds(pos2));
	EXPECT_TRUE(!t1.IsInBounds(pos3));
	EXPECT_TRUE(!t1.IsInBounds(pos4));

	EXPECT_TRUE(!t2.IsInBounds(pos1));
	EXPECT_TRUE(!t2.IsInBounds(pos2));
	EXPECT_TRUE(!t2.IsInBounds(pos3));
	EXPECT_TRUE(!t2.IsInBounds(pos4));

	t2.Resize(6, 6);

	EXPECT_TRUE(t2.IsInBounds(pos1));
	EXPECT_TRUE(t2.IsInBounds(pos2));
	EXPECT_TRUE(t2.IsInBounds(pos3));
	EXPECT_TRUE(!t2.IsInBounds(pos4));
}