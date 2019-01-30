#include <iostream>
using namespace std;

template<typename T>
class Queue{
  private:
    struct Node{
      T info;
      Node * next;
      Node(T i, Node * n){
        info = i;
        next = n;
      }
    };
    Node * _front, * _back;
    unsigned int _size;
  public:
    Queue(){
      _front = nullptr;
      _back = nullptr;
      _size = 0;
    }
    ~Queue(){
      auto p = _back;
      while(p){
        auto temp = p->next;
        delete p;
        p = temp;
      }
    }
    void push(T i){
      auto n = new Node(i, _back);
      if(_size == 0){
        _front = n;
      }
      _back = n;
      _size++;
    }
    void pop(){
      auto p = _back;
      while(p->next and p->next != _front){
        p = p->next;
      }
      delete _front;
      if(_front == _back){
        _back = _front = nullptr;
      }
      else{
        _front = p;
        _front->next = nullptr;
      }
      _size--;
    }
    void print(){
      auto p = _back;
      while(p){
        cout << p->info << " ";
        p = p->next;
      }
      cout << endl;
    }
    T front(){
      cout << _front->info << endl;
    }
    T back(){
      cout << _back->info << endl;
    }
    unsigned int size(){
      return _size;
    }
};

int main(){

  Queue<int> q;
  q.print();
  q.push(1);
  q.push(2);
  q.push(3);
  q.print();
  cout << endl;
  q.pop();
  q.pop();
  q.print();
  q.~Queue();

  return 0;
}