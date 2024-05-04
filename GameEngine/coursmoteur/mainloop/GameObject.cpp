#include "GameObject.h"
#include "ObjectArena.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <functional>

//GameObject* GameObject::m_pool = nullptr;
//GameObject::m_currentIndex = 0;
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
    std::cout << "[GameObject] add component" << std::endl;
    components.push_back(comp);
}

void UpdateComponentThread(std::vector<Component*>& components, size_t start, size_t end) {
    for (size_t i = start; i < end; ++i) {
        components[i]->Update();
    }
}

void GameObject::setTag(std::string tag) {
    this->tag = tag;
}

void GameObject::UpdateComponents() {
    std::cout << "[GameObject] update components" << std::endl;

    // Nombre de threads à utiliser (vous pouvez ajuster ce nombre en fonction de votre système)
    const size_t numThreads = std::thread::hardware_concurrency();

    // Vecteur pour stocker les threads
    std::vector<std::thread> threads(numThreads);

    // Vecteur pour stocker les index de début et de fin de chaque "batch" de composants
    std::vector<size_t> batchStart(numThreads + 1);

    // Calculer les index de début et de fin de chaque "batch" de composants
    const size_t batchSize = components.size() / numThreads;
    for (size_t i = 0; i < numThreads; ++i) {
        batchStart[i] = i * batchSize;
    }
    batchStart[numThreads] = components.size();

    // Lancer les threads
    for (size_t i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(UpdateComponentThread, std::ref(components), batchStart[i], batchStart[i + 1]);
    }

    // Attendre que tous les threads se terminent
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}