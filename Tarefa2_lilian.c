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

void ShellSort(int *Zeca, int tam){
  int i, j, save, jump, shell;
  jump = 4; /* definido o padrão o tamanho dos "pulos" do shell*/
  /* o algorítimo não aceitará vetores menores que 4 */
  for( i = jump; i > 0; i--){ //laço reduzindo os pulos em 1
    for(j = 0; j != i; j++){//mantem atado ao começo com os limites de pulo
      for( shell = j; shell < tam; shell+i){//inicia em J e avança
        if(shell + i < tam && Zeca[shell] > Zeca[shell+i]){
          save = Zeca[shell];
          Zeca[shell] = Zeca[shell+i];
          Zeca[shell+i] = save;
        }
      }
    }
  }
}

/*Este algoritimo se baseia no vídeo de Yusuf Shakeel presente em:
 Sorting Algorithm | Quick Sort - step by step guide
 <youtube.com/watch?v=3OLTJlwyIqQ>, acessado 18/agosto/2017 */
void NesQUICKsort(int *Zeca, int DI, int EI){
  //Esquerda do PIVO sempre deverá ser MENOR que elemento
  //Direita do PIVO sempre deverá ser MAIOR que elemento
  int DirIndex, EsqIndex, Pivo, aux, hold, ei1, di1;
  hold = 0;// utilizado para mover o LADO
  DirIndex = Pivo = di1 = DI;//no caso inicial sera tam
  EsqIndex = ei1 = EI;//no caso inicial sera 0
  while (DirIndex != EsqIndex) {
    if(hold == 0){//trata a DIREITA
      if (Zeca[Pivo] < Zeca[DirIndex])
        DirIndex--;
      else{
        //swap
        Aux = Zeca[DirIndex];
        Zeca[DirIndex] = Zeca [Pivo];
        Zeca[Pivo] = Aux;
        Pivo = DirIndex;//at o Pivo
        hold = 1;
      }
    }
    else{//trata a ESQUERDA
      if (DirIndex != EsqIndex && Zeca[EsqIndex] < Zeca[Pivo] )
        EsqIndex--;
      else{
        //swap
        Aux = Zeca[EsqIndex];
        Zeca[EsqIndex] = Zeca [Pivo];
        Zeca[Pivo] = Aux;
        Pivo = EsqIndex;//at o Pivo
        hold = 0
      }
    }
  }
  if (di1 != ei1){//parte recursiva
    NesQUICKsort(*Zeca, di1, Pivo);
    NesQUICKsort(*Zeca, Pivo, ei1);
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
