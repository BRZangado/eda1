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
    bool continuar = true;
    while(continuar){
      stack<int> trem;
      stack<int> aux;
      stack<int> saida;
      for(i=N;i>0;i--){
        trem.push(i);
      }
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
      for(i = 0; i<N; i++){
        while(!trem.empty() and combinacao[i] > trem.top()) {
          aux.push(trem.top());
          trem.pop();
        }
        if(!trem.empty() and combinacao[i] == trem.top()){
          saida.push(trem.top());
          trem.pop();
        }
        else if(!aux.empty() and combinacao[i] == aux.top()){
          saida.push(aux.top());
          aux.pop();
        }
        else if(!aux.empty() and combinacao[i] < aux.top()){
          break;
        }
      }
      if(saida.size() == N){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
    cout << endl;
  }
  return 0;
}