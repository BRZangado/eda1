#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  while(N != 0){
    int pa = 0, pb = 0, i;  
    for(i = 0; i<N; i++){
      int a,b;
      cin >> a >> b;
      if(a > b){
        pa++;
      }
      else if(b > a){
        pb++;
      }
    }
    cout << pa << " " << pb << endl;
    cin >> N;
  }
  return 0;
}