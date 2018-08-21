#include <stdio.h>
#include <stdlib.h>

/*
int menor(int *vet, int Tamam){
int i, Aux;
if(vet[0] == NULL)
return -1;
Aux=9999;  /* ¯\_(ツ)_/¯  *//*
for(i=0, i!=Tamam-1, i++){
if(vet[i] < Aux && vet[i] > 0)
Aux = vet[i];
}
return (Aux);
}*/
void BolhaSort(int *result, int *swaps, int turnos, int Tamam){
    int i, j, Aux, Aux2;
    Aux = turnos;
    Aux2 = Tamam;
    for(j = 0; j!= turnos; j++){
          printf("inserindo %d\n", (Aux+Aux2) );
          result[(swaps[j]-Tamam)] = Aux + Aux2;
          Aux;
          Aux2--;
          printf(">%i<\n",result[(swaps[j]-Tamam)]);
    }
}
/*passar "preenche" p BolhaSort*/
void preenche(int *vet, int Tamam){
    int Aux, i;
    Aux = 1;
    for(i=0; i!=Tamam-1; i++){
        if(vet[i] == 0){
            vet[i] = Aux;
            i++;
        }
    }
}
/*stackoverflow.com/questions/34844003/changing-array-inside-function-in-c*/
int main(){
    int Tamam, Aux, *swaps, *result, i, turnos;
    printf ("informe o numero de elementos\n");
    scanf ("%d", &Tamam);
    result = malloc(Tamam * sizeof(result));

    printf ("informe o numero de turnos\n");
    scanf("%d", &turnos);
    swaps = malloc(Tamam * sizeof(swaps));
    printf("informe os swaps\n");
    for (i = 0; i < turnos; i++){
	    scanf ("%d", &Aux);
	    swaps[i]  = Aux;
    }
    for (i = 0; i < Tamam; i++)
      result[i] = 0;

    BolhaSort(result, swaps, turnos, Tamam);
    preenche(result, Tamam);

    for (i = 0; i < Tamam; i++)//imprimindo o vetor ordenado
      printf("%d\n", result[i]);
    return 0;
}
