#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Trabalho para a dissiplina de AED-II d na UNIFESP*/
/* Marcos Eduardo Lopes Honorato. RA: 86379 */
/*** todos os sorts assumem que o vetor terá mais que um item ***/

void SelSort(int *Zec, int tam){
  int i, menor, j, cup, save;
  menor = Zec[tam-1];
  for (i = 0; i <  tam; i++){//laço do posicionameto
    for(j = tam-1; j > i; j--){ //fim -> onde ja foi ordenado
      if(menor < Zec[j])
        save = j;//salva o local do menor elemento
    }
  cup = Zec[save];
  Zec[save] = Zec[i];//ordenando
  Zec[i] = cup;
  }
}

void InsertSort(int *Zec, int tam){
  int i, j, save;
  for(i = 1; i < tam; i++){ //laço para parte ordenada
    save = Zec[i];//item a ser movido
    j -= i;

    while(j >= 0 && save < Zec[j]){//passando o intem
      Zec[j+1] = Zec[j];
      j--;
    }
    Zec[j+1] = save;//realocação
  }
}

void BolhaSort(int *Zec, int tam){
  int i, j, save;
  for( i = 0; i != tam; i++){ //laço para repetições
    for(j = 0; j < tam -1; j++){//bolha
      if(Zec[j] > Zec[j+1]){
        save = Zec[j];
        Zec[j] = Zec[j+1];
        Zec[j+1] = save;
      }
    }
  }
}

int main(){

    int Tamam, Aux, *Zeca, *Zeca1, *Zeca2, i;

    scanf ("%d", &Tamam);

    Zeca = malloc(Tamam * sizeof(Zeca));
    Zeca1 = malloc(Tamam * sizeof(Zeca));
    Zeca2 = malloc(Tamam * sizeof(Zeca));
    for (i = 0; i < Tamam; i++){
	    Aux = rand() % Tamam;
	    Zeca[i]  = Aux;
      Zeca1[i]  = Aux;
      Zeca2[i]  = Aux;
    }
    clock_t start = clock();
    SelSort(Zeca, Tamam);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%f\n", seconds);

    start = clock();
    InsertSort(Zeca1, Tamam);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%f\n", seconds);

    start = clock();
    BolhaSort(Zeca2, Tamam);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%f\n", seconds);

}
