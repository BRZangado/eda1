#ifndef LIST_H
#define LIST_H

template<typename T>
class List{

private:
  struct Node{
    T info;
    Node *next;

    Node(const T& i, Node *n){
      info = i;
      next = n;
    }
  };

  Node *head;
  Node *tail;
  unsigned long _size;

public:
  List(){
    head = nullptr;
    tail = nullptr;
    _size = 0;
  }
  ~List(){
    auto p = head;
    while(p){
      auto next = p->next;
      delete p;
      p = next;
    }
  }
  void push_front(const T& info){
    auto n = new Node(info, head);
    if(head){
      tail = tail;
    }
    else{
      tail = n;
    }
    head = n;
    _size++;
  }
  void push_back(const T& info){
    auto n = new Node(info, nullptr);
    if(tail){
      tail->next = n;
    }
    else{
      head = n;
    }
    tail = n;
    _size++;
  }
  void pop_front(){
    if(!head){
      throw "Empty List!!";
    }
    else{
      auto temp = head;
      head = head->next;
      delete temp;
      if(head){
        tail = tail;
      }
      else{
        tail = nullptr;
      }
      _size--;
    }
  }
  void pop_back(){
    if(!head){
      throw "Empty List!!";
    }
    else{
      auto prev = head;
      while(prev->next and prev->next != tail){
        prev = prev->next;
      }
      delete tail;
      if(tail == head){
        head = tail;
        tail = nullptr;
      }
      else{
        tail = prev;
        tail->next = nullptr;
      }
      _size--;
    }
  }
  const T& front() const{
    if(head){
      return head->info;
    }
    else{
      throw "Empty List!!";
    }
  }
  const T& back() const{
    if(tail){
      return tail->info;
    }
    else{
      throw "Empty List!!";
    }
  }

  bool empty() const{
    if(head){
      return false;
    }
    return true;
  }

  unsigned long size() const{
    return _size;
  }

};

#endif