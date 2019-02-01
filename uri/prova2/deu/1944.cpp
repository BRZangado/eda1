#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){

  int N, i, cont = 0;
  cin >> N;
  stack<char> letras;
  for(i = 1; i<=N; i++){
    if(letras.size() == 0){
      letras.push('F');
      letras.push('A');
      letras.push('C');
      letras.push('E');
    }
    char a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<char> proximas;
    proximas.push_back(a);
    proximas.push_back(b);
    proximas.push_back(c);
    proximas.push_back(d);
    int j, c2=0;
    stack<char> teste = letras;
    for(j = 0; j<4; j++){
      if(proximas[j] == teste.top()){
        teste.pop();
        c2++;
      }
      else{
        break;
      }
    }
    if(c2 == 4){
      letras.pop();
      letras.pop();
      letras.pop();
      letras.pop();
      cont++;
    }
    else{
      letras.push(a);
      letras.push(b);
      letras.push(c);
      letras.push(d);
    }
  }

  cout << cont << endl;


  return 0;
}