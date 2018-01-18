#include <stdio.h>
#include <stdlib.h>
int TotalDeCombinacoes = 0;

void troco(int *caixa, int Goal, int Tamam){
    int n,  i;
    n = Tamam;
    if(Goal < 0)     //caso de pegar troco a mais
        return;

    if(Goal == 0)    //caso de pegar o troco desejado
        TotalDeCombinacoes++;

    else{                   //ainda falta troco
        for(i = 0; i!= n; i++){
            troco(caixa, Goal-caixa[i], Tamam);
        }
    }
}

int main(){
    int Tamam, Aux, *Zeca, i, trocos, goal;
    scanf ("%d", &goal);

    scanf ("%d", &Tamam);

    Zeca = malloc(Tamam * sizeof(Zeca));
    for (i = 0; i < Tamam; i++){
	    scanf ("%d", &Aux);
	    Zeca[i]  = Aux;
    }
    troco(Zeca, goal, Tamam);
    printf("%d\n", TotalDeCombinacoes);
}
