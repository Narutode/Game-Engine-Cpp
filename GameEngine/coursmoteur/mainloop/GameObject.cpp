#include "GameObject.h"
#include "ObjectArena.h"

void GameObject::CreatePool(int count) {
    g_Arena.Initialise(count * sizeof(GameObject));
}

void GameObject::DestroyPool() {
    g_Arena.Destroy();
}

GameObject* GameObject::Allocate() {
    return g_Arena.AllocateGameObject();
}