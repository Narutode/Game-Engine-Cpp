#pragma once

#include <cstdint>
#include <string>
#include "ObjectArena.h" // Assurez-vous d'inclure ObjectArena.h ici

class GameObject
{
public:
    int id;
    std::string tag;
    // Ajouter d'autres composants selon les besoins
    static GameObject* m_pool;
    static int m_currentIndex;
    static ObjectArena g_Arena; // Assurez-vous que ObjectArena est déclaré avant son utilisation
    static GameObject* Allocate();
    static void CreatePool(int count);
    static void DestroyPool();
};
