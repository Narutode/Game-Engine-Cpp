#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include <iostream>

class Transform : public Component {
private:
    float x, y, z; // Coordonnées de transformation

public:
    // Constructeur
    Transform(float x, float y, float z) : x(x), y(y), z(z) {}
    void Update() override {
        std::cout << "[Transform] " << x << ", " << y << ", " << z << std::endl;
    };
};

#endif // TRANSFORM_H