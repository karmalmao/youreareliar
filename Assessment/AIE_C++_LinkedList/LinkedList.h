#include <iostream>

template<class T>
class LinkedList
{
public:
	struct Node
	{
		T value;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	struct Iterator
	{
		Node* node = nullptr;

		// Constructors
		Iterator() : node(nullptr) {}
		Iterator(Node* node) : node(node) {}

		// Increment operators
		Iterator& operator ++ () { return Next(); }
		Iterator operator ++ (int) { return Next(); }

		//begin and end


		// Decrement operators
		Iterator operator -- () { return Prev(); }
		Iterator operator -- (int) { return Prev(); }

		// Equality chek operators
		bool operator == (const Iterator& rhs) { return node == rhs.node; }
		bool operator != (const Iterator& rhs) { return node != rhs.node; }

		// Dereference operators
		T& operator * () { return node->value; }
		T* operator -> () { return &node->value; }

		// Move to the next value
		Iterator& Next()
		{
			if (node != nullptr)
				node = node->next;

			return *this;
		}

		// move to the previous value
		Iterator& Prev()
		{
			if (node != nullptr)
				node = node->prev;

			return *this;
		}
	};

	LinkedList()
	{
	}

	~LinkedList()
	{
	}

	void PushBack(T value)
	{
		Node* n = new Node();
		n->value = value;
		if (m_first != nullptr && m_last != nullptr)
		{
			n->prev = m_last;
			m_last->next = n;
			m_last = n;
			m_count++;
		}
		else
		{

			m_first = n;
			m_last = n;
			m_count++;
		}
	}
	void PopBack()
	{
		Node* n = new Node();
		if (m_first != nullptr)
		{
			n = m_last;
			if (m_last->prev != nullptr)
			{
				m_last->prev->next = nullptr;
			}
			m_last = m_last->prev;
			delete n;
		}
		m_count--;
	}
	void PushFront(T value)
	{
		Node* n = new Node();
		n->value = value;
		if (m_first != nullptr && m_last != nullptr)
		{
			n->next = m_first;
			m_first->prev = n;
			m_first = n;
			m_count++;
		}
		else
		{
			m_first = n;
			m_last = n;
			m_count++;
		}

	}
	void PopFront()
	{
		Node* n = new Node();
		if (m_first != nullptr)
		{
			n = m_first;
			if (m_first->next != nullptr)
			{
				m_first->next->prev = nullptr;
			}
			m_first = m_first->next;
			delete n;
		}
		m_count--;
	}

	Iterator Insert(Iterator iter, const T& value)
	{
		Node* nodeA = iter.node;

		Node* newNodeB = new Node();
		Node* newNodeC = nodeA->next;

		if (iter.node == m_first)
		{
			PushFront(value);
		}
		if (iter.node == m_last)
		{
			PushBack(value);
		}
		else
		{
			nodeA->next = newNodeB;newNodeB->prev = nodeA;

			newNodeB->next = newNodeC;newNodeC->prev = newNodeB;
			m_count++;
		}
		return Iterator(newNodeB);
	}
	Iterator Remove(Iterator iter)
	{
		Node* node = iter.node;

		if (iter.node == m_first)
		{
			PopFront();
		}
		if (iter.node == m_last)
		{
			PopBack();
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;

			delete node;
			m_count--;
		}
		return Iterator(iter.node->next);
	}

	void Sort()
	{

	}
	void Clear()
	{
		Node* prevNode;
		LinkedList<T>::Node* newNode = m_last;
		while (newNode != nullptr)
		{
			prevNode = newNode->prev;
			delete newNode;
			newNode = prevNode;
		}
		m_first = nullptr;
		m_last = nullptr;
		m_count = 0;

	}
	Iterator Search(const T& value)
	{

	}
	unsigned int Count()
	{
		return m_count;
	}
	bool IsEmpty()
	{
		return m_first == nullptr && m_last == nullptr;
	}

	Node* FirstNode() { return m_first; }
	Node* LastNode() { return m_last; }

	Iterator begin() { return Iterator(m_first); }
	Iterator end() { return Iterator(nullptr); }
	LinkedList(std::initializer_list<T> list)
	{
		for (auto iter = list.begin(); iter != list.end(); iter++)
			PushBack(*iter);
	}
protected:
private:
	Node* m_first = nullptr;
	Node* m_last = nullptr;
};