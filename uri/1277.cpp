#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int T, i;
  cin >> T;
  for(i = 0; i<T; i++){
    int num_alunos, j;
    vector<string> alunos;
    vector<string> afreq;
    vector<string> alunos_rep;
    cin >> num_alunos;
    for(j=0; j<num_alunos; j++){
      string nome;
      cin >> nome;
      alunos.push_back(nome);
    }
    for(j=0; j<alunos.size(); j++){
      string freq;
      cin >> freq;
      afreq.push_back(freq);
    }
    for(j = 0; j<alunos.size(); j++){
      string presenca = afreq[j];
      float pre = 0, total = 0, porc = 0;
      for(int k =0; k < presenca.size(); k++){
        if(presenca.substr[k] == "P"){
          pre++;
          total++;
        }
        else if(presenca.substr[k] == "A"){
          total++;
        }
      }
      porc = (total/pre)*100.0;
      cout << porc << endl;
    }

  }

  return 0;
}