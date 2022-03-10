#include <stdlib.h>
#include <stdio.h>

void leVetor(int *v, int n);
void bubbleSort(int *v, int n);
void troca(int *v, int a, int b);


int main() {
int n;
int *v = NULL;

scanf("%d", &n);

v = (int *)malloc(n * sizeof(int));
leVetor(v, n);

bubbleSort(v, n);

free(v);

return 0;
}

void bubbleSort(int *v, int n) {
    int i, j, aux;
    int comp = 0, t = 0;

    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i ; j--)
        { 
          comp++;
            if(v[j] < v[j - 1])
            {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux; 
                t++;
            }
             
        }
    //for(i = 0; i < n; i++) para ver saída
     // printf("%d ", v[i]);

    printf("%d %d\n", comp, t);
}

void leVetor(int *v, int n){
  int i;
  
  for (i = 0; i < n; i++)
  {

    scanf("%d", &v[i]);

  }

}
