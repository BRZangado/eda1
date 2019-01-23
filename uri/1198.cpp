#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bsort(vector<int> & v){
  int N = v.size();
  int i;
  bool updated;
  do{
    updated = false;
    for(i = 1; i<N; i++){
      if(v[i-1] > v[i]){
        swap(v[i-1], v[i]);
        updated = true;
      }
    }
  }while(updated);
}

int main(){

  int a, b;
  while(cin >> a >> b){
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    bsort(v);
    cout << v[1] - v[0] << endl;
  }

  return 0;
}