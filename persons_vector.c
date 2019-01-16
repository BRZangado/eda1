#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char nome[500];
    int idade;
}Person;

typedef struct vector{
    int capacity;
    int size;
    Person *people;
}Vector;

Vector create(int capacity){
    Vector v;
    v.capacity = capacity;
    v.size = 0;
    v.people = (Person *) malloc(capacity * sizeof(Person));
    printf("Vector criado \n\n");
    return v;
}

void push_back(Vector * vector, Person p){
    if(vector->size < vector->capacity){
        vector->people[vector->size++] = p;
        printf("Elemento %s adicionado \n\n", vector->people[vector->size-1].nome);
    }
    else{
        printf("Capacidade estourada\n\n");
    }
}

int main() {
    int n_pessoas = 0;

    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n_pessoas);

    Vector v1 = create(n_pessoas);

    Person p;
    strcpy(p.nome, "Pedrin");
    p.idade=20;

    push_back(&v1, p);



    return 0;
}
