#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  while(true){
    int N, M;
    cin >> N >> M;
    if(N == 0 and M == 0){
      break;
    }
    int i;
    vector<int>bilhetes;
    vector<int>achou;
    for(i = 0; i<M; i++){
      int a;
      cin >> a;
      if(find(bilhetes.begin(),bilhetes.end(), a) != bilhetes.end()){
        if(find(achou.begin(),achou.end(), a) == achou.end()){
          achou.push_back(a);
        }
      }
      bilhetes.push_back(a);
    }
    cout << achou.size() << endl;
  }
  return 0;
}