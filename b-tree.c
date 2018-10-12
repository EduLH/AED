#include <stdio.h>
#include <stdlib.h>
/*
Trabalho para a matéria de AED-II na UNIFESP
Marcos Eduardo Lopes Honorato. RA: 86379
Este arquivo é de intuito didático apenas
*/

typedef struct TipoB{
    struct TipoB *filho;
    struct TipoNo *nos;
    int numNos;
}TipoB;

typedef struct TipoNo{
    int num;
    struct TipoNo *prox;
    struct TipoB *filhos;
}TipoNo;

TipoNo *criaNo(int num){
    TipoNo *no;
    no = malloc(sizeof(TipoNo));
    no->num = num;
    no->prox = NULL;
    no->filhos = NULL;
    return no;
}

TipoNo *criaTipoB(){
    TipoB *no;
    no = malloc(sizeof(TipoB));
    no->filho = NULL;
    no->nos = NULL;
    no->numNos = 0;
    return no;
}

void InsereNo(TipoNo *no, TipoB *Btree){

  if(Btree->numNos <4){
    TipoNo *aux;
    aux = Btree->nos
    while
  }

}
