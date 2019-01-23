#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  unsigned int N, i;
  cin >> N;
  vector<int> pares;
  vector<int> impares;
  vector<int> total;

  for(i = 0; i<N; i++){
    int input;
    cin >> input;
    if(input % 2 == 0){
      pares.push_back(input);
    }
    else{
      impares.push_back(input);
    }
  }

  stable_sort(pares.begin(), pares.end());
  stable_sort(impares.begin(), impares.end(), greater<int>());

  for(i = 0; i<pares.size(); i++){
    total.push_back(pares[i]);
  }
  for(i = 0; i<impares.size(); i++){
    total.push_back(impares[i]);
  }

  for(i = 0; i<total.size(); i++){
    cout << total[i] << endl;
  }


  return 0;
}