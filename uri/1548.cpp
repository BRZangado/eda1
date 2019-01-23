#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int N, i, conta = 0;
  cin >> N;

  for(i=0; i<N;i++){

    int M, j;
    vector<int> vector, vector2;
    cin >> M;

    for(j = 0; j < M; j++){
      int input;
      cin >> input;
      vector.push_back(input);
      vector2.push_back(input);
    }

    stable_sort(vector.begin(), vector.end(), greater<int>());

    for(int j = 0; j<vector.size(); j++){
      if(vector[j] == vector2[j]){
        conta++;
      }
      cout << vector[j] << " " << vector2[j] << endl;
    }

    cout << conta << endl;

  }

  return 0;
}