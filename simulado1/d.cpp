#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int N;
  while(true){
    cin >> N;
    if(N == 0){
      break;
    }
    vector<int> candidatos;
    int n_candidatos = 0;
    int maior = 0;
    int candidato_maior;
    int menor = 0;
    bool empatado;
    for(int i = 0; i<N; i++){
      int candidato;
      cin >> candidato;
      if (find(candidatos.begin(), candidatos.end(), candidato) == candidatos.end() ){
        n_candidatos++;
      }
      candidatos.push_back(candidato);
    }

    for(int i = 0; i<candidatos.size(); i++){
      int freq = count(candidatos.begin(), candidatos.end(), candidatos[i]); 
      if(freq > maior){
        maior = freq;
        candidato_maior = candidatos[i];
      }
      else if(freq == maior){
        if(candidato_maior > candidatos[i]){
          candidato_maior = candidatos[i];
        }
      }
    }

    cout << "Mais votado foi " << candidato_maior << " com " << maior << " votos" << endl;
    cout << "No total foram " << n_candidatos << " candidatos" << endl;
    cout << endl;
  }

  return 0;
}