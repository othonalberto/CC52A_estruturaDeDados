/*  BUSCAS SEQUENCIAIS */
int sequencial(int v[], int k, int ini, int fim);
int nsequencial(int v[], int k, int n);

// situação hipotética onde a probabilidade de k estar em um índice par é maior
int nsequencialPar(int v[], int k, int n);

int sequencialMeio(int v[], int k, int ini, int fim);
int nsequencialMeio(int v[], int k, int n);

/* BUSCAS BINÁRIAS */
int binaria(int v[], int k, int ini, int fim);

int recursivaBinaria(int v[], int k, int ini, int fim);
int nRecursivaBinaria(int v[], int k, int n);
