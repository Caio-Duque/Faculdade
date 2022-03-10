#include <stdio.h>
#include <stdlib.h>


void leVetor(int *v, int *y, int *z, int n);
void troca(int *a, int *b);


int particionahoare(int *v, int p, int r);
void quicksorthoare(int *v, int p, int r);

int particionalomuto(int *v, int p, int r);
void quicksortlomuto(int *v, int p, int r);

int particaorobert(int *v, int p, int r);
void quicksortrobert(int *v, int p, int r);



int th = 0;//troca hoare
int ch = 0; //comparações hoare

int tl = 0; //trocas lomuto
int cl = 0; //comparações lomuto

int tr = 0; //trocas robert
int cr = 0; //comparações robert

int main(void) {

  int n;
  int *v = NULL;
  int *y = NULL;
  int *z = NULL;

  scanf("%d", &n);

  v = (int *)malloc(n * sizeof(int));
  y = (int *)malloc(n * sizeof(int));
  z = (int *)malloc(n * sizeof(int));
  
  leVetor(v, y, z, n);

  quicksorthoare(v, 0, n-1);
  printf("%d %d", ch, th);

  quicksortlomuto(y, 0, n-1);
  printf("\n%d %d", cl, tl);

  
  quicksortrobert(z, 0, n-1);
  printf("\n%d %d", cr, tr);


  free(v);
  free(y);
  free(z);
  
  return 0;
}


void leVetor(int *v, int *y, int *z, int n)
{
  int i;
  
  for (i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
      y[i] = v[i];
      z[i] = y[i];

  }

}

  void troca(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int particionahoare(int *v, int p, int r)
{

int piv = v[p];
int i = p - 1, j = r + 1;

while(1){
  do { i++; ch++;
  } while (v[i] < piv);
  do{
    j--; ch++;
  }while (v[j] > piv);

  if (i >= j)
  return j;
  troca(&v[i], &v[j]), th++;
}

}




void quicksorthoare(int *v, int p, int r)
  {
  int q; // Recebe o retorno da função particiona

  if(p < r)
    {
    q = particionahoare(v, p, r);
    quicksorthoare(v, p, q);
    quicksorthoare(v, q + 1, r);
    }

  }

int particionalomuto(int *y, int p, int r){

int piv = y[r];
int i = (p - 1);

for(int j = p; j <= r - 1; j++){
cl++;
if(y[j] <= piv){

i++;
troca(&y[i], &y[j]), tl++;

}

}


troca(&y[i+1], &y[r]), tl++;
return i + 1;

}


void quicksortlomuto(int *y, int p, int r)
  {
  int q; // Recebe o retorno da função particiona

  if(p < r)
    {
    q = particionalomuto(y, p, r);
    quicksortlomuto(y, p, q - 1);
    quicksortlomuto(y, q + 1, r);
    }

  }





int particionarobert(int *z, int p, int r)
     {
     int i = p, j = r + 1, piv = z[p];

    while(1)
      {
      while(cr++, z[++i] < piv)  if(i == r) break;
      while(cr++, piv < z[--j])  if(j == p) break;

      if(i >= j) break;
      

       troca(&z[i], &z[j]), tr++;
      
      }

         troca(&z[j], &z[p]), tr++;

         return j;
      }
     
void quicksortrobert(int *z, int p, int r)
  {
  int q; // Recebe o retorno da função particiona

  if(p < r)
    {
    q = particionarobert(z, p, r);
    quicksortrobert(z, p, q - 1);
    quicksortrobert(z, q + 1, r);
    }

  }

