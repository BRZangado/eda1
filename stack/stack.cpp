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
    void empilhar(T i){
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
    void desempilhar(){
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
      return top->info;
    }
};

int main(){

  Stack<int> stack;
  stack.print();
  stack.empilhar(1);
  stack.empilhar(2);
  stack.empilhar(3);
  stack.print();
  cout << endl;
  cout << endl;
  stack.desempilhar();
  stack.print();

}
