#include "GameObject.h"
#include <string>
#include <vector>
#include <iostream>
class Scene {
public:
    //std::vector<GameObject*> m_gameObjects;

    ObjectArena* m_gameObjects;

    Scene() {
        m_gameObjects = new ObjectArena();
        m_gameObjects->Initialise(sizeof(GameObject)*4);
    }

    GameObject* Scene::AddGameObject() {
        std::cout << "[Scene] add game object"<< std::endl;
        return m_gameObjects->AllocateGameObject();
    }

    void Scene::RemoveGameObject(GameObject* gameObject) {
        m_gameObjects->DeallocateObject(gameObject);
        std::cout << "[Scene] delete game object " << gameObject->tag << std::endl;
        /*
        // Recherche et suppression de l'objet du vecteur
        auto it = std::find(m_gameObjects.begin(), m_gameObjects.end(), gameObject);
        if (it != m_gameObjects.end()) {
            m_gameObjects.erase(it);
        }
        */
    }

    std::vector<GameObject*> Scene::FindObjectsWithTag(const std::string& tag) {
        std::vector<GameObject*> objectsWithTag;
        uint8_t* currentMemory = m_gameObjects->m_memory;
        uint8_t* endMemory = m_gameObjects->m_memory + m_gameObjects->m_cursor;

        while (currentMemory < endMemory) {
            GameObject* gameObject = reinterpret_cast<GameObject*>(currentMemory);
            if (gameObject->tag == tag) {
                objectsWithTag.push_back(gameObject);
            }
            currentMemory += sizeof(GameObject);
        }

        return objectsWithTag;
    }

    void UpdateGameObject() {
        uint8_t* currentMemory = m_gameObjects->m_memory;
        uint8_t* endMemory = m_gameObjects->m_memory + m_gameObjects->m_cursor;

        while (currentMemory < endMemory) {
            GameObject* gameObject = reinterpret_cast<GameObject*>(currentMemory);
            gameObject->UpdateComponents();
            currentMemory += sizeof(GameObject);
        }
    }
};