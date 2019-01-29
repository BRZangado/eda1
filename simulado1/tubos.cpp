#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tubo{
  int id;
  int qtd;
}Tubo;

bool compare(const Tubo tubo1, const Tubo tubo2){
  if(tubo1.qtd > tubo2.qtd){
    return true;
  }
  else if(tubo1.qtd == tubo2.qtd){
    if(tubo1.id > tubo2.id){
      return true;
    }
    else{
      return false;
    }
  }
  else if(tubo1.qtd < tubo2.qtd){
    return false;
  }
}

int main(){

  int N;
  cin >> N;
  for(int i = 0; i<N; i++){
    int M;
    vector<Tubo> tubos;
    vector<Tubo> tubos_encontrados;
    vector<Tubo> tubos_final;
    cin >> M;
    for(int j = 0; j<M; j++){
      int id;
      cin >> id;
      Tubo tubo;
      tubo.id = id;
      tubos.push_back(tubo);
    }
    for(int j = 0; j<tubos.size(); j++){
      if(find(tubos_encontrados.begin(), tubos_encontrados.end(), tubos[j]) == tubos_encontrados.end()){
        int freq = count(tubos.begin(), tubos.end(), tubos[i]);
        tubos_encontrados.push_back(tubos[i]);
        tubos[i].qtd = freq;
        tubos_final.push_back(tubos[i]);
      }
    }

    stable_sort(tubos_final.begin(),tubos_final.end(), compare);

    for(int j = 0; j<tubos_final.size(); j++){
      cout << "ID: " << tubos_final[i].id << " QTD: " << tubos_final[i].qtd;
    }

  }

  return 0;

}