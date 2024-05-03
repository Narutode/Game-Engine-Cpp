#include "ObjectArena.cpp"

class GameObject
{
public:
	// todo : pleins de propriétés ici
	static GameObject* m_pool;
	static int m_currentIndex;
	static ObjectArena g_Arena;
	int id;

public:
	GameObject() {

	};
	~GameObject();
	static GameObject* Allocate() {
		//ok, si nombre croissant d'objets alloués et peu/pas de déalloc
		return &m_pool[m_currentIndex++];
	}
	static void DestroyPool() {
		delete[] m_pool;
	}

	void* operator new(const size_t size) {
		return g_Arena.Allocate(size);
	}
	void operator delete(void* pointer) {
		// idem code precedent
	}
	static void CreatePool(int count) {
		g_Arena.Initialise(count * sizeof(GameObject));
	}
};