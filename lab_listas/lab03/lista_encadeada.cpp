#include <bits/stdc++.h>
#include "lista_encadeada.hpp"

using namespace std;

LinkedList::LinkedList()
{
    // Constroi o estado inicial da lista
    tail = head = NULL;
}

void LinkedList::push_back(int element)
{
    // Adiciona um novo nó ao fim da lista
    // Complexidade: O(1)

}

void LinkedList::pop_back()
{
    // Remove o ultimo nó da lista
    // Complexidade: O(n)

}

void LinkedList::push_front(int element)
{
    // Adiciona um novo nó no inicio da lista
    // Complexidade: O(1)

}

void LinkedList::pop_front()
{
    // Remove o primeiro nó da lista
    // Complexidade: O(1)

}

void LinkedList::insert(int element, unsigned int index)
{
    // Adiciona um novo nó no indice index da lista
    // Complexidade: O(n)

}

void LinkedList::erase(unsigned int index)
{
    // Remove o nó de indice index da lista
    // Complexidade: O(n)

}

int LinkedList::front()
{
    // Retorna o valor do primeiro nó
    // Complexidade: O(1)

    return -1;
}

int LinkedList::back()
{
    // Retorna o valor do útlimo nó
    // Complexidade: O(1)

    return -1;
}

void LinkedList::clear()
{
    // Remove todos os nós da lista
    // Complexidade: O(n)

}

bool LinkedList::find(int element)
{
    // Procura se existe um nó cujo o valor seja igual ao de element
    // Complexidade: O(n)

    return false;
}

unsigned int LinkedList::size()
{
    // Retorna o número de nós que existem na lista
    // Complexidade: O(n)

    return 0;
}

bool LinkedList::empty()
{
    // Retorna se a lista está vazia ou não
    // Complexidade: O(n)

    return false;
}

void LinkedList::print()
{
    Node1 * node = head;

    cout << "--List Begin [" << head << "]-- Size = " << size() << "\n";

    while(node)
    {
        cout << "(" << node->value << ", " << node->next;
        if (node->next) cout << " [" << node->next->value << "]";
        cout << ")\n";

        node = node->next;
    }

    cout << "--List End [" << tail << "]--\n\n";
}
