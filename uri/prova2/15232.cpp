#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef struct carro
{
  int h_chegada;
  int h_saida;
}Carro;


int main(){
  int qtdmoto, capacidade;
  while(true){
    cin >> qtdmoto >> capacidade;
    if(qtdmoto == 0 and capacidade == 0){
      break;
    }
    stack<Carro> estacionamento;
    int i;
    bool deu = true;
    for(i = 0; i<qtdmoto; i++){
      int he, hs;
      cin >> he >> hs;
      Carro carro;
      carro.h_chegada = he;
      carro.h_saida = hs;
      if(estacionamento.empty()){
        estacionamento.push(carro);
      }
      while(true){
        if(carro.h_chegada > estacionamento.top().h_saida){
          estacionamento.pop();
        }
        else{
          break;
        }
      }
      if(carro.h_saida > estacionamento.top().h_saida){
        deu = false;
      }
    }
    if(deu){
      cout << "Sim" << endl;
    } else {
      cout << "Nao" << endl;
    }
  }
  return 0;
}