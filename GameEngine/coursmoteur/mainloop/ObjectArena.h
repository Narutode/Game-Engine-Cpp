#ifndef OBJECTARENA_H
#define OBJECTARENA_H

#include <cstdint>

// Déclaration avancée de la classe GameObject pour éviter l'inclusion cyclique
class GameObject;

class ObjectArena
{
public:

    uint8_t* m_memory;
    uint32_t m_cursor;
    uint32_t m_capacity; // Capacité totale de la mémoire allouée

    void Initialise(uint32_t taille);
    void Destroy();
    GameObject* AllocateGameObject();
    void DeallocateObject(GameObject* go);
};

#endif //OBJECTARENA_H