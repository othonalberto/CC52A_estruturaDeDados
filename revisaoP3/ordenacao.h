/* PROCEDIMENTOS ÚTEIS */
void troca(int v[], int j, int k);
void printaTudo(int v[], int n);

/* PROCEDIMENTOS BASE */
void borbulhaMaior(int v[], int n);
void selecaoMaior(int v[], int n);
void insercao(int v[], int i, int n); //i é a quantidade de elementos que estão ordenados
int particao(int v[], int ini, int fim);
int randomParticao(int v[], int ini, int fim);
void intercala(int v[], int ini, int fim, int meio);

/* ORDENAÇÃO QUADRÁTICA */
void bubbleSort(int v[], int n);
void selectionSort(int v[], int n);
void insertionSort(int v[], int n);

/* ORDENAÇÃO EFICIENTE*/
void quickSort(int v[], int ini, int fim);
void randomQuickSort(int v[], int ini, int fim);
void mergeSort(int v[], int ini, int fim);
