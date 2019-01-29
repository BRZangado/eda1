#ifndef LIST_H
#define LIST_H

template<typename T>
class LinkedList{
  private:
    struct Node{
      T info;
      Node * next;
      Node(T i, Node * n){
        info = i;
        next = n;
      };
    };

    Node * tail;
    Node * head;
    unsigned int _size;
    
  public:

    LinkedList(){
      tail = nullptr;
      head = nullptr;
      _size = 0;
    }
    ~LinkedList(){
      auto p = head;
      while(p){
        auto temp = p->next;
        delete p;
        p = temp;
      }
    }

    void push_front(T info){
      auto n = new Node(info, head);
      if(!head){
        tail = n;
      }
      head = n;
      _size++;
    }
    void push_back(T info){
      auto n = new Node(info, nullptr);
      if(tail){
        tail->next = n;
      } else{
        head = n;
      }
      tail = n;
      _size++;
    }
    void pop_back(){
      auto p = head;
      while(p->next and p->next != tail){
        p = p->next;
      }
      delete tail;
      if(tail == head){
        head = tail = nullptr;
      }
      else{
        tail = p;
        tail->next = nullptr;
      }
      _size--;
    }
    
    void pop_front(){
      auto p = head;
      head = head->next;
      delete p;
      if(head){
        tail = tail;
      }
      else{
        tail = nullptr;
      }
      _size--;
    }

    T front(){
      if(head){
        return head->info;
      } else {
        throw "Empty List!!!";
      }
    }
    T back(){
      if(tail){
        return tail->info;
      } else {
        throw "Empty List!!!";
      }
    }
    bool empty(){
      if (_size == 0){
        return true;
      } else {
        return false;
      }
    }
    unsigned int size(){
      return _size;
    }
};

#endif