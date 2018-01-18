#include <stdio.h>
#include <stdlib.h>
/*
Trabalho para a dissiplina de AED-II d na UNIFESP
Marcos Eduardo Lopes Honorato. RA: 86379
Este arquivo é de intuito didático apenas
*/

typedef struct TipoNo{
    int num;
    struct TipoNo *esq,*dir,*pai;
    int cor;//0-red 1-black
}TipoNo;

TipoNo *criaNo(int num){
    TipoNo *no;
    no = malloc(sizeof(TipoNo));
    no->num = num;
    no->dir = NULL;
    no->esq = NULL;
    no->pai = NULL;
    no->cor = 0;
    return no;
}

void verificaInsert(TipoNo *no){
  TipoNo *y;
  if (no.pai != NULL && no.pai.pai != NULL){
    while (no.pai.cor == 0) {
      if (no.pai == no.pai.pai.esq) { //caso para no na esquerda
        y = no.pai.pai.dir; //tio
        if (y.cor == 0) {
          no.pai.cor = 1;     //caso1
          y.cor = 1;          //caso1
          no.pai.pai.cor = 0; //caso1
          no = no.pai.pai;    //caso1
          return;
        }
        else{
          if (no == no.pai.dir) {
            no = no.pai;      //caso2
            rotEsq(no);       //caso2
            return;
          }
          no.pai.cor = 1;     //caso3
          no.pai.pai.cor = 0; //caso3
          rotDir(no.pai.pai); //caso3
          return;
        }
      }
      else{                           //caso para no na direita
        y = no.pai.pai.esq; //tio
        if (y.cor == 0) {
          no.pai.cor = 1;     //caso1
          y.cor = 1;          //caso1
          no.pai.pai.cor = 0; //caso1
          no = no.pai.pai;    //caso1
          return;
        }
        else{
          if (no == no.pai.esq) {
            no = no.pai;      //caso2
            rotDir(no);       //caso2
            return;
          }
          no.pai.cor = 1;     //caso3
          no.pai.pai.cor = 0; //caso3
          rotEsq(no.pai.pai); //caso3
          return;
        }
      }
    }
  }
  else return;
}

void rotEsq(TipoNo *no){
  TipoNo *aux;
  aux = no->dir;
  no->dir = aux->esq;
  aux->esq = no;
}

void rotDir(TipoNo *no){
  TipoNo *aux;
  aux = no->esq;
  no->esq = aux->dir;
  aux->dir = no;

}

void DoubleRotDir(TipoNo *no){
  rotEsq(no->esq);
  rotDir(no);
}

void DoubleRotEsq(TipoNo *no){
  rotDir(no->dir);
  rotEsq(no);
}
