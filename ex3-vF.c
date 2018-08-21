//Marcos Eduardo Lopes Honorato 86379
//Robinson Alves Junior 86942

#include <stdio.h>
#include <stdlib.h>

typedef struct no {// no
     int str;
     int reco;
     int num;
     struct no* prox;
} TNo;
typedef TNo *PNo;

typedef struct fila {// enfileirador
    PNo ini;
    PNo fim;
} TFila;
typedef TFila *PFila;

PFila iniciaFila( PFila line){//inicia enfileirador VAZIO
    PFila f = (PFila) malloc(sizeof(TFila));
    f->ini = f->fim = NULL;
    return f;
}

PFila insere(PFila Line, int nume){//inserindo na FILA

    int inSTR;
    PNo NOVO;
    scanf("%d", &inSTR);
    NOVO = (PNo) malloc(sizeof(TNo));
    NOVO->str = inSTR;
    NOVO->reco = inSTR;
    NOVO->prox = NULL;
    NOVO->num = nume;
    if(Line->ini == NULL){
        Line->ini = NOVO;
        Line->fim = NOVO;

    }
    else{
        Line->fim->prox = NOVO;
        Line->fim = NOVO;
    }
    return Line;
}

PFila FIGHT(PFila line,int heal){// tem que colocar a condicao pra verificar se tem ao menos 2 na main
//vai ser adicionada a condição de RECUPERACAO(reco)
    PNo P1, P2, winer;
    P1 = line->ini;
    P2 = P1->prox;
    if (P2->reco <= P1->reco){//o tanto que o ganhador ficar de energia SERA OQ ELE RECUPEROU(reco)
        winer = P1;
        winer->reco = P1->reco - P2->reco;
        line->fim->prox = P1; //inicio para dar FREE nos ponteiros //ganhador vai pro final da fila
        line->ini = P2->prox;
        line->fim = P1;
        P1->prox = NULL;
        free(P2);//p2 perdeu
    }
    else{
        winer = P2;
        winer->reco = P2->reco - P1->reco;
        line->fim->prox = P2; //inicio para dar FREE nos ponteiros //ganhador vai pro final da fila
        line->ini = P2->prox;
        line->fim = P2;
        P2->prox = NULL;
        free(P1);//p1 perdeu
    }
    //iniciando processo de recuperaca1
    if(winer->reco + heal >= winer->str)
        winer->reco = winer->str;
    else
        winer->reco = winer->reco + heal;
    //fim recuperaca1
    return line;
}

int main(){
    int N, heal, i;
    float tot;
    PFila ffila;
    ffila = iniciaFila(ffila);https://www.youtube.com/watch?v=xos2MnVxe-c
    scanf("%d %d", &N, &heal);
    tot = pow(2, N);
    //aqui ja comeca a escanear as forcas e td
    for(i = 1; i < tot+1; i++){
        ffila = insere(ffila, i);
    }
    while(ffila->fim->num != ffila->ini->num){// condicao para lutarem sempre diferentes
        ffila = FIGHT(ffila, heal);
    }

    printf("%d", ffila->ini->num);
}
