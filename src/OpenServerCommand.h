//
// Created by ziv_t on 12/14/18.
//

#ifndef STEPPING_STONE1_OPENSERVERCOMMAND_H
#define STEPPING_STONE1_OPENSERVERCOMMAND_H

#include <string>
#include "Command.h"

class OpenServerCommand:public Command{
    std::vector<std::string> DirectVar = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                                    "/instrumentation/altimeter/indicated-altitude-ft",
                                    "/instrumentation/altimeter/pressure-alt-ft",
                                    "/instrumentation/attitude-indicator/indicated-pitch-deg",
                                    "/instrumentation/attitude-indicator/indicated-roll-deg",
                                    "/instrumentation/attitude-indicator/internal-pitch-deg",
                                    "/instrumentation/attitude-indicator/internal-roll-deg",
                                    "/instrumentation/encoder/indicated-altitude-ft",
                                    "/instrumentation/encoder/pressure-alt-ft",
                                    "/instrumentation/gps/indicated-altitude-ft",
                                    "/instrumentation/gps/indicated-ground-speed-kt",
                                    "/instrumentation/gps/indicated-vertical-speed",
                                    "/instrumentation/heading-indicator/indicated-heading-deg",
                                    "/instrumentation/magnetic-compass/indicated-heading-deg",
                                    "/instrumentation/slip-skid-ball/indicated-slip-skid",
                                    "/instrumentation/turn-indicator/indicated-turn-rate",
                                    "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                    "/controls/flight/aileron",
                                    "/controls/flight/elevator",
                                    "/controls/flight/rudder",
                                    "/controls/flight/flaps",
                                    "/controls/engines/engine/throttle",
                                    "/engines/engine/rpm"};
public:
    void execute() override;

    ~OpenServerCommand() override;

    std::string stringify() override;

    void addMaps(mapHandler &mapHandler1) override;

    void connectAndUpdate(int sleepTime, int sockeNum);

    int findIndexFromString(std::string const &path) const;

};


#endif //STEPPING_STONE1_OPENSERVERCOMMAND_H
