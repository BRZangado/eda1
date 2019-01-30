#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  string line;
  int N;
  cin >> N;
  while(N > 0){
    stack<char> s;
    string line;
    cin >> line;
    int count = 0;
    for(char& c : line) {
      if(c == '<' or c == '>'){
        if(!s.empty()){
          if(c == '>' and s.top() == '<'){
            s.pop();
            count++;
          } else {
            s.push(c);
          }
        } else {
          s.push(c);
        }
      }
    }
    cout << count << endl;
    N--;
  }

  return 0;
}