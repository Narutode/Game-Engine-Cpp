#pragma once

#include <cstdint>
#include <string>
#include "ObjectArena.h"
#include <vector>
#include "Component.h"

class GameObject
{
public:
    int id;
    std::string tag;
    std::vector<Component*> components;
    static GameObject* m_pool;
    static int m_currentIndex;
    static ObjectArena g_Arena;
    GameObject(std::string tag) : id(m_currentIndex), tag(tag) {};
    GameObject() {};
    void AddComponent(Component* comp);
    static GameObject* Allocate();
    static void CreatePool(int count);
    static void DestroyPool();
};