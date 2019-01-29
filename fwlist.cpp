#include <iostream>
#include <forward_list>

using namespace std;

int main(){

  forward_list<int> lista;
  lista.insert_after(lista.end(), 0);
  lista.insert_after(lista.end(), 1);

  int indice = 0;
  for(int i : lista){
    cout << i << " ";
  }
  cout << endl;

  lista.insert_after(lista.before_begin(), 0);

  for(int i : lista){
    cout << i << " ";
  }
  cout << endl;

  return 0;
}