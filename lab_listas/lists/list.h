#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template<typename T>
class List{
  private:
    struct Node{
      T data;
      Node * next;
      Node(T info, Node * n){
        data = info;
        next = n;
      }
    };
    Node * tail, *head;
    unsigned int _size;
  public:
    List(){
      tail = nullptr;
      head = nullptr;
      _size = 0;
    }
    ~List(){
      auto p = head;
      while(p){
        auto n = p->next;
        delete p;
        p = n;
      }
    }
    void push_front(T data){
      auto node = new Node(data, head);
      if(!head){
        tail = node;
      }
      head = node;
      _size++;
    }
    void push_back(T data){
      auto node = new Node(data, nullptr);
      if(tail){
        tail->next = node;
      }
      else{
        head = node;
      }
      tail = node;
      _size++;
    }
    void pop_back(){
      if(_size == 0){
        throw "empty list";
      }
      else if(_size == 1){
        delete tail;
        tail = nullptr;
        head = nullptr;
      }
      else{
        auto p = head;
        while(p->next and p->next != tail){
          p = p->next;
        }
        p->next = nullptr;
        delete tail;
        tail = p;
        _size--;
      }
    }
    void pop_front(){
      auto p = head;
      head = head->next;
      delete p;
      if(!head){
        tail = nullptr;
      }
      _size--;
    }
    T front(){
      if(head){
        return head->data;
      }
      throw "Empty List";
    }
    T back(){
      if(tail){
        return tail->data;
      }
      throw "Empty List";
    }
    unsigned int size(){
      return _size;
    }
    void print(){
      auto p = head;
      while(p){
        cout << p->data << " ";
        p = p->next;
      }
      cout << endl;
    }
};

#endif