/* 
    Insertion Sort é o primeiro algoritmo do Introduction to Algorithms
    
    i: é o contador externo e principal, é como se fosse a carta de baralho retirada do monte.
    j: é o contador interno e principal, vai ser utilizado para comparar de fato os valores.
    aux: onde vamos depositar o valor de A[i], visto que vamos alterar diretamente os valores da array.
    n: dimensão da array, dada por ARR_SIZE
    
    Este algoritmo escolhe um número como item principal de comparação, e vai comparando-o a todos os itens
    da SubArray[0 : i], e através de um loop interno controlado por j, vai comparando i com cada item desta
    SubArray[0 : i], e:
      a. Se A[i] < A[j] (sendo j = i - 1) então o loop vai jogar toda a SubArray para a direita, abrindo espaço
      para podermos colocar o número menor antes do número maior.
      b. Contudo, como A[i] pode ser menor que A[j], A[j - 1], A[j - 2] e assim por diante, primeiro são feitas
      as comparações, e espaços vão sendo ordenados, antes que coloquemos A[i] em seu lugar.
      
*/
#include <stdio.h>
#DEFINE ARR_SIZE 6;

int main(){
    int A[ARR_SIZE] = {6, 4, 5, 2, 3, 1};
  
    /* i é o contador externo principal, e j é o contador interno auxiliar */
    /* n armazena a dimensão da array e aux a variável que vai armazenar A[i] */
    int j = 0, i = 0, n = ARR_SIZE, aux;
  
    /* i = 1 pois precisamos ter itens suficientes para comparação e.g "A[0] cmp A[1]"  */
    /* de i = 1 até i = n, sendo este último incluso, pois é a última iteração*/
    for(i = 1; i <= n; i++){
        /* Vamos guardar A[i] visto que manipularemos diretamente a array */
        /* Na comparação feita na condição do loop while abaixo, se aux for menor que A[j] (A[i - 1])
        então vamos jogar os valores do índice j para j + 1, (j para i), ou seja, sobrescrevemos A[i]
        pelo valor A[i - 1], por isto precisamos armazená-lo, para que n seja perdido. */
        aux = A[i];
        j = i - 1;
        while(j > 0 && A[j] > aux){
            A[j + 1] = A[j];
            j = j - 1; // j--
        }
        A[j + 1] = aux;
    }
    
    return 0;
}
  
 9
