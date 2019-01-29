#include <iostream>
#include "linked_list.h"

using namespace std;

int main(){

  LinkedList<int> list;

  cout << "Lista vazia? " << (list.empty() ? "Sim" : "Nao") << endl;
  for (int n = 1; n <= 10; ++n){
    list.push_back(n);
  }
  list.pop_back();
  cout << "Tamanho da lista: " << list.size() << endl;
  cout << "Primeiro elemento: " << list.front() << endl;
  cout << "Último elemento: " << list.back() << endl;

  list.~LinkedList();

  return 0;
}