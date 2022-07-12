#include "pch.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/Position.h"

TEST(RobotTest, ConstructorTest) {
	Robot r1;
	Robot r2(Position(-5, -7), UNKNOWN);
	Robot r3(1, 2, SOUTH);

	EXPECT_EQ(r1.GetPosition().GetX(), 0);
	EXPECT_EQ(r1.GetPosition().GetY(), 0);
	EXPECT_EQ(r1.GetDirection(), NORTH);
	EXPECT_EQ(r2.GetPosition().GetX(), -5);
	EXPECT_EQ(r2.GetPosition().GetY(), -7);
	EXPECT_EQ(r2.GetDirection(), UNKNOWN);
	EXPECT_EQ(r3.GetPosition().GetX(), 1);
	EXPECT_EQ(r3.GetPosition().GetY(), 2);
	EXPECT_EQ(r3.GetDirection(), SOUTH);
}

TEST(RobotTest, ToStringTest) {
	Robot r1(-5, -7, UNKNOWN);
	Robot r2(1, 2, SOUTH);
	Robot r3(1024, 552, WEST);
	Robot r4(21, -22, EAST);
	Robot r5;

	EXPECT_EQ(r1.ToString(), "-5,-7 UNKNOWN");
	EXPECT_EQ(r2.ToString(), "1,2 SOUTH");
	EXPECT_EQ(r3.ToString(), "1024,552 WEST");
	EXPECT_EQ(r4.ToString(), "21,-22 EAST");
	EXPECT_EQ(r5.ToString(), "0,0 NORTH");
}

TEST(RobotTest, FaceLeftTest) {
	Robot r1(1, 1, UNKNOWN);
	Robot r2(1, 1, SOUTH);

	r1.FaceLeft();
	r2.FaceLeft();

	EXPECT_EQ(r1.GetDirection(), UNKNOWN);
	EXPECT_EQ(r2.GetDirection(), EAST);

	r1.FaceLeft();
	r1.FaceLeft();
	r2.FaceLeft();
	r2.FaceLeft();

	EXPECT_EQ(r1.GetDirection(), UNKNOWN);
	EXPECT_EQ(r2.GetDirection(), WEST);
}

TEST(RobotTest, FaceRightTest) {
	Robot r1(1, 1, UNKNOWN);
	Robot r2(1, 1, SOUTH);

	r1.FaceRight();
	r2.FaceRight();

	EXPECT_EQ(r1.GetDirection(), UNKNOWN);
	EXPECT_EQ(r2.GetDirection(), WEST);

	r1.FaceRight();
	r1.FaceRight();
	r2.FaceRight();
	r2.FaceRight();

	EXPECT_EQ(r1.GetDirection(), UNKNOWN);
	EXPECT_EQ(r2.GetDirection(), EAST);
}