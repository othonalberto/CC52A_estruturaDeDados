#include <stdlib.h>
#include <stdio.h>

void troca(int v[], int j, int k){
    int aux = v[j];
    v[j] = v[k];
    v[k] = aux;
}

void printaTudo(int v[], int n){
    if(v == NULL)
        return;

    int i;

    for(i = 0; i<n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}
void borbulhaMaior(int v[], int n){
    int i;

    for(i = 0; i<n-1; i++){
        if(v[i] > v[i+1])
            troca(v, i, i+1);
    } 
}

void selecaoMaior(int v[], int n){
    if(v == NULL)
        return;

    int i, maior = 0;

    for(i = 0; i<n; i++){
        if(v[i] > v[maior])
            maior = i;
    }

    troca(v, maior, n-1);
}

void insercao(int v[], int i, int n){
    if(v == NULL)
        return;

    int j;

    for(j = i; j>-1;j--){
        if(v[j] < v[j-1])
            troca(v, j, j-1);
    }
}
void bubbleSort(int v[], int n){
    if(v == NULL)
        return;

    int i;

    for(i = 0; i<n; i++)
        borbulhaMaior(v, n-i);
}

void selectionSort(int v[], int n){
    if(v == NULL)
        return;

    int i;

    for(i = 0; i<n; i++)
      selecaoMaior(v, n-i);
}

void insertionSort(int v[], int n){
    if(v == NULL)
        return;

    int i;

    for(i = 0; i<n; i++)
        insercao(v, i, n);
}
