#include <stdio.h>
#include <stdlib.h>

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
  for( i = 0; i != tam-1; i++){ //laço para repetições
    for(j = 0; j < tam -2; j++){//bolha
      if(Zec[j] > Zec[j+1]){
        save = Zec[j];
        Zec[j] = Zec[j+1];
        Zec[j+1] = save;
      }
    }
  }
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

//Arruma move o vetor para DIREITA e SOMENTE para DIREITA "em uma casa"
void Arruma(int *Zeca, int Comeco, int fim, int itemMovido){
  int i;
  for (i = fim, i != Comeco, i--)
    Zeca[i] = Zeca[i--];
  Zeca[Comeco] = itemMovido;
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

/*Este algoritimo se baseia no vídeo de Machael Sambol presente em:
Heap sort in 4 minutes
<youtube.com/watch?v=2D>, acessado 18/agosto/2017 */
void HeapSort(int *Zeca, int tam){
  int Aux, Sorted, i, j, max;
  max = Zeca[0];
  sorted = -1; //pq tem nada organizado ainda
  for(i = tam-1; i != 0; i--){
    for(j = 0; j != tam; j++ ){
      if (max < Zeca[j])
        max = j;//salva o index do maior num no vetor
      Aux = Zeca[max];
      Zeca[max] = Zeca[0];
      Zeca[0] = Aux;
    }
    Aux = Zeca[0];
    Zeca[0] = Zeca[i];
    Zeca[i] = Aux;
  }
}



int main(){
    int Tamam, Aux, *Zeca, i;
    printf ("informe o tamanho do vetor");
    scanf ("%d", &Tamam);
    Zeca = malloc(Tamam * sizeof(Zeca));
    printf ("informe os valores do vetor");
    for (i = 0; i < Tamam; i++){
	    scanf ("%d", &Aux);
	    Zeca[i]  = Aux;
    }
    printf("Selecione o metodo de ordenação: \n");
    printf("1- Selection  2- Insertion  3- Bolha\n");
    scanf("%d\n", &i);
    if (i == 1) {
      SelSort(Zeca, Tamam);
    }
    else if (i ==2) {
      InsertSort(Zeca, Tamam);
    }
    else if (i == 3) {
      BolhaSort(Zeca, Tamam);
    }

    for (i = 0; i < Tamam; i++)//imprimindo o vetor ordenado
      printf("%d\n", Zeca[i]);

    return 0;
}
