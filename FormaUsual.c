/*
    15 de Outubro de 2022 : 10:40 am

    Código retirado da aula do Jacob Sorber: https://www.youtube.com/watch?v=VOpjAHCee7c

    Primeiro exemplo:

*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;  /* Leia esta linha do seguinte modo: */
                        /*      é um pointer para o tipo de estrutura que estamos definindo; */
                        /*      e pode apontar para qualquer estrutura do tipo node;         */
} node_t;

void printlist(node_t *head){
    node_t *temporary = head;

    while(temporary != NULL) {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

node_t *create_new_node(int value){
    node_t *result = (node_t *) malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

int main(){
    node_t *n1, n2, n3;
    node_t *head;

    n1 = (node_t *) malloc(sizeof(node_t));
    n1->value = 45;
    n2.value = 8;
    n3.value = 32;


    // vamos linkar os nodes
    head = n1;
    n3.next = NULL;
    n2.next = &n3;
    n1->next = &n2;

    printlist(head);

    return 0;
}