#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  string line;
  while(getline(cin, line)){
    stack<char> s;
    for(char& c : line) {
      if(c == '(' or c == ')'){
        if(!s.empty()){
          if(c == ')' and s.top() == '('){
            s.pop();
          } else {
            s.push(c);
          }
        } else {
          s.push(c);
        }
      }
    }
    if(s.size() == 0){
      cout << "correct" << endl;
    } else {
      cout << "incorrect" << endl;
    }
  }

  return 0;
}