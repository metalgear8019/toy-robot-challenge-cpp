#include "pch.h"
#include "../ToyRobot/Parser.h"
#include <vector>

TEST(ParserTest, PlaceCommandTest) {
	Parser parser;
	EXPECT_EQ(parser.ParseCommand("PLACE 1,1,NORTH"), CMD_PLACE);
	EXPECT_EQ(parser.ParseCommand("PLACE"), CMD_PLACE);
	EXPECT_EQ(parser.ParseCommand("PLACE     "), CMD_PLACE);
	EXPECT_EQ(parser.ParseCommand("PLA CE"), CMD_UNKNOWN);
	EXPECT_EQ(parser.ParseCommand(" PLACE 1,1,NORTH"), CMD_UNKNOWN);
}

TEST(ParserTest, MoveCommandTest) {
	Parser parser;
	EXPECT_EQ(parser.ParseCommand("MOVE"), CMD_MOVE);
	EXPECT_EQ(parser.ParseCommand("MOVE     "), CMD_MOVE);
	EXPECT_EQ(parser.ParseCommand("MOVE 1,1,NORTH"), CMD_MOVE);
	EXPECT_EQ(parser.ParseCommand("MO VE"), CMD_UNKNOWN);
	EXPECT_EQ(parser.ParseCommand(" MOVE"), CMD_UNKNOWN);
}

TEST(ParserTest, LeftCommandTest) {
	Parser parser;
	EXPECT_EQ(parser.ParseCommand("LEFT"), CMD_LEFT);
	EXPECT_EQ(parser.ParseCommand("LEFT     "), CMD_LEFT);
	EXPECT_EQ(parser.ParseCommand("LEFT 1,1,NORTH"), CMD_LEFT);
	EXPECT_EQ(parser.ParseCommand("LE FT"), CMD_UNKNOWN);
	EXPECT_EQ(parser.ParseCommand(" LEFT"), CMD_UNKNOWN);
}

TEST(ParserTest, RightCommandTest) {
	Parser parser;
	EXPECT_EQ(parser.ParseCommand("RIGHT"), CMD_RIGHT);
	EXPECT_EQ(parser.ParseCommand("RIGHT     "), CMD_RIGHT);
	EXPECT_EQ(parser.ParseCommand("RIGHT 1,1,NORTH"), CMD_RIGHT);
	EXPECT_EQ(parser.ParseCommand("RI GHT"), CMD_UNKNOWN);
	EXPECT_EQ(parser.ParseCommand(" RIGHT"), CMD_UNKNOWN);
}

TEST(ParserTest, ReportCommandTest) {
	Parser parser;
	EXPECT_EQ(parser.ParseCommand("REPORT"), CMD_REPORT);
	EXPECT_EQ(parser.ParseCommand("REPORT     "), CMD_REPORT);
	EXPECT_EQ(parser.ParseCommand("REPORT 1,1,NORTH"), CMD_REPORT);
	EXPECT_EQ(parser.ParseCommand("REP ORT"), CMD_UNKNOWN);
	EXPECT_EQ(parser.ParseCommand(" REPORT"), CMD_UNKNOWN);
}

TEST(ParserTest, RemoveWhitespaceTest) {
	Parser parser;
	EXPECT_EQ(parser.RemoveLeadingAndTrailingWhitespaces("    test      "), "test");
	EXPECT_EQ(parser.RemoveLeadingAndTrailingWhitespaces("    test"), "test");
	EXPECT_EQ(parser.RemoveLeadingAndTrailingWhitespaces("test      "), "test");
	EXPECT_EQ(parser.RemoveLeadingAndTrailingWhitespaces("    t e s t      "), "t e s t");
	EXPECT_EQ(parser.RemoveLeadingAndTrailingWhitespaces("    t    est      "), "t    est");
	EXPECT_EQ(parser.RemoveLeadingAndTrailingWhitespaces("         "), "");
}

TEST(ParserTest, SplitStringsTest) {
	Parser parser;
	auto arrComma = parser.SplitInputs("1234, 22213, 1239048129034, 10923w180234", ',');
	auto arrX = parser.SplitInputs("helloWoolxsayGoodbyexashOfTomorrowx ", 'x');

	EXPECT_EQ(arrComma.size(), 4);
	EXPECT_EQ(arrX.size(), 4);

	EXPECT_EQ(arrComma[0], "1234");
	EXPECT_EQ(arrComma[1], " 22213");
	EXPECT_EQ(arrComma[2], " 1239048129034");
	EXPECT_EQ(arrComma[3], " 10923w180234");

	EXPECT_EQ(arrX[0], "helloWool");
	EXPECT_EQ(arrX[1], "sayGoodbye");
	EXPECT_EQ(arrX[2], "ashOfTomorrow");
	EXPECT_EQ(arrX[3], " ");
}

TEST(ParserTest, ParseDirectionTest) {
	Parser parser;

	Direction dir1 = UNKNOWN;
	Direction dir2 = UNKNOWN;
	Direction dir3 = UNKNOWN;
	Direction dir4 = UNKNOWN;
	Direction dir5 = NORTH;
	Direction dir6 = NORTH;

	EXPECT_EQ(parser.ParseDirection(dir1, "NORTH"), true);
	EXPECT_EQ(parser.ParseDirection(dir2, "EAST"), true);
	EXPECT_EQ(parser.ParseDirection(dir3, "WEST"), true);
	EXPECT_EQ(parser.ParseDirection(dir4, "SOUTH"), true);
	EXPECT_EQ(parser.ParseDirection(dir5, ""), false);
	EXPECT_EQ(parser.ParseDirection(dir6, "QWERTY"), false);

	EXPECT_EQ(dir1, NORTH);
	EXPECT_EQ(dir2, EAST);
	EXPECT_EQ(dir3, WEST);
	EXPECT_EQ(dir4, SOUTH);
	EXPECT_EQ(dir5, UNKNOWN);
	EXPECT_EQ(dir6, UNKNOWN);
}

TEST(ParserTest, ParsePositionTest) {
	Parser parser;

	Position pos1;
	Position pos2;
	Position pos3;

	EXPECT_EQ(parser.ParsePosition(pos1, "1", "2"), true);
	EXPECT_EQ(parser.ParsePosition(pos2, "-52", "502"), true);
	EXPECT_EQ(parser.ParsePosition(pos3, "   12", "24    "), true);

	EXPECT_EQ(pos1.GetX(), 1);
	EXPECT_EQ(pos1.GetY(), 2);
	EXPECT_EQ(pos2.GetX(), -52);
	EXPECT_EQ(pos2.GetY(), 502);
	EXPECT_EQ(pos3.GetX(), 12);
	EXPECT_EQ(pos3.GetY(), 24);
}