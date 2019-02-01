#include <iostream>

using namespace std;

template<typename T>
class Circular {

private:
    struct Node {
        T info;
        Node *prev, *next;

        Node(T i, Node *p, Node *n) : info(i), prev(p), next(n) {}
    };

    Node *head, *tail;
    unsigned int _size;

public:
    Circular(){
      head = nullptr;
      tail = nullptr;
      _size = 0;
    }

    ~Circular() {
      if (head == nullptr){
        return;
      }
      auto p = head;
      do {
          auto next = p->next;
          delete p;
          p = next;
      } while (p != head);
    }

    T front() {
      if (head)
          return head->info;
      else
          throw "Empty list!";
    }

    T back(){
      if (tail)
          return tail->info;
      else
          throw "Empty list!";
    }

    T back2(){
      if (tail)
          return head->next->info;
      else
          throw "Empty list!";
    }

    bool empty() { return head == nullptr; }

    unsigned int size(){
      return _size;
    }

    void push_front(T info){
      auto n = new Node(info, nullptr, head);
      head ? head->prev = n : tail = n;
      head = n;
      head->prev = tail;
      tail->next = head;
      _size++;
    }

    void push_back(T info){
      auto n = new Node(info, tail, nullptr);
      if(tail){
        tail->next = n;
      } else {
        head = n; 
      }
      tail = n;
      tail->next = head;
      head->prev = tail;
      _size++;
    }

    void pop_front(){
      if (!head){
        throw "Lista vazia";
      }
      auto temp = head;
      if(_size > 1){
        head = head->next;
      } else {
        head = nullptr;
      }
      delete temp;
      if(head){
        head->prev = tail;
        tail->next = head;
      } else {
        tail = nullptr;
      }
      _size--;
    }

    void pop_back(){
      if (!tail){
        throw "Lista vazia";
      }
      tail = tail->prev;
      head = head->prev;
      pop_front();
    }

    void insert(T info, int position){
      if(_size == 0){
        push_back(info);
      }
      else{
        if(position == 0){
          push_front(info);
        }
        else if(position == _size-1){
          push_back(info);
        }
        else{
          auto p = head;
          int i = 0;
          while(i != position){
            p=p->next;
            i++;
          }
          auto n = new Node(info, p->prev, p);
          p->prev->next = n;
          p->prev = n;
        }
      }
      _size++;
    }

    void erase(int position){
      if(position == 0){
        pop_front();
      }
      else if(position == _size-1){
        pop_back();
      }
      else if(position >= _size){
        cout << "posicao nao existente" << endl;
      } else {
        int i = 0;
        auto p = head;
        while(i != position){
          p=p->next;
          i++;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        _size--;
      }
    }

    void print(){
      auto p = tail;
      for(int i = 0; i<41; i++){
        p=p->next;
      }
      cout << p->info << endl;
    }
    void printb(){
      auto p = tail;
      do{
        cout << p->info << " ";
        p = p->prev;
      }while(p != tail);
      cout << endl;
    }
};

int main(){

  Circular<int> circular;
  circular.push_back(1);
  circular.push_back(2);
  circular.push_back(3);
  circular.push_back(4);
  circular.push_back(5);
  circular.push_back(6);
  circular.push_back(7);
  circular.print();
  circular.~Circular();

  return 0;
}