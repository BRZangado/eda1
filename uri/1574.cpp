#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int T, i;
  cin >> T;
  for(i = 0; i<T; i++){
    int n, j, k, posicao = 0;
    vector<string> options;
    cin >> n;
    for(j = 0; j<n; j++){
      int ps[n];
      string op;
      getline(cin, op);
      if(op == "LEFT"){
        ps[i] = -1;
      }
      else if(op == "RIGHT"){
         ps[i] = 1;
      }
      else{
         int number = stoi(op.substr(8));
         ps[i] = ps[number];
      }
      posicao += ps[i];
    }
    cout << posicao << endl;
  }

  return 0;
}