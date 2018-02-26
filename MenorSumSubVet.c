#include <stdio.h>
#include <stdlib.h>

int plus(int init,int end,int *vector){
  int sum= 0;
  for(;init <= end; init++){
    sum += vector[init];
  }
  return (sum);
}

void print(int init,int end,int *vector){
  if (plus(init, end, vector) >= 0){
    printf(" 0 ");
    return;
  }
  int i;
  for (i = init; i <= end; i++)
    printf("%d\n", vector[i]);
}

int main(){
    int Tamam, Aux, *Vector, i, init, end, k;
    scanf ("%d", &Tamam);
    init = end = 0;
    Vector = malloc(Tamam * sizeof(int));
    for (i = 0; i < Tamam; i++){
	    scanf ("%d", &Aux);
	    Vector[i]  = Aux;
    }

    Aux = plus(0, Tamam, Vector);
    for(i = 0; i < Tamam; i++){
      for(k = Tamam-1; k >= i; k--){
        if(plus(i, k, Vector) <= Aux){
          Aux = plus(i, k, Vector);
          init = i;
          end = k;
        }
      }
    }
    print(init, end, Vector);
}
