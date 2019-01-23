#include <stdio.h>
#include <stdlib.h>

typedef struct vector{

  int capacity;
  int size;
  int * elements;

}Vector;

Vector create(int capacity){
  Vector v;
  v.capacity = capacity;
  v.size = 0;
  v.elements = (int *) malloc(capacity * sizeof(int));
  return v;
}

void destroy (Vector * vector){
    free(vector->elements);
    vector->elements = NULL;
    vector->capacity = 0;
    vector->size = 0;
    printf("Vector destruido \n\n");
}

void push_back(Vector * vector, int element){
    if(vector->size < vector->capacity){
        vector->elements[vector->size++] = element;
        printf("Elemento %d adicionado \n\n", element);
    }
    else{
        printf("Capacidade estourada, realocando... \n\n");
        vector->capacity *= 2;
        vector->elements = (int *) realloc(vector->elements, vector->capacity * sizeof(int));
        vector->elements[vector->size++] = element;
        printf("Elemento %d adicionado \n\n", element);
    }
}

void pop_back(Vector * vector){
    if(vector->size >= 1){
        vector->elements[vector->size--];
        printf("último elemento excluido \n\n");
    }
}

unsigned int size(Vector * vector){
    unsigned int size;
    size = vector->size;
    return size;
}

unsigned int capacity(Vector * vector){
    unsigned int capacity;
    capacity = vector->capacity;
    return capacity;
}

int at(Vector * vector, int i){
    int element;
    element = vector->elements[i];
    return element;
}

int main(){

  Vector v1 = create(10);
  for (int i = 0; i < 15; ++i)
  {
      push_back(&v1, i * 2);     
  }

  for(int i = 0; i<v1.size;i++){
    printf("%d ", v1.elements[i]);
  }


  destroy(&v1);

  return 0;
}