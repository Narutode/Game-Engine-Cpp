
#include "GameObject.h"

class GameObjectFactory {
public:
    static GameObject* CreateGameObject(const std::string& tag) {
        GameObject* gameObject = new GameObject(tag);
        // Initialisation suppl�mentaire si n�cessaire
        return gameObject;
    }
};