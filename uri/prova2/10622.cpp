#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(){

  int N;
  while(true){
    cin >> N;
    if(N == 0){
      break;
    }
    stack<int> trem;
    stack<int> aux;
    stack<int> saida;
    int i;
    for(i = N; i>0; i--){
      trem.push(i);
    }
    vector<int> combinacao;
    bool deu = true;
    for(i = 0; i<N; i++){
      int vagao;
      cin >> vagao;
      combinacao.push_back(vagao);
    }
    for(i = 0; i<N; i++){
      while(!trem.empty() and combinacao[i] > trem.top()) {
        aux.push(trem.top());
        trem.pop();
      }
      if(!trem.empty() and combinacao[i] == trem.top()){
        saida.push(trem.top());
        trem.pop();
      }
      if(!aux.empty() and combinacao[i] == aux.top()){
        saida.push(aux.top());
        aux.pop();
      }
      if(!aux.empty() and combinacao[i] < aux.top()){
        deu = false;
        break;
      }
    }

    if(deu){
      cout << "deu" << endl;
    } else {
      cout << "n deu" << endl;
    }

  }

  return 0;
}