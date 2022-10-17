#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i = 0;

    printf("RANDMAX  \t : %d\n", RAND_MAX);
    printf("RANDMAX mod 256  : %d\n", RAND_MAX % 256);
    printf("RANDMAX mod 512  : %d\n", RAND_MAX % 512);
    printf("RANDMAX mod 1024 : %d\n", RAND_MAX % 1024);
    printf("RANDMAX mod 10   : %d\n", RAND_MAX % 10);
    printf("RANDMAX mod 100  : %d\n", RAND_MAX % 100);
    printf("RANDMAX mod 1000 : %d\n", RAND_MAX % 1000);
    puts("-----------------------------------------------------------------");

    srand(time(NULL));
    for(i = 0; i < 20; i++){
        printf("%d ", rand() % 10);
    }
    puts(" ");
    

}