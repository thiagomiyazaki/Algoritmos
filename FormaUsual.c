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
    node_t *tmp;
    node_t *head;

    tmp = create_new_node(32);
    head = tmp;
    tmp = create_new_node(8);
    tmp->next = head;
    head = tmp;
    tmp = create_new_node(34);
    tmp->next = head;
    head = tmp;

    printlist(head);

    return 0;
}
