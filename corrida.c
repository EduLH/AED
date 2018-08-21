#include <stdlib.h>
#include <stdio.h>

int *Popula(int *vet, int size){
    int i, a;
    for(i=0; i<size; i++){
      scanf("%i", &a);
      if (vet == NULL){
          vet = malloc(size * sizeof(int));
          vet[i] = a;
      }
      else
          vet[i] = a;
    }
    return vet;
}

int procura(int *vet, int size, int targ){
    int i, a;
    a = -1;
    for(i=0; i<size; i++){
        if (vet[i] == targ){
            a = i;
            i = size+1;
        }
    }
    return a;
}

int *swap(int *vet, int i){
    int a;
    a = vet[i];
    vet[i] = vet[i-1];
    vet[i-1] = a;
    return vet;
}

int corrida(int *largada, int *chegada, int size){
  int UltPass, i, posCheg, posLarg;
  UltPass=0;
  for(i=0; i<size; i++){
      posCheg = i;
      posLarg = procura(largada, size, chegada[i]);
      while (posLarg != posCheg) {
          largada = swap(largada, posLarg);
          posLarg--;
          UltPass++;
      }
  }
  return UltPass;
}

int main(){
    int UltPass, i, *largada, *chegada;
    largada = chegada = NULL;
    scanf("%i", &i);
    largada = Popula(largada, i);
    chegada = Popula(chegada, i);
    UltPass = corrida(largada, chegada, i);
    printf("%i", UltPass);

    return 0;
}
