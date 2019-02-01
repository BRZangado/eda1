#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

  int N, K;
  while(true){
    cin >> N >> K;
    if(N == 0 and K == 0){
      break;
    }
    int i;
    stack<int> saida;
    bool deu = true;
    for(i = 0; i<N; i++){
      int horae, horas;
      cin >> horae >> horas;
      if(saida.empty()){
        saida.push(horas);
      }
      else if(horae < saida.top()){
        if(horas < saida.top()){
          saida.push(horas);
        }
      }
      else if(horae > saida.top()){
        saida.pop();
        if(horas < saida.top()){
          saida.push(horas);
        }
        else{
          deu = false;
          break;
        }
      }
    }
    if(saida.size() <= K && deu == true){
      cout << "Sim" << endl;
    } else {
      cout << "Nao" << endl;
    }
  }

  return 0;
}