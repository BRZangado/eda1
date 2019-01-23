#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  while(true){
    int A, B, C, D;
    bool cruza = false;
    vector<int> intervalo1;
    vector<int> intervalo2;
    cin >> A >> B >> C >> D;
    if(A == 0 and B == 0 and C == 0 and D == 0){
      break;
    }
    else{
      intervalo1.push_back(A);
      intervalo1.push_back(B);
      intervalo2.push_back(C);
      intervalo2.push_back(D);
      stable_sort(intervalo1.begin(), intervalo1.end());
      stable_sort(intervalo2.begin(), intervalo2.end());
      for(int i = intervalo1.front(); i <= intervalo1.back(); i++){
        for(int j = intervalo2.front(); j <= intervalo2.back(); j++ ){
          if(i == j){
            cruza = true;
            break;
          }
        }
      }
      if(cruza == false){
        cout << "Linhas autorizadas" << endl;
      }
      else{
        cout << "Precisamos de novas linhas!" << endl;
      }
    }
  }

  return 0;
}