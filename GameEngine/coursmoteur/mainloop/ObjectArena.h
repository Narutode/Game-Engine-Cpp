#pragma once
#include <cstdint>
#include "GameObject.cpp"

class GameObject; // Forward declaration

class ObjectArena
{
    uint8_t* m_memory;
    uint32_t m_cursor;
    uint32_t m_capacity; // Capacité totale de la mémoire allouée

public:
    void Initialise(uint32_t taille);
    void Destroy();
    GameObject* AllocateGameObject();
};
