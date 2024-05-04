#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "Component.h"
#include <string>
#include <iostream>

class Behavior : public Component {
    std::string script;
    void Update() override {
        std::cout << "[Behavior]" << std::endl;
    };
};

#endif // BEHAVIOR_H