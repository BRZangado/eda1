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

    for(j = 0; j<idades.size(); j++){
      if(j == idades.size()-1){
        cout << idades[j] << endl;
      }
      else{
        cout << idades[j] << " ";
      }
    }


  }

  return 0;
}