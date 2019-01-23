#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsort(vector<int> vector){
  int N = vector.size();
  int i, posicoes_originais[N];
  bool updated;
  int contagem = 0;
  do{
    updated = false;
    for(i = 0; i<N;i++){
      posicoes_originais[i]=vector[i];
      if(vector[i-1] > vector[i]){
        swap(vector[i-1],vector[i]);
        updated = true;
      }
    }
  }while(updated);

  for(i=0;i<N;i++){
    if(vector[i] == posicoes_originais[i]){
      contagem++;
    }
  }
  return contagem;
}

int main(){

  int N, i, conta = 0;
  cin >> N;

  for(i=0; i<N;i++){

    int M, j;
    vector<int> vector;
    cin >> M;

    for(j = 0; j < M; j++){
      int input;
      cin >> input;
      vector.push_back(input);
    }

    int contagem = bsort(vector);
    cout << contagem << endl;

  }

  return 0;
}