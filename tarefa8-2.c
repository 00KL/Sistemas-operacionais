#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quickSort (int valor [] , int esquerda , int direita )
{
    int i , j , x , y ;
    i = esquerda ;
    j = direita ;
    x = valor [( esquerda + direita ) / 2];
    while ( i <= j ) {
        while ( valor [ i ] < x && i < direita ) {
           i ++;
        }
        while ( valor [ j ] > x && j > esquerda ) {
            j--;
        }
        if( i <= j ) {
            y = valor [ i ];
            valor [ i ] = valor [ j ];
            valor [ j ] = y ;
            i++;
            j--;
        }
    }
    if( j > esquerda ) {
        quickSort ( valor , esquerda , j ) ;
    }
    if( i < direita ) {
        quickSort ( valor , i , direita ) ;
    }
}

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = n - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(){

    clock_t c1 , c2, total_t ; /* variaveis que contam ciclos de processador */
    float tmp ;
    c1 = clock () ;

    int a[10] = {2,34,67,12,6,7,80,9,76,10};
    int pid;
    if((pid = fork()) == 0){
        quickSort(a, 0, 9);
        for(int i = 0; i < 10; i++){
            printf("%d ", a[i]);
        }
       
        printf("sou o filho\n");
        
        c2 = clock () ;
        //tmp = ( c2 - c1 ) *1000/ CLOCKS_PER_SEC ; // tempo de execucao em milisec .
    
    }else{
        bubble_sort(a, 10);
        for(int i = 0; i < 10; i++){
            printf("%d ", a[i]);
        }
        
        printf(" sou o pai \n");

        c2 = clock () ;
        //tmp = ( c2 - c1 ) *1000/ CLOCKS_PER_SEC ; // tempo de execucao em milisec .
    }

    
    total_t = (double)(c2 - c1) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %ld\n", total_t  );
}