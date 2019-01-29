#ifndef LISTA_CRICULAR_HPP
#define LISTA_CRICULAR_HPP

struct Node3 {
    int value;
    Node3 * next;
};

class CircularList {
public:
    Node3 * head;

    CircularList();

    void push(int element);
    void pop();

    void clear();

    bool find(int element);

    unsigned int size();
    bool empty();

    void print();
};

#endif

