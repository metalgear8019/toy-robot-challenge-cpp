#pragma once

#include <iostream>
#include <string>

#include "CommandFactory.h"
#include "Command.h"
#include "Parser.h"
#include "Table.h"

int main()
{
    bool isTerminated = false;
    std::string strInput;
    Command* cmd = nullptr;

    // Function callers and parsers init
    CommandFactory cmdFactory;
    Parser parser;

    // Declare grid/table with a 5x5 size
    Table table(5, 5);

    // Display available commands
    std::cout
        << "Available commands:" << std::endl
        << " (1) PLACE X,Y,DIRECTION" << std::endl
        << " (2) MOVE" << std::endl
        << " (2) LEFT" << std::endl
        << " (3) RIGHT" << std::endl
        << " (4) REPORT" << std::endl
        << "** Use EXIT command to exit application." << std::endl << std::endl;

    do {
        // Read command input here
        try {
            std::getline(std::cin, strInput);
            
            auto cmdCode = parser.ParseCommand(strInput);
            if (cmdCode != CMD_EXIT) {
                cmd = cmdFactory.CreateCommand(cmdCode, &table, strInput);
                if (nullptr != cmd) {
                    cmd->Execute();
                    delete cmd;
                }
            } else { isTerminated = true; }
        } catch (std::exception&) { isTerminated = true; }

    } while (!isTerminated);

}