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

int main(){
    node_t n1, n2, n3, n4;
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;
    n4.value = 77;

    // vamos linkas os nodes
    head = &n3;
    n3.next = &n2;
    n2.next = &n4;
    n4.next = &n1;
    n1.next = NULL;     /* Onde a lista termina. */

    // head = head->next;

    printlist(head);

    return 0;
}