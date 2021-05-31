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
        }
        else
        {

            m_first = n;
            m_last = n;
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
        }
        else
        {
            m_first = n;
            m_last = n;
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
    }

    void PrePrint(Node* n)
    {
        PrePrint(n->next);
        PrePrint(n->prev);
        std::cout << n->value << std::endl;
    }
    void PostPrint(Node* n)
    {
        std::cout << n->value << std::endl;
        PostPrint(n->next);
        PostPrint(n->prev);
    }

    void Sort()
    {

    }
    void Clear()
    {
        
        for (int i = 0; i < 4; i++)
        {

        }
    }
    void Search(const T& value)
    {

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