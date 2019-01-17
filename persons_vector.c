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

void destroy (Vector * vector){
    free(vector->people);
    vector->people = NULL;
    vector->capacity = 0;
    vector->size = 0;
    printf("Vector destruido \n\n");
}

void push_back(Vector * vector, Person p){
    if(vector->size < vector->capacity){
        vector->people[vector->size++] = p;
        printf("Elemento %s adicionado \n\n", vector->people[vector->size-1].nome);
    }
    else{
        printf("Capacidade estourada, realocando espaço....\n\n");
        vector->capacity *= 2;
        vector->people = (Person *) realloc(vector->people, vector->capacity * sizeof(Person));
        vector->people[vector->size++] = p;
        printf("Elemento %s adicionado \n\n", vector->people[vector->size-1].nome);
    }
}

void pop_back(Vector * vector){
    if(vector->size > 0){
        vector->people[vector->size--];
    }
}

void erase(Vector * vector, int position){
    if(position < vector->size){
        for(int i = position; i < vector->size; i++){
            vector->people[i] = vector->people[i + 1];
        }
        vector->size--;
    }
}

void clear(Vector * vector){
    free(vector->people);
    vector->size = 0;
}

Person back(Vector * vector){
    Person back;
    back = vector->people[vector->size - 1];
    return back;
}

Person front(Vector * vector){
    Person front;
    front = vector->people[0];
    return front;
}

Person at(Vector * vector, int position){
    Person p;
    p = vector->people[position];
    return p;
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

void print(Vector * vector){
    if(vector->size > 0){
        for(int i = 0; i<size(vector); i++){
            Person p = at(vector, i);
            printf("Nome: %s \n Idade: %d \n", p.nome, p.idade);
        }
    }
    else{
        printf("Nenhuma pessoa cadastrada no momento\n\n");
    }
}

void register_person(Vector * vector){

    Person p;
    char nome[100];
    int idade;

    printf("Digite o nome \n");
    scanf("%s", nome);
    printf("Digite a idade \n");
    scanf("%d", &idade);

    strcpy(p.nome, nome);
    p.idade = idade;
    push_back(vector, p);
}

int main() {
    int n_pessoas = 0;

    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n_pessoas);
    Vector v1 = create(n_pessoas);

    int opt;

    while(1){

        printf("Escolha uma das opções: \n\n");
        printf("1 - Inserir pessoa\n");
        printf("2 - Excluir última pessoa\n");
        printf("3 - Excluir pessoa na posicao x\n");
        printf("4 - Ver primeira pessoa do vector\n");
        printf("5 - Ver última pessoa do vector\n");
        printf("6 - Ver todas as pessoas cadastradas\n");
        printf("7 - Excluir todos os registros\n");
        printf("0 - Sair\n\n");

        scanf("%d", &opt);

        if(opt == 0){
            break;
        }
        else if( opt == 1 ){
            register_person(&v1);
        }
        else if( opt == 6 ){
            print(&v1);
        }
        

    }

    printf("Encerrando programa e restituindo memoria\n");
    destroy(&v1);

    return 0;
}
