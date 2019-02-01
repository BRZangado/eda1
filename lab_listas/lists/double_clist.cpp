#include <iostream>
using namespace std;

template<typename T>
class List {
public:
    List(){
      head = nullptr;
      tail = nullptr;
      _size = 0;
    }

    ~List() {
        auto p = head;
        while (p){
          auto next = p->next;
          delete p;
          p = next;
        }
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

    bool empty() const { return head == nullptr; }

    unsigned int size(){
      return _size;
    }

    void push_front(T info){
        auto n = new Node(info, nullptr, head);
        head ? head->prev = n : tail = n;
        head = n;
        _size++;
    }

    void push_back(T info){
      auto n = new Node(info, tail, nullptr);
      tail ? tail->next = n : head = n; 
      tail = n;
      _size++;
    }

    void pop_front(){
      if (!head)
          throw "Lista vazia";
      auto temp = head;
      head = head->next;
      delete temp;
      head ? head->prev = nullptr : tail = nullptr;
      _size--;
    }

    void pop_back(){
      if (!tail)
          throw "Lista vazia";
      auto temp = tail;
      tail = tail->prev;
      delete temp;        
      tail ? tail->next = nullptr : head = nullptr;
      _size--;
    }

    void insert(T info, int position){
      if(_size == 0){
        return;
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
            p = p->next;
            i++;
          }
          auto node = new Node(info, p->prev, p);
          p->prev->next = node;
          p->prev = node;
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
        while(p){
          if(i == position){
            auto prev = head;
            while(prev->next != p){
              prev = prev->next;
            }
            prev->next = p->next;
            if(p->next){
              p->next->prev = prev;
            }
            delete p;
            break;
          }
          else{
            p = p->next;
            i++;
            continue;
          }
        }
        _size--;
      }
    }

    void print(){
      auto p = head;
      while(p){
        cout << p->info << " ";
        p = p->next;
      }
      cout << endl;
    }
    void printb(){
      auto p = tail;
      while(p){
        cout << p->info << " ";
        p = p->prev;
      }
      cout << endl;
    }
    T fw(int passos){
      auto p = head;
      while(passos != 0){
        if(!p->next){
          p = head;
          break;
        }
        p = p->next;
        passos--;
      }
      return p->info;
    }

    T bw(int passos){
      auto p = tail;
      while(passos != 0){
        if(!p->prev){
          p = tail;
          break;
        }
        p = p->prev;
        passos--;
      }
      return p->info;
    }

private:
    struct Node {
        T info;
        Node *prev, *next;

        Node(const T& i, Node *p, Node *n) : info(i), prev(p), next(n) {}
    };

    Node *head, *tail;
    unsigned int _size;
};