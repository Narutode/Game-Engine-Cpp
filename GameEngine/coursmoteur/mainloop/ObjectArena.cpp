#include <cstdint>
#include "GameObject.cpp"
class ObjectArena
{
	// allocateur lineaire (linear allocator)
	// tips: on peut desallouer le contenu en remettant le curseur a zero
	uint8_t* m_memory;
	uint32_t m_cursor; // position du premier octet libre
public:
	void Initialise(uint32_t taille) {
		m_memory = new uint8_t[taille];
	}
	void Destroy() {
		delete[] m_memory;
	}
	GameObject* ObjectArena::AllocateGameObject()
	{
		GameObject* data = (GameObject*)&m_memory[m_cursor];
		m_cursor += sizeof(GameObject);
		// placement new
		// utile lorsque la zone mémoire existe déjà et
		// que l'on souhaite appeler explicitement le constructeur
		::operator new(sizeof(GameObject), data);
		return data;
	}

};