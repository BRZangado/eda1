#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void order(vector<string> & nomes, vector<int> & idades){
  bool updated;
  do{

    updated = false;
    for(int i = 0; i < nomes.size(); i++){
      if(idades[i-1] > idades[i]){
        updated = true;
        swap(idades[i-1], idades[i]);
        swap(nomes[i-1], nomes[i]);
      }
    }

  }while(updated);
}

int main(){

  int N;
  while(true){
    cin >> N;
    if(N == 0){
      break;
    }
    vector<string> nomes;
    vector<int> idades;
    for(int i = 0; i<N; i++){
      string nome;
      int idade;
      cin >> nome;
      cin >> idade;
      nomes.push_back(nome);
      idades.push_back(idade);
    }
    order(nomes, idades);
    for(int i = 0; i<nomes.size(); i++){
      cout << nomes[i] << endl;
    }
  }

  return 0;
}