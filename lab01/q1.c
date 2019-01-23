#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
    int capacity;
    int size;
    int *elements;
}Vector;

Vector create(int capacity){
    Vector v;
    v.capacity = capacity;
    v.size = 0;
    v.elements = (int *) malloc(capacity * sizeof(int));
    printf("Vector criado \n\n");
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

void erase(Vector * vector, int i){
    if(i < vector->size){
        for (int j = i; j <= vector->size; j++){
            vector->elements[j] = vector->elements[j + 1];
        }
        printf("elemento do índice %d excluido \n\n", i);
        vector->size--;
    }
}

int find(Vector * vector, int position){
    if(position < vector->size){
        return vector->elements[position];
    }
}

void clear(Vector * vector){
    free(vector->elements);
    vector->size = 0;
}

int back(Vector * vector){
    int back;
    back = vector->elements[vector->size -1];
    return back;
}

int front(Vector * vector){
    int front;
    front = vector->elements[0];
    return front;
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

void print(Vector* vector)
{
    printf("[ ");
    for(int i = 0; i < size(vector); ++i) {
        printf("%d ", at(vector, i));
    }
    printf(" ]\n\n");
}

int main()
{
    Vector v1 = create(10);

    print(&v1); // vetor vazio
    
    for (int i = 0; i < 15; ++i)
    {
        push_back(&v1, i * 2);     
    }

    print(&v1);
    
    for (int i = 0; i < 3; ++i)
    {
        pop_back(&v1);
    }

    print(&v1);

    for (int i = 0; i < 20; i += 3)
    {
        erase(&v1, i);
    }
    
    print(&v1); 

    for (int i = 0; i < 20; i++)
    {
        erase(&v1, i);
    }

    print(&v1);

    clear(&v1);

    print(&v1);

    for (int i = 0; i < 10; ++i)
    {
        push_back(&v1, i * 3 + 1);
    }

    print(&v1);

    printf("v1[3] = %d\n", at(&v1, 3));
    printf("v1[4] = %d\n", at(&v1, 4));
    printf("v1[6] = %d\n", at(&v1, 6));
    printf("v1[7] = %d\n", at(&v1, 7));
    printf("v size = %d\n", size(&v1));

    printf("\nfront: %d :: back: %d\n", front(&v1), back(&v1));

    destroy(&v1);

    return 0;
}
