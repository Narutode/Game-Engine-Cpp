// Définition de la classe Transform qui hérite de Component
#include "Component.cpp";
class Transform : public Component {
private:
    float x, y, z; // Coordonnées de transformation

public:
    // Constructeur
    Transform(float x, float y, float z) : x(x), y(y), z(z) {}
};