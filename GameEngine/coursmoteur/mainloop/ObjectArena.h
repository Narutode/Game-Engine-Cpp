#pragma once

#include <cstdint>

// D�claration avanc�e de la classe GameObject pour �viter l'inclusion cyclique
class GameObject;

class ObjectArena
{
    uint8_t* m_memory;
    uint32_t m_cursor;
    uint32_t m_capacity; // Capacit� totale de la m�moire allou�e

public:
    void Initialise(uint32_t taille);
    void Destroy();
    GameObject* AllocateGameObject();
};
