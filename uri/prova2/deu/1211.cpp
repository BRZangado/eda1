#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int N;
  while(scanf("%d", &N) != EOF){
    if(N == 0){
      continue;
    }
    vector<string> numbers;
    int i, j;
    int count = 0;
    for(i = 0; i<N; i++){
      string line;
      cin >> line;
      numbers.push_back(line);
    }
    stable_sort(numbers.begin(), numbers.end());
    for(i = 1; i<N; i++){
      queue<char> s;
      for(char& c : numbers[i-1]){
        s.push(c);
      }
      for(char& c : numbers[i]){
        if(c == s.front()){
          s.pop();
          count++;
        }
        else{
          break;
        }
      }
    }
    cout << count << endl;
  }

  return 0;
}
