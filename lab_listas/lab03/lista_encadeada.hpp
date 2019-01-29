#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

struct Node1 {
    int value;
    Node1 * next;
};

class LinkedList {
public:
    Node1 * head;
    Node1 * tail;

    LinkedList();

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
