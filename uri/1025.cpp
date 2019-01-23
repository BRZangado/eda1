#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int N, Q, i, casen = 1;

  while(true){

    cin >> N >> Q;

    if(N == 0 and Q == 0){
      break;
    }

    vector<int> pedras;
    vector<int> respostas;

    for(i = 0; i < N; i++){
      int input;
      cin >> input;
      pedras.push_back(input);
    }
    for(i = 0; i < Q; i++){
      int input;
      cin >> input;
      respostas.push_back(input);
    }

    stable_sort(pedras.begin(), pedras.end());

    cout << "CASE# " << casen << ":" << endl;

    for(i = 0; i < Q; i++){
      auto a = find(pedras.begin(), pedras.end(), respostas[i]);
      if(a != pedras.end()){
        cout << respostas[i] << " found at " << distance(pedras.begin(), a) + 1 << endl;
      }
      else{
        cout << respostas[i] << " not found" << endl;
      }
    }

    casen++;
  }

  return 0;
}