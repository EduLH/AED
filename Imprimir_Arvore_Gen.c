#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENTACAO DAS FUNCOES DA ARVORE*/
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

TipoNo *global;

void *busca(int X, TipoNo *tree){

    if(tree != NULL){
        if (tree->num == X){
            global = tree;
            return;
        }
        else{
            if(tree->esq != NULL)
                busca(X, tree->esq);
            if(tree->dir != NULL)
                busca(X, tree->dir);
        }
    }
}

void imprime(TipoNo *no){
    if(no==NULL)
        return;
    printf("(%d",no->num);
    imprime(no->esq);
    printf(")");
    imprime(no->dir);
}

int main(){
    int N, M, a, b, i;
    TipoNo *pno, *aux, *tree;
    scanf("%d %d", &N, &M);
    scanf("%d %d", &a, &b);
    tree = criaNo(a);
    pno = criaNo(b);
    tree->esq = pno;
    for(i = 0; i != M-1; i++ ){
        scanf("%d %d", &a, &b);
        busca(a, tree);
        aux = global;
        //printf("buscou %i\n", aux->num);
        if(aux->esq == NULL){
            aux->esq = criaNo(b);
           //printf("foi null\n");
        }
        else{
            //printf("nao foi null\n");
            aux = aux->esq;
            //printf("primeiro irmao %d\n", aux->num);
            while(aux->dir != NULL){
                aux = aux->dir;
                //printf("chegou no ultimo irmao %d\n", aux->num);
            }
            aux->dir = criaNo(b);
            //printf("criou\n");
        }
    }
    imprime(tree);
    return 0;
}
