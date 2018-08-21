#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Trabalho para a dissiplina de AED-II d na UNIFESP*/
/* Marcos Eduardo Lopes Honorato. RA: 86379 */
/*** todos os sorts assumem que o vetor terá mais que um item ***/

void imprime(int *Zeca, int Tamam){
  int i;
  for (i = 0; i < Tamam; i++)//imprimindo o vetor ordenado
    printf("%d ", Zeca[i]);
  printf("\n");
  return;
}

void SelSort(int *Zec, int tam){
  int i, menor, j, cup, save;
  for (i = 0; i <  tam; i++){//laço do posicionameto
    menor = Zec[i];
    save = i;
    for(j = tam-1; j > i; j--){ //fim -> onde ja foi ordenado
      if(menor > Zec[j]){
        save = j;//salva o local do menor elemento
        menor = Zec[j];
      }
    }
    cup = Zec[save];
    Zec[save] = Zec[i];//ordenando
    Zec[i] = cup;
    //imprime(Zec, tam);
  }
}

void InsertSort(int *Zec, int tam){
  int i, j, save;
  for(i = 0; i < tam; i++){ //laço para parte ordenada
    save = Zec[i];//item a ser movido
    for(j = i; j != -1; j--){
      if(save < Zec[j]){
        save = Zec[j+1];
        Zec[j+1] = Zec[j];//passando o intem
        Zec[j] = save;
      }
    }
    //imprime(Zec, tam);
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
  //imprime(Zec, tam);
  }
}

int main(){

    int Tamam, Aux, *Zeca, *Zeca1, *Zeca2, i;

    scanf ("%d", &Tamam);

    Zeca = malloc(Tamam * sizeof(Zeca));
    Zeca1 = malloc(Tamam * sizeof(Zeca));
    Zeca2 = malloc(Tamam * sizeof(Zeca));
    for (i = 0; i < Tamam; i++){
	    Aux = Aux + rand() % 10;//modo vetor crescente
      //Aux = rand() % Tamam; //modo vetor aleatorio
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
