#include <iostream>
using namespace std;

template<typename T>
class Stack{

  private:
    struct Node{
      T info;
      Node * prev;
      Node(T i, Node * n){
        info = i;
        prev = n;
      }
    };
    unsigned int _size;
    Node * top;
  
  public:
    Stack(){
      top = nullptr;
      _size = 0;
    }
    void push(T i){
      if(_size == 0){
        auto n = new Node(i, nullptr);
        top = n;
      }
      else{
        auto n = new Node(i, top);
        top = n;
      }
      _size++;
    }
    void pop(){
      if(_size == 0){
        throw "Empty Stack!!!";
      }
      else{
        auto temp = top;
        top = top->prev;
        delete temp;
        _size--;
      }
    }
    void print(){
      auto t = top;
      while(t){
        cout << t->info << endl;
        t = t->prev;
      }
    }
    unsigned int size(){
      return _size;
    }
    T _top(){
      cout << top->info << endl;
    }
};

int main(){

  Stack<int> stack;
  stack.print();
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.print();
  cout << endl;
  cout << endl;
  stack.pop();
  stack.print();
  cout << endl;
  cout << endl;
  stack._top();

  return 0;
}
