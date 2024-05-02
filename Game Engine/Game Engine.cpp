// Game Engine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <cassert>
struct GameObject
{
    float x, y, z;
    int id;
    GameObject() { std::cout << "constructeur" << std::endl; };
    ~GameObject() { std::cout << "destructeur" << std::endl; };

    static GameObject* pool;
    static uint32_t poolElementCount;
    static uint32_t poolCapacity;

    void* operator new(const size_t size) {
        assert(poolElementCount + 1 < poolCapacity);
        void* pointer = &(pool[poolElementCount++]);
        return ::operator new (pointer) GameObject
    }
};

// placement new, permet de construire un object a une adresse presise en passee en parametre
#include <new>
int main()
{
    using byte = unsigned char;
    byte* data = new byte[1024 * 1024];
    //appelle le constructeur 
    GameObject* go =  new(data)GameObject;
    //appelle le destructeur
    go->~GameObject();
    delete go;
    delete[] data;
    std::cout << "Hello World!\n";
}

