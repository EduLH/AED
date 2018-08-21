#include <stdio.h>
#include <stdlib.h>
/*
Trabalho para a dissiplina de AED-II d na UNIFESP
Marcos Eduardo Lopes Honorato. RA: 86379
Este arquivo é de intuito didático apenas
*/
/*
                    ATENÇÃO!
FALTA IMPLEMENTAR A REMOÇÃO E VERIFICADOR DE ÁRVORE
*/

typedef struct TipoNo{
    int num;
    struct TipoNo *esq,*dir;
}TipoNo;

TipoNo *criaNo(int num){
    TipoNo *no;
    no = malloc(sizeof(TipoNo));
    no->num = num;
    no->dir = NULL;
    no->esq = NULL;
    return no;
}
void imprimePRE(TipoNo *no){
    if(no==NULL)
        return;
    printf("%d",no->num);
    imprimePRE(no->esq);
    imprimePRE(no->dir);
}
void imprimeEM(TipoNo *no){
    if(no==NULL)
        return;
    imprimeEM(no->esq);
    printf("%d",no->num);
    imprimeEM(no->dir);
}
void imprimePOS(TipoNo *no){
    if(no==NULL)
        return;
    imprimePOS(no->esq);
    imprimePOS(no->dir);
    printf("%d",no->num);
}

int altura (TipoNo *arvore) {
  if (arvore == NULL)
    return 0;
  else {
    int he = altura (arvore->esq);
    int hd = altura (arvore->dir);
    if(he < hd)
      return hd+1;
    else
      return he+1;
  }
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

int HDHE(TipoNo *no){
  int E,D;
  E = altura(no->esq);
  D = altura(no->dir);
  return(D-E);
}

void Inserir(TipoNo *no, int chave){
  if(no == NULL){
    criaNo(chave);
    return;
  }
  else{
    if(chave > no->num){
      if(no->dir != NULL)
        Inserir(no->dir, chave);
      else
        no->dir = criaNo(chave);
    }
    else{
      if(no->esq != NULL)
        Inserir(no->esq, chave);
      else
        no->esq = criaNo(chave);
    }
  }
}



void remover(TipoNo *no){
  TipoNo *aux, *pai;
  if(no->dir != NULL){
    aux = no->dir;
    while (aux->esq != NULL)
      pai = aux;
      aux = aux->esq;

  }
  else
    aux = no->esq;

}

void verificaTam(TipoNo *no){
  if(HDHE(no) <= 1)
    return;
  else
    if (HDHE(no) == -2 && HDHE(no->esq) == -1)
      rotDir(no);
    if (HDHE(no) == 2 && HDHE(no->dir) == 1)
      rotEsq(no);
    if (HDHE(no) == -2 && HDHE(no->esq) == 1)
      DoubleRotDir(no);
    if ((HDHE(no) == 2 && HDHE(no->dir) == -1))
      DoubleRotEsq(no);
}

/*cria um treeor com valores aleatórios e retorna o ponteiro pro treeor*/
int* treeRand1k(){//perguntar pro Nathan
  int i, a, *j, *randomico;
  randomico = malloc(1000 * sizeof(int));
  for (i = 0; i != 999; i++){
    randomico[i] = rand() % 10000;
  }
  j = randomico;
  return j;
}

int sequencial(int *treeor, int target){
  int i;
  for (i = 0; i != 999; i++){
    if (treeor[i] == target)
      return i;
  return -1;//nao achou
}
/*
int *binaria(int *Zeca, int target, int init, int fim){
  int mid;
  mid = ((fim-init)/2) + init;
  if (init == fim && Zeca[init] == target)
    return init;
  if (fim - init <= 2){
    if (Zeca[init+1] == target)
      return init+1;
    if (Zeca[init+2] == target)
      return init+2;
  }
  if (Zeca[mid] > target)
    binaria(Zeca, target, mid, fim);
  if (Zeca[mid] < target)
    binaria(Zeca, target, init, mid);
  return -1;
}*/

TipoNo *arvoreBusca(int X, TipoNo *tree){

  if(tree != NULL){
    if (tree->num == X)
        return tree; //achou
    else{
      if(tree->esq != NULL)
        arvoreBusca(X, tree->esq);
      if(tree->dir != NULL)
        arvoreBusca(X, tree->dir);
    }
  }
  return  NULL; //nao achou
}

int main(){
    int i, aux;
    TipoNo *tree;
    tree = NULL;
    i = 1;
    while(i==1) {
        scanf("%i", &aux);
        if(aux > 0){
          if(tree == NULL){
            tree = criaNo(aux);
          }
          else{
            tree = Inserir(tree, aux);
          }
        }
        else{
          i = 0;
        }
    }
    scanf("%i", &aux);
    tree = busca(tree, aux);
    aux = conta(tree);
    printf("%i\n", aux-1);
    return 0;

}
