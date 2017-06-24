#include <stdlib.h>
#include "busca.h"
#include <stdio.h>

int sequencial(int v[], int k, int ini, int fim){
    if(v == NULL)
        return -1;

    while(ini <= fim){
        if(v[ini] == k)
            return v[ini];
        else
            ini++;
    }

    return -1;
}

int nsequencial(int v[], int k, int n){
    if(v == NULL)
        return -1;
    
    int i;

    for(i = 0; i<n; i++){
        if(v[i] == k)
            return v[i];
    }

    return -1;
}

int nsequencialPar(int v[], int k, int n){
    int i;

    for(i = 0; i<n; i = i+2){ //corre os pares
        if(v[i] == k)
            return v[i];
    }

    for(i = 1; i<n; i = i+2){
        if(v[i] == k)
            return v[i];
    }

    return -1;
}

int sequencialMeio(int v[], int k, int ini, int fim){
    if(v == NULL)
        return -1;
    
    int i = 0;
    int n = (fim - ini + 1);
    int meio = n/2;

    if(v[meio] == k)
        return v[meio];

    while(i < n){
        if(meio+i <= fim && v[meio+i] == k)
            return v[meio+i];

        if(meio-i >= ini && v[meio-i] == k)
            return v[meio-i];
        
        i++;
    }

    return -1;
}   

int nsequencialMeio(int v[], int k, int n){
    if(v == NULL)
        return -1;

    int i = 0;
    int meio = n/2;

    while(i < n){
        if(meio+i < n && v[meio+i] == k)
            return v[meio+i];

        if(meio-i > -1  && v[meio-i] == k)
            return v[meio-i];
        
        i++;
    }

    return -1;
}

int binaria(int v[], int k, int ini, int fim){
    if(v == NULL)
        return -1;

    
    while(ini <= fim){
        int meio = (ini+fim) /2;

        if(v[meio] == k)
            return v[meio];
        else if(v[meio] < k) //k está à direita
            ini = meio+1;
        else //k está à esquerda
            fim = meio-1;
    }
    
    return -1;
}

int recursivaBinaria(int v[], int k, int ini, int fim){
    if(v == NULL || ini>fim)
        return -1;

    int meio = (ini+fim) /2;

    if(v[meio] == k)
        return v[meio];
    else if(v[meio] < k)
        return recursivaBinaria(v, k, meio+1, fim);
    else
        return recursivaBinaria(v, k, ini, meio-1);
}

int nRecursivaBinaria(int v[], int k, int n){
    if(v == NULL || n == 0)
        return -1;

    int meio = n/2;

    if(v[meio] == k)
        return v[meio];
    else if(v[meio] < k)
        return nRecursivaBinaria(v+meio+1, k, meio);
    else
        return nRecursivaBinaria(v, k, meio);
}
