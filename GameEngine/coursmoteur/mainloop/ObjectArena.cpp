#include "ObjectArena.h"
#include "GameObject.h"
#include <iostream>

void ObjectArena::Initialise(uint32_t taille) {
    m_memory = new uint8_t[taille];
    m_cursor = 0;
    m_capacity = taille;
    std::cout << "[Object arena] init" << std::endl;
}

void ObjectArena::Destroy() {
    delete[] m_memory;
}

GameObject* ObjectArena::AllocateGameObject() {
    if (m_cursor + sizeof(GameObject) > m_capacity) {
        // Gestion d'une capacité insuffisante : Vous pouvez choisir de lever une exception ou de gérer autrement cette situation.
        return nullptr;
    }

    GameObject* data = reinterpret_cast<GameObject*>(&m_memory[m_cursor]);
    m_cursor += sizeof(GameObject);
    new (data) GameObject(); // Utilisation de placement new pour appeler le constructeur
    return data;
}
