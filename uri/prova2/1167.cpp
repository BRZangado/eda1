#include <iostream>
#include <vector>

using namespace std;

typedef struct person{

  int num;
  string nome;

}Person;

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

    Node * first(){
      if (head){
        if(head->info.num%2==0){
          return head->prev;
        }
        return head->next;
      }
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
        tail = nullptr;
      }
      delete temp;
      if(head){
        head->prev = tail;
        tail->next = head;
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
      auto p = head;
      do{
        cout << p->info << " ";
        p = p->next;
      }while(p != head);
      cout << endl;
    }
    void printb(){
      auto p = tail;
      do{
        cout << p->info << " ";
        p = p->prev;
      }while(p != tail);
      cout << endl;
    }

    Person game2(Node * n, int passos){
      if(_size==1){
        cout << "lalala" << endl;
        cout << n->info.nome << endl;
        return n->info;
      }
      auto p = n;
      int i = 1;
      if(passos%2==0){
        while(i != passos){
          p=p->prev;
          i++;
        }
      } else {
        while(i != passos){
          p=p->next;
          i++;
        }
      }
      p->prev->next = p->next;
      p->next->prev = p->prev;
      passos = p->info.num;
      auto prox = p;
      if(passos%2==0){
        prox=prox->prev;
      } else {
        prox=prox->next;
      }
      cout << _size << endl;
      cout << p->info.nome << endl;
      cout << prox->info.nome << endl;
      delete p;
      _size--;
      game2(prox, passos);
    }

    Person game(bool start, Person parou, int passos){
      if(_size == 1){
        return head->info;
      }
      int i = 0;
      Person p = parou;
      if(start == true){
        passos = head->info.num;
      }
      auto k = head;
      while(k->info.nome != p.nome){
        k=k->next;
      }
      while(i != passos){
        if(passos%2==0){
          k=k->prev;
        } else {
          k=k->next;
        }
        i++;
      }
      int proximos_passos = k->info.num;
      auto temp = k;
      if(proximos_passos%2==0){
        temp = k->prev;
      } else {
        temp = k->next;
      }
      k->prev = k->next;
      k->next->prev = k->prev;
      delete k;
      _size--;
      if(_size == 1){
        head = temp;
        tail = temp;
      }
      return game(false, temp->info, proximos_passos);
    }
};

int main(){

  int N;
  while(true){
    cin >> N;
    if(N == 0){
      break;
    }
    Circular<Person> lista;
    int i;
    for(i = 0; i<N; i++){
      string nome;
      int num;
      cin >> nome >> num;
      Person p;
      p.nome = nome;
      p.num = num;
      lista.push_back(p);
    }
    Person head =  lista.front();
    Person vencedor = lista.game2(lista.first(), head.num);
    cout << vencedor.nome << endl;
    /*
    
    3
    Fa 7
    Fo 9
    G 11
    3
    Fo
    G
    2
    G
    Fa
    lalala
    Fa
    free(): invalid pointer
    Abortado (imagem do núcleo gravada)

    
    */

  }
  

  return 0;
}