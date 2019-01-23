#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int feq(vector<int>& v, int value){
  int i, feq = 0;
  for(i=0; i<v.size(); i++){
    cout << "taaqui" << endl;
    if(value == v[i]){
      feq+=1;
      v.erase(v.begin()+i);
    }
  }
  return feq-1;
}

int main(){
  int N, M;
  cin >> N >> M;
  while(N != 0 and M != 0){
    int i, j, req = 0;
    vector<int> biletes;
    for(i=0; i<M; i++){
      int da_vez;
      cin >> da_vez;
      biletes.push_back(da_vez);
    }
    for(j = 0; j < biletes.size(); j++){
      cout << "taaq22222ui" << endl;
      req += feq(biletes, biletes[j]);
    }
    cout << req-1 << endl;
    cin >> N >> M;  
  }
  return 0;
}