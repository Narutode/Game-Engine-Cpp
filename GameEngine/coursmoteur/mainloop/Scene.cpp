#include "GameObject.h"
#include <string>
#include <vector>
#include <iostream>
class Scene {
public:
    std::vector<GameObject*> m_gameObjects;

    void Scene::AddGameObject(GameObject* gameObject) {
        std::cout << "[Scene] add game object " << gameObject->tag << std::endl;
        m_gameObjects.push_back(gameObject);
    }

    void Scene::RemoveGameObject(GameObject* gameObject) {
        std::cout << "[Scene] delete game object " << gameObject->tag << std::endl;
        // Recherche et suppression de l'objet du vecteur
        auto it = std::find(m_gameObjects.begin(), m_gameObjects.end(), gameObject);
        if (it != m_gameObjects.end()) {
            m_gameObjects.erase(it);
        }
    }

    std::vector<GameObject*> Scene::FindObjectsWithTag(const std::string& tag) {
        std::vector<GameObject*> objectsWithTag;
        for (auto gameObject : m_gameObjects) {
            // Vérifie si l'objet a le tag spécifié
            if (gameObject->tag == tag) {
                objectsWithTag.push_back(gameObject);
            }
        }
        return objectsWithTag;
    }
};