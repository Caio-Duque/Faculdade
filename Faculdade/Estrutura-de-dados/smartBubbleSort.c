#include <stdlib.h>
#include <stdio.h>

void leVetor(int *v, int n);
void smartBubbleSort(int *v, int n);


int main() {
int n;
int *v = NULL;

scanf("%d", &n);

v = (int *)malloc(n * sizeof(int));

leVetor(v, n);

smartBubbleSort(v, n);


free(v);

return 0;
}

void smartBubbleSort(int *v, int n) {
    int i, j;
    int comp = 0, t = 0;
    int again=1;
    int aux;

    for (i = 0; i < n - 1 && again; i++)
    {  
        for (j = n - 1, again = 0; j > i ; j--)
        { 
          comp++;
            if(v[j] > v[j - 1])
            {

                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;


                t++;
                again = 1;
            }
        }
    }
    for(i = 0; i < n; i++)
     printf("%d ", v[i]);
    
    printf("\n%d %d\n", comp, t);
}

void leVetor(int *v, int n){
  int i;
  
  for (i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
  }

}
