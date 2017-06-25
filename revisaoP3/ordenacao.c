#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ordenacao.h"

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

int particao(int v[], int ini, int fim){
    if(v == NULL)
        return -1;
    int pivot = ini;
    int i = ini+1;
    int j = fim;

    while(i<=j){
        if(v[i] <= v[pivot])
            i++;
        else if(v[j] > v[pivot])
            j--;
        else{
            troca(v, i, j);
            i++;
            j--;
        }
    }

    troca(v, pivot, j);

    return j;
}

int randomParticao(int v[], int ini, int fim){
    if(v == NULL)
        return -1;
    
    srand(time(NULL));

    int pivot = ini;
    int i = ini+1;
    int j = fim;
    int r = rand()% (fim-ini+1) + ini;
    
    troca(v, pivot, r);
    
    while(i<=j){
        if(v[i] < v[pivot])
            i++;
        else if(v[j] > v[pivot])
            j--;
        else{
            troca(v, i, j);
            i++;
            j--;
        }
    }

    troca(v, pivot, j);

    return j;
}

void intercala(int v[], int ini, int fim, int meio){
    int i = ini;
    int j = meio+1;
    int n = fim-ini+1;
    int k = 0;
    
    int *aux = malloc(sizeof(int)*n);
    if(aux == NULL)
        return;
    
    while(i<=meio && j<=fim){
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        } else{
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    while(i<=meio){
        aux[k] = v[i];
        i++;
        k++;
    }

    while(j<=fim){
        aux[k] = v[j];
        j++;
        k++;
    }
    
    for(k = 0; k<n; k++)
        v[ini++] = aux[k];

    free(aux);
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

void quickSort(int v[], int ini, int fim){
    if(v == NULL || ini>fim)
        return;
    
    int p = particao(v,ini, fim); 
    quickSort(v, ini, p-1);
    quickSort(v, p+1, fim);
}

void randomQuickSort(int v[], int ini, int fim){
    if(v == NULL || ini>fim)
        return;

    int p = randomParticao(v, ini, fim);
    quickSort(v, ini, p-1);
    quickSort(v, p+1, fim);
}

void mergeSort(int v[], int ini, int fim){
    if(v == NULL)
        return;
    
    if(ini<fim){
        int meio;
        meio = (fim+ini)/2;

        mergeSort(v, ini, meio);
        mergeSort(v, meio+1, fim);
        intercala(v, ini, fim, meio);
    }
}
