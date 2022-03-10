#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int p, int q, int r);
void leVetor(int *v, int n);
void mergeSort(int *v, int p, int r);

int t=0;
int comp=0;

int main() {
  //int i;
  int n;
  int *v = NULL;
  //int p;

scanf("%d", &n);

v = (int *)malloc(n * sizeof(int));
 
  leVetor(v, n);
  /*
  for (i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
  }
  */
  mergeSort(v, 0, n);
/*
for (i = 0; i < n; i++)
  {
    printf("%d", v[i]);
  }

*/
  printf("%d %d", comp, t);

  return 0;
}

void mergeSort(int *v, int p, int r)
  {
    if(p < r - 1)
    {
    int q = (p + r) / 2; // metade

    mergeSort(v, p, q);
    mergeSort(v, q, r);
    intercala(v, p, q, r);
    }
    }


void intercala(int *v, int p, int q, int r)
  {
  int i, j, k; // Contadores
  int *w; // Vetor auxiliar

    w = (int *)malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r)
    {
    if(v[i] <= v[j])
      
      w[k++] = v[i++], comp++, t++;
    else
      w[k++] = v[j++], comp++, t++;
    }


    while(i < q)
      w[k++] = v[i++], t++;
    while(j < r)
      w[k++] = v[j++], t++;

    for(i = p; i < r; i++)
      v[i] = w[i - p], t++;

    
    
    free(w);
    } // Fim intercala()





void leVetor(int *v, int n){
  int i;
  
  for (i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
  }

}
