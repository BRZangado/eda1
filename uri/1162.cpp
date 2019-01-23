#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trocas(vector<int> v){
  int N = v.size();
  int i, swaps = 0;
  bool updated;

  do{
    updated = false;
    for(i=1; i<N; i++){
      if(v[i - 1] > v[i]){
        swaps++;
        swap(v[i-1], v[i]);
        updated = true;
      }
    }
  }while(updated);

  return swaps;
}

int main(){
  int N, i;
  cin >> N;

  for(i = 0; i < N; i++){
    int L, j;
    cin >> L;
    vector<int> vagoes;
    for(j = 0; j<L; j++){
      int input;
      cin >> input;
      vagoes.push_back(input);
    }
    int swaps = trocas(vagoes);
    cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
  }

  return 0;
}