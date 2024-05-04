#include "Transform.h"
#include "Behavior.h"
enum class ComponentType {
    Transform,
    Behavior
};
class ComponentFactory {
public:
    static Component* CreateComponent(ComponentType type) {
        switch (type) {
        case ComponentType::Transform:
            return new Transform(0,0,0);
        case ComponentType::Behavior:
            return new Behavior();
            // Ajoutez d'autres types de composants au besoin
        default:
            return nullptr;
        }
    }
};