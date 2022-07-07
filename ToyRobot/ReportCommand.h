#pragma once

#include "Command.h"
#include "Robot.h"

class ReportCommand : public Command
{
    ReportCommand(const Robot& r) {
        m_robot = r;
    }

    bool Execute() const override {
        // TODO: Route output to display buffer
        return true;
    }
private:
    Robot m_robot;
};

