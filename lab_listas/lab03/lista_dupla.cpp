#include <bits/stdc++.h>
#include "lista_dupla.hpp"

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
    // Constroi o estado inicial da lista
    tail = head = NULL;
}

void DoubleLinkedList::push_back(int element)
{
    // Adiciona um novo nó ao fim da lista
    // Complexidade: O(1)

}

void DoubleLinkedList::pop_back()
{
    // Remove o ultimo nó da lista
    // Complexidade: O(1)

}

void DoubleLinkedList::push_front(int element)
{
    // Adiciona um novo nó no inicio da lista
    // Complexidade: O(1)

}

void DoubleLinkedList::pop_front()
{
    // Remove o primeiro nó da lista
    // Complexidade: O(1)

}

void DoubleLinkedList::insert(int element, unsigned int index)
{
    // Adiciona um novo nó no indice index da lista
    // Complexidade: O(n)

}

void DoubleLinkedList::erase(unsigned int index)
{
    // Remove o nó de indice index da lista
    // Complexidade: O(n)

}

int DoubleLinkedList::front()
{
    // Retorna o valor do primeiro nó
    // Complexidade: O(1)

    return -1;
}

int DoubleLinkedList::back()
{
    // Retorna o valor do útlimo nó
    // Complexidade: O(1)

    return -1;
}

void DoubleLinkedList::clear()
{
    // Remove todos os nós da lista
    // Complexidade: O(n)

}

bool DoubleLinkedList::find(int element)
{
    // Procura se existe um nó cujo o valor seja igual ao de element
    // Complexidade: O(n)

    return false;
}

unsigned int DoubleLinkedList::size()
{
    // Retorna o número de nós que existem na lista
    // Complexidade: O(n)

    return 0;
}

bool DoubleLinkedList::empty()
{
    // Retorna se a lista está vazia ou não
    // Complexidade: O(n)

    return false;
}

void DoubleLinkedList::print()
{
    Node2 * node = head;

    cout << "--List Begin [" << head << "]-- Size = " << size() << "\n";

    while(node)
    {
        cout << "(";

        cout << node->prev;
        if (node->prev) cout << " [" << node->prev->value << "]";

        cout << ", " << node->value << ", ";

        cout << node->next;
        if (node->next) cout << " [" << node->next->value << "]";

        cout << ")\n";

        node = node->next;
    }

    cout << "--List End [" << tail << "]--\n\n";
}

