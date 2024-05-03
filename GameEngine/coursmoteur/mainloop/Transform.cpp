// D�finition de la classe Transform qui h�rite de Component
#include "Component.cpp";
class Transform : public Component {
private:
    float x, y, z; // Coordonn�es de transformation

public:
    // Constructeur
    Transform(float x, float y, float z) : x(x), y(y), z(z) {}
};