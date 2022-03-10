/*
TAMANHOS(n) DE VETORES A SEREM TESTADOS: 50 000; 75 000; 112 500; 168 750; 253 125;
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define RUN 32 //TIM SORT - RUN é o nome dado aos sub-vetores ordenados do vetor de entrada. seus valores podem variar de 32 a 64 e se o tamanho do array for menor que o RUN ele poderá ser ordenado utilizando apenas Insertion Sort

#define TAM 50000 //define o tamanho dos baldes que serão usados no bucket sort

void preencheVetorDistinto(int *v, int n);
void copiaVetor(int *v, int *v2, int *v3, int *v4, int *v5, int *v6, int *v7, int *v8, int *vAux, int n);

void preencheVetorIgual(int *v, int n);

void preencheVetor4(int *v, int n);

void trocar(int *a, int *b);

void smartBubbleSort(int *vAux, int n);
void vetorDes(int *v, int n);

int menor(int a, int b, unsigned long long int *comp);

void insertionSort(int *v, int n);

void selectionSort(int *v2, int n);

void bubbleSort(int *v3, int n);

void combSort(int *v4, int n);

void mergeSort(int *v5, int p, int r);
void intercala(int *v5, int p, int q, int r);

int particionahoare(int *v6, int p, int r);
void quicksorthoare(int *v6, int p, int r);

int minTim(int x, int y);
int menorTim(int a, int b);
int menorIgualTim(int a, int b);
void insertionTim(int *v7, int first, int n);
void mergeTim(int *v, int inicio, int meio, int fim);
void timSort(int *v, int n);
//-----------------------------------------------------

//bucket sort
void bucketSort(int *v8, int n);
int menorBucket(int a, int b);

//variáveis globais pra contagem
unsigned long int cm = 0; //comparações merge
unsigned long int tm = 0; //trocas merge

unsigned long int ch = 0; //comparaçoes quick hoare
unsigned long int th = 0; //trocas quick hoare

unsigned long int ct = 0; //comparaçoes timSort
unsigned long int tt = 0; //trocas timSort

unsigned long int cb = 0; //comparações bucket sort
unsigned long int tb = 0; //trocas bucket sort

int main()
{
  unsigned long int n = 20000; //alterar conforme o tamanho do vetor 
  int v[n];
  int vAux[n];
  int v2[n];
  int v3[n];
  int v4[n];
  int v5[n];
  int v6[n];
  int v7[n];
  int v8[n];

  //contagem de tempo
  double time_spent = 0.0;
  
  
  preencheVetorDistinto(v, n);
  copiaVetor(v, vAux, v2, v3, v4, v5, v6, v7, v8, n);

  clock_t begin = clock();
  insertionSort(v, n);
  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de execução Insertion Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  selectionSort(v2, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Selection Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  bubbleSort(v3, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Bubble Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  combSort(v4, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Comb Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  mergeSort(v5, 0, n);
  end = clock();
  printf("\ncomparações e trocas do merge\n");
  printf("%lu %lu", cm, tm);
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Merge Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  quicksorthoare(v6, 0, n - 1);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações  e trocas do Quick Sort\n");
  printf("%lu %lu", ch, th);
  printf("\nTempo de execução Quick Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  timSort(v7, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nComparações e trocas do Tim Sort:\n");
  printf("%lu %lu", ct, tt);
  printf("\nTempo de execução do Tim Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  tb = 0;
  cb = 0;
  begin = clock();
  bucketSort(v8, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações  e trocas do Bucket Sort\n");
  printf("%lu %lu", cb, tb);
  printf("\nTempo de execução Bucket Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0; 

  printf("FIM DO VETOR 1\n\n"); 

  //vetor do tipo 2, com elementos distintos já ordenados
  
  preencheVetorDistinto(v, n);

  copiaVetor(v, vAux, v2, v3, v4, v5, v6, v7, v8, n);

  begin = clock();
  insertionSort(v, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de execução Insertion Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  selectionSort(v2, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Selection Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  bubbleSort(v3, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Bubble Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  combSort(v4, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Comb Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  mergeSort(v5, 0, n);
  end = clock();
  printf("\ncomparações e trocas do merge\n");
  printf("%lu %lu", cm, tm);
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Merge Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  quicksorthoare(v6, 0, n - 1);
  end = clock();
  printf("\ncomparações  e trocas do quick\n");
  printf("%lu %lu", ch, th);
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução quick sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  begin = clock();
  timSort(v7, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nComparações e trocas do Tim Sort:\n");
  printf("%lu %lu", ct, tt);
  printf("\nTempo de execução Tim Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  tb = 0;
  cb = 0;
  begin = clock();
  bucketSort(v8, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações  e trocas do Bucket Sort\n");
  printf("%lu %lu", cb, tb);
  printf("\nTempo de execução Bucket Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  printf("\nFIM DO VETOR 2\n\n"); 
  
  //3 fase
  //com vetor ordenado de forma descrescente com elementos distintos
  
  preencheVetorDistinto(v, n);

  smartBubbleSort(vAux, n);

  copiaVetor(v, vAux, v2, v3, v4, v5, v6, v7, v8, n);

  //INSERTION SORT
  begin = clock();
  insertionSort(v, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de execução Insertion Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //SELECTION SORT
  begin = clock();
  selectionSort(v2, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Selection Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //BUBBLE SORT
  begin = clock();
  bubbleSort(v3, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Bubble Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //COMB SORT
  begin = clock();
  combSort(v4, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Comb Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //MERGE SORT
  begin = clock();
  mergeSort(v5, 0, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações e trocas do merge\n");
  printf("%lu %lu", cm, tm);
  printf("\nTempo de execução Merge Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //QUICK SORT
  begin = clock();
  quicksorthoare(v6, 0, n - 1);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações  e trocas do quick\n");
  printf("%lu %lu", ch, th);
  printf("\nTempo de execução Quick Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //TIM SORT
  begin = clock();
  timSort(v7, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nComparações e trocas do Tim Sort:\n");
  printf("%lu %lu", ct, tt);
  printf("\nTempo de execução Tim Sort: %f seconds\n", time_spent);
  time_spent = 0.0;

  //BUCKET SORT
  tb = 0;
  cb = 0;
  begin = clock();
  bucketSort(v8, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações  e trocas do Bucket Sort\n");
  printf("%lu %lu", cb, tb);
  printf("\nTempo de execução Bucket Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0; 
  
  //----------------------------------------------------------------------
  memset(v, 0, sizeof(v));
  
  printf("\n\nVetor 4:\n\n");
  
  preencheVetor4(v, n);
  copiaVetor(v, vAux, v2, v3, v4, v5, v6, v7, v8, n);

  //INSERTION SORT
  begin = clock();
  insertionSort(v, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de execução Insertion Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //SELECTION SORT
  begin = clock();
  selectionSort(v2, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Selection Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //BUBBLE SORT
  begin = clock();
  bubbleSort(v3, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Bubble Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //COMB SORT
   begin = clock();
  combSort(v4, n);
   end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo de execução Comb Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //MERGE SORT
  begin = clock();
  mergeSort(v5, 0, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações e trocas do merge\n");
  printf("%lu %lu", cm, tm);
  printf("\nTempo de execução Merge Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //QUICK SORT
  begin = clock();
  quicksorthoare(v6, 0, n - 1);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações  e trocas do quick\n");
  printf("%lu %lu", ch, th);
  printf("\nTempo de execução Quick Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;

  //TIM SORT
  begin = clock();
  timSort(v7, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nComparações e trocas do Tim Sort:\n");
  printf("%lu %lu", ct, tt);
  printf("\nTempo de execução Tim Sort: %f seconds\n", time_spent);
  time_spent = 0.0;

  //BUCKET SORT
  tb = 0;
  cb = 0;
  begin = clock();
  bucketSort(v8, n);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ncomparações  e trocas do Bucket Sort\n");
  printf("%lu %lu", cb, tb);
  printf("\nTempo de execução Bucket Sort: %f seconds\n\n", time_spent);
  time_spent = 0.0;
  
  return 0;
}

//função para preencher o tamanho(n) do vetor com números aleatórios sem repetição
void preencheVetorDistinto(int *v,  int n)
{
  int i = 0;
  srand(time(NULL));
  //alterar o % conforme mudar o 'n'
  for (i = 0; i < n; i++)
  {
    v[i] = (rand() % 100000000000) + 1; //%(range) alto pra nao ter chance de repetir, além de por %n demorar menos pra achar um vetor que não repita
    
  }
}

void preencheVetor4(int *v, int n)
{
  int i = 0, j = 0, k = 0;

  srand(time(NULL));

  //prenchemos o vetor de 5 em 5 por cento com um mesmo valor j.
  for (k = 0; k < n; k += (n / 20))
  {
    j = (rand() % 1000000) + 1;
    for (i = k; i < k + (n / 20); i++)
    {
      v[i] = j;
    }
  }

  //embaralhamos os valores do vetor
  for (i = 0; i < n - 1; ++i)
  {
    int j = rand() % (n - i) + i;
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
  }
}

//função responsável por copiar o valor do vetor original. Esse valor será usado em outras funções.

void copiaVetor(int *v, int *vAux, int *v2, int *v3, int *v4, int *v5, int *v6, int *v7, int *v8, int n)
{
  int i;
  for (i = 0; i < n; i++)
    v2[i] = v[i]; //cópia recebe original

  for (i = 0; i < n; i++)
    v3[i] = v2[i];

  for (i = 0; i < n; i++)
    v4[i] = v3[i];

  for (i = 0; i < n; i++)
    v5[i] = v4[i];

  for (i = 0; i < n; i++)
    v6[i] = v5[i];

  for (i = 0; i < n; i++)
    v7[i] = v6[i];

  for (i = 0; i < n; i++)
    v8[i] = v7[i];

  for (i = 0; i < n; i++)
    vAux[i] = v8[i];
}

//função para testes, demonstra o vetor gerado
void vetorDes(int *v, int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n\n");
}

//funçao para auxiliar nas trocas

void trocar(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

//função responsável por ordenar o vetor de forma descrente, recebe o vetor original copiado e o tamanho dele. será usada para auxiliar no momento de gerar vetores aleatórios ordenados de forma contrária

void smartBubbleSort(int *vAux, int n)
{
  int i, j;
  int comp = 0, t = 0;
  int again = 1;
  int aux;

  for (i = 0; i < n - 1 && again; i++)
  {
    for (j = n - 1, again = 0; j > i; j--)
    {
      comp++;
      if (vAux[j] > vAux[j - 1])
      {

        aux = vAux[j];
        vAux[j] = vAux[j - 1];
        vAux[j - 1] = aux;

        t++;
        again = 1;
      }
    }
  }
}

int menor(int a, int b, unsigned long long int *comp)
{

  *comp = *comp + 1;

  return (a < b);
}

//AJUSTAR PARA unsigned long int COMPARAÇÕES e TROCAS %lu para imprimir na tela

void insertionSort(int *v, int n)
{
  int i, j;
  unsigned long long int trocas = 0, comp = 0;

  for (i = 0; i < n; i++)
  {
    for (j = i; j > 0 && menor(v[j], v[j - 1], &comp); j--)
    {
      trocar(&v[j], &v[j - 1]);

      trocas++;
    }
  }
  printf("comparações e trocas do Insertion\n");
  printf("%llu %llu\n", comp, trocas);
}

void selectionSort(int *v2, int n)
{

  int i, j, min;
  unsigned long long int comp = 0, trocas = 0;

  for (i = 0; i < n - 1; i++)
  {

    min = i;
    for (j = i + 1; j < n; j++)
    {

      if (menor(v2[j], v2[min], &comp))
      {
        min = j;
      }
    }

    trocar(&v2[i], &v2[min]);
    trocas++;
  }
  printf("comparações e trocas do selection sort\n");
  printf("%llu %llu", comp, trocas);
}

void bubbleSort(int *v3, int n)
{
  int i, j, aux;

  unsigned long int comp = 0;
  unsigned long int t = 0;

  for (i = 0; i < n - 1; i++)
    for (j = n - 1; j > i; j--)
    {
      comp++;
      if (v3[j] < v3[j - 1])
      {
        aux = v3[j];
        v3[j] = v3[j - 1];
        v3[j - 1] = aux;
        t++;
      }
    }
  printf("\ncomparações e trocas do bubble sort\n");
  printf("%lu %lu", comp, t);
}

void combSort(int *v4, int n)
{
  int i, j, k, again = 1, step;
  int aux;
  unsigned long int compComb = 0;
  unsigned long int trocasComb = 0;

  step = (int)(n / 1.3);
  //fase 1
  while (step > 1)
  {
    for (j = 0; (j + step) < n; j++)
    {
      k = j + step;
      compComb++;
      if (v4[j] > v4[k])
      {
        aux = v4[k];
        v4[k] = v4[j];
        v4[j] = aux;
        trocasComb++;
      }
    }
    step = (int)(step / 1.3);
  }

  //fase 2
  for (i = 0; i < n - 1 && again; i++)
  {
    for (j = n - 1, again = 0; j > i; j--)
    {
      compComb++;
      if (v4[j] < v4[j - 1])
      {
        aux = v4[j];
        v4[j] = v4[j - 1];
        v4[j - 1] = aux;
        trocasComb++;
        again = 1;
      }
    }
  }
  printf("\ncomparações e trocas comb\n");
  printf("%lu %lu", compComb, trocasComb);
}

void mergeSort(int *v5, int p, int r)
{
  if (p < r - 1)
  {
    int q = (p + r) / 2; // metade

    mergeSort(v5, p, q);
    mergeSort(v5, q, r);
    intercala(v5, p, q, r);
  }
}

void intercala(int *v5, int p, int q, int r)
{
  int i, j, k; // Contadores
  int *w;      // Vetor auxiliar

  w = (int *)malloc((r - p) * sizeof(int));
  i = p;
  j = q;
  k = 0;

  while (i < q && j < r)
  {
    if (v5[i] <= v5[j])

      w[k++] = v5[i++], cm++, tm++;
    else
      w[k++] = v5[j++], cm++, tm++;
  }

  while (i < q)
    w[k++] = v5[i++], tm++;
  while (j < r)
    w[k++] = v5[j++], tm++;

  for (i = p; i < r; i++)
  {
    v5[i] = w[i - p], tm++;
  }

  free(w);
} // Fim intercala()

int particionahoare(int *v6, int p, int r)
{

  int piv = v6[p];
  int i = p - 1, j = r + 1;

  while (1)
  {
    do
    {
      i++;
      ch++;
      cb++;
    } while (v6[i] < piv);

    do
    {
      j--;
      ch++;
      cb++;
    } while (v6[j] > piv);

    if (i >= j)
    {
      return j;
    }
    trocar(&v6[i], &v6[j]);
    th++;
    tb++;
  }
}

void quicksorthoare(int *v6, int p, int r)
{
  int q; // Recebe o retorno da função particiona

  if (p < r)
  {
    q = particionahoare(v6, p, r);
    quicksorthoare(v6, p, q);
    quicksorthoare(v6, q + 1, r);
  }
}

int menorTim(int a, int b)
{
  ct++;
  return (a < b);
}

int minTim(int x, int y)
{                         // utilizado para calcular o MINRUN, que se trata do comprimento mínimo de um RUN
  return (x < y) ? x : y; //operador ternário
}

void insertionTim(int *v7, int first, int n)
{
  //first é o primeiro elemento do sub-vetor, n é o último
  int i, j;

  for (i = first + 1; i <= n; i++)
  { //percore o sub-vetor
    int aux = v7[i];
    for (j = i - 1; j >= first && menorTim(aux, v7[j]); j--)
    { //se o anterior for maior que o seguinte... //COMPARAÇÃO NO FOR

      v7[j + 1] = v7[j]; //o seguinte recebe o anterior
      tt++;
    }
    v7[j + 1] = aux;
  }
}

int menorIgualTim(int a, int b)
{
  ct++;
  return (a <= b);
}

void mergeTim(int *v7, int inicio, int meio, int fim)
{

  int tam1 = meio - inicio + 1; //sub-vetor inicial
  int tam2 = fim - meio;        //sub-vEtor seguinte
  int i = 0;
  int inicial[tam1]; //definimos os sub-vetores com seus devidos tamanhos
  int seguinte[tam2];

  for (i = 0; i < tam1; i++)
  { //"preenchemos" os sub-vetores
    inicial[i] = v7[inicio + i];
  }

  for (i = 0; i < tam2; i++)
  {
    seguinte[i] = v7[meio + i + 1];
  }

  int j = 0;
  int k = inicio;

  while (i < tam1 && j < tam2)
  { //compara os sub-vetores e faz o merge deles em um sub-vetor
    if (menorIgualTim(inicial[i], seguinte[j]))
    { //compara os elementos dos dois sub-vetores para ordenar e colocar no vetor principal
      //COMPARAÇÃO AQUI NO IF

      v7[k] = inicial[i]; //TROCA?
      i++;
      tt++;
    }
    else
    {
      v7[k] = seguinte[j]; //TROCA?
      j++;
    }
    k++;
  }

  //faz o merge do restante dos elementos
  while (i < tam1)
  {
    v7[k++] = inicial[i];
    i++;
  }

  while (j < tam2)
  {
    v7[k++] = seguinte[j];
    j++;
  }
}

void timSort(int *v7, int n)
{

  int tamanho;
  int i = 0;

  for (i = 0; i < n; i += RUN)
  {

    insertionTim(v7, i, minTim((i + RUN - 1), (n - 1))); //faz o insertion sort nos sub-vetores de tamanho RUN
  }

  for (tamanho = RUN; tamanho < n; tamanho *= 2)
  {             //começa o merge a partir do tamanho do RUN
    int inicio; //inicio do sub-vetor inicial

    for (inicio = 0; inicio < n; inicio += 2 * tamanho)
    { //aqui é feito o merge do primeiro sub-vetor com o seguinte

      int meio = inicio + tamanho - 1;                                                         //encontra o final do primeiro sub-vetor (meio+1 é o inicio do sub-vetor seguinte)
      int fim = ((inicio + 2 * tamanho - 1) < (n - 1)) ? (inicio + 2 * tamanho - 1) : (n - 1); //encontra o final do sub-vetor seguinte

      if (meio < fim)
        mergeTim(v7, inicio, meio, fim); //faz o merge do sub-vetor inicial com o seguinte
    }
  }
}

//struct com quantidade e tamanho de cada malde

struct balde
{
  int qtd;
  int valores[TAM];
};

//código baseado no autor andre backes
void bucketSort(int *v8, int n)
{
  int i, j, maior, menor, nBaldes, pos;

  struct balde *bd;
  maior = menor = v8[0];
  //busca o maior e o menor e aloca na variável
  for (i = 1; i < n; i++)
  {
    if (v8[i] > maior)
    { //COMP
      maior = v8[i];
    }
    if (v8[i] < menor)
    { // COMP
      menor = v8[i];
    }
  }

  nBaldes = (maior - menor) / TAM + 1; //define quantos baldes vão ter

  bd = (struct balde *)malloc(nBaldes * sizeof(struct balde));

  for (i = 0; i < nBaldes; i++) //inicializa os baldes
    bd[i].qtd = 0;

  for (i = 0; i < n; i++) //distribui em subvetores em intervalos
  {
    pos = (v8[i] - menor) / TAM;

    bd[pos].valores[bd[pos].qtd] = v8[i];
    bd[pos].qtd++;
  }

  pos = 0;  //ordena separadamente e envia novamente pro array inicial ordenado
  for (i = 0; i < nBaldes; i++)
  {
    quicksorthoare(bd[i].valores, 0, (bd[i].qtd - 1));

    for (j = 0; j < bd[i].qtd; j++)
    {
      v8[pos] = bd[i].valores[j];
      pos++;
    }
  }

  free(bd);
}
