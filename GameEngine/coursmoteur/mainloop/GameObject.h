#pragma once
#include <cstdint>
#include <string>
class GameObject
{
public:
    int id;
    std::string tag;
    // Ajouter d'autres composants selon les besoins
    static GameObject* m_pool;
    static int m_currentIndex;
    static ObjectArena g_Arena;
    static GameObject* Allocate();
    static void CreatePool(int count);
    static void DestroyPool();
};