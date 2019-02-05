#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main(){
  int N;
  while(true){
    cin >> N;
    if(N == 0){
      break;
    }
    int i;
    stack<int> trem;
    stack<int> aux;
    stack<int> saida;
    for(i=N;i>0;i--){
      trem.push(i);
    }
    bool continuar = true;
    while(continuar){
      vector<int> combinacao;
      int j;
      for(j = 0; j<N; j++){
        int a;
        cin >> a;
        if(a == 0){
          continuar = false;
          break;
        }
        combinacao.push_back(a);
      }
      if(!continuar){
        break;
      }
      bool deu = true;
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
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}