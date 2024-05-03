#include "GameObject.h"
#include "ObjectArena.h"

GameObject* GameObject::m_pool = nullptr;
int GameObject::m_currentIndex = 0;
ObjectArena GameObject::g_Arena; // Déclaration de g_Arena ici

void GameObject::CreatePool(int count) {
    g_Arena.Initialise(count * sizeof(GameObject));
}

void GameObject::DestroyPool() {
    g_Arena.Destroy();
}

GameObject* GameObject::Allocate() {
    return g_Arena.AllocateGameObject();
}

void GameObject::AddComponent(Component* comp) {
    components.push_back(comp);
}