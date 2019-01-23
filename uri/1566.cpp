#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int NC, i;
  cin >> NC;

  for(i = 0; i < NC; i++){

    int N, j;
    vector<int> idades;
    cin >> N;

    for(j = 0; j < N; j++){
      int input;
      cin >> input;
      idades.push_back(input);
    }

    stable_sort(idades.begin(), idades.end());
    for(i=0;i<idades.size();i++){
      cout << idades[i] << " ";
    }
    cout << endl;

  }

  return 0;
}