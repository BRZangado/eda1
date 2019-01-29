#include <bits/stdc++.h>
#include "lista_encadeada.hpp"
#include "lista_dupla.hpp"
#include "lista_circular.hpp"

using namespace std;

int main()
{
    LinkedList lista;

    lista.push_back(4);
    lista.push_back(8);
    lista.push_back(15);
    lista.push_back(16);
    lista.push_back(23);
    lista.push_back(42);

    lista.print();

    lista.pop_back();
    lista.print();

    lista.pop_back();
    lista.pop_back();
    lista.pop_back();
    lista.pop_back();
    lista.pop_back();
    lista.pop_back();

    lista.print();

    lista.push_front(4);
    lista.push_front(8);
    lista.push_front(15);
    lista.push_front(16);
    lista.push_front(23);
    lista.push_front(42);

    lista.print();

    lista.pop_front();
    lista.print();

    lista.pop_front();
    lista.pop_front();
    lista.pop_front();
    lista.pop_front();
    lista.pop_front();

    lista.print();

    lista.push_front(4);
    lista.push_front(8);
    lista.push_front(15);
    lista.push_front(16);
    lista.push_front(23);
    lista.push_front(42);

    lista.print();

    lista.erase(2);
    lista.print();
    lista.erase(3);
    lista.print();
    lista.erase(0);
    lista.print();
    lista.erase(lista.size() - 1);
    lista.print();
    lista.erase(100);

    lista.insert(33, 0);
    lista.insert(31, lista.size());
    lista.print();
    lista.insert(34, 1);
    lista.insert(35, 2);
    lista.insert(37, 5);
    lista.insert(36, 100);
    lista.print();

    if (lista.empty()) cout << "Vazia\n";
    else cout << "Nao vazia\n";

    if (lista.find(37)) cout << "Achei 37!\n";
    else cout << "Nao achei 37\n";

    if (lista.find(36)) cout << "Achei 36!\n";
    else cout << "Nao achei 36\n";

    cout << lista.front() << " :: " << lista.back() << "\n";

    lista.clear();
    lista.print();

    if (lista.empty()) cout << "Vazia\n";
    else cout << "Nao vazia\n";

    if (lista.find(37)) cout << "Achei 37!\n";
    else cout << "Nao achei 37\n";

    cout << "###########################################################\n";

    DoubleLinkedList lista2;

    lista2.push_back(4);
    lista2.push_back(8);
    lista2.push_back(15);
    lista2.push_back(16);
    lista2.push_back(23);
    lista2.push_back(42);

    lista2.print();

    lista2.pop_back();
    lista2.print();

    lista2.pop_back();
    lista2.pop_back();
    lista2.pop_back();
    lista2.pop_back();
    lista2.pop_back();
    lista2.pop_back();

    lista2.print();

    lista2.push_front(4);
    lista2.push_front(8);
    lista2.push_front(15);
    lista2.push_front(16);
    lista2.push_front(23);
    lista2.push_front(42);

    lista2.print();

    lista2.pop_front();
    lista2.print();

    lista2.pop_front();
    lista2.pop_front();
    lista2.pop_front();
    lista2.pop_front();
    lista2.pop_front();

    lista2.print();

    lista2.push_front(4);
    lista2.push_front(8);
    lista2.push_front(15);
    lista2.push_front(16);
    lista2.push_front(23);
    lista2.push_front(42);

    lista2.print();

    lista2.erase(2);
    lista2.print();
    lista2.erase(3);
    lista2.print();
    lista2.erase(0);
    lista2.print();
    lista2.erase(lista2.size() - 1);
    lista2.print();
    lista2.erase(100);

    lista2.insert(33, 0);
    lista2.insert(31, lista2.size());
    lista2.print();
    lista2.insert(34, 1);
    lista2.insert(35, 2);
    lista2.insert(37, 5);
    lista2.insert(36, 100);
    lista2.print();

    if (lista2.empty()) cout << "Vazia\n";
    else cout << "Nao vazia\n";

    if (lista2.find(37)) cout << "Achei 37!\n";
    else cout << "Nao achei 37\n";

    if (lista2.find(36)) cout << "Achei 36!\n";
    else cout << "Nao achei 36\n";

    cout << lista2.front() << " :: " << lista2.back() << "\n";

    lista2.clear();
    lista2.print();

    if (lista2.empty()) cout << "Vazia\n";
    else cout << "Nao vazia\n";

    if (lista2.find(37)) cout << "Achei 37!\n";
    else cout << "Nao achei 37\n";

    cout << "###########################################################\n";

    CircularList lista3;

    lista3.push(4);
    lista3.push(8);
    lista3.push(15);
    lista3.push(16);
    lista3.push(23);
    lista3.push(42);

    lista3.print();

    lista3.pop();
    lista3.print();

    lista3.pop();
    lista3.pop();
    lista3.pop();
    lista3.pop();
    lista3.pop();
    lista3.pop();

    lista3.print();

    lista3.push(4);
    lista3.push(8);
    lista3.push(15);
    lista3.push(37);
    lista3.push(23);
    lista3.push(42);

    lista3.print();

    if (lista3.empty()) cout << "Vazia\n";
    else cout << "Nao vazia\n";

    if (lista3.find(37)) cout << "Achei 37!\n";
    else cout << "Nao achei 37\n";

    if (lista3.find(36)) cout << "Achei 36!\n";
    else cout << "Nao achei 36\n";

    lista3.clear();
    lista3.print();

    if (lista3.empty()) cout << "Vazia\n";
    else cout << "Nao vazia\n";

    if (lista3.find(37)) cout << "Achei 37!\n";
    else cout << "Nao achei 37\n";

    return 0;
}
