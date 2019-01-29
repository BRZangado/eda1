#ifndef LISTA_DUPLA_HPP
#define LISTA_DUPLA_HPP

struct Node2 {
    int value;
    Node2 * next;
    Node2 * prev;
};

class DoubleLinkedList {
public:
    Node2 * head;
    Node2 * tail;

    DoubleLinkedList();

    void push_back(int element);
    void pop_back();

    void push_front(int element);
    void pop_front();

    void insert(int element, unsigned int index);
    void erase(unsigned int index);

    int front();
    int back();

    void clear();

    bool find(int element);

    unsigned int size();
    bool empty();

    void print();
};

#endif

