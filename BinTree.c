#include <stdio.h>
#include <stdlib.h>

typedef struct TipoNo{
    int num;
    struct TipoNo *esq,*dir;
}TipoNo;

TipoNo *criaNo(int val){
    TipoNo *no;
    no = malloc(sizeof(TipoNo));
    no->num = val;
    no->dir = NULL;
    return no;
}

TipoNo *insereNo(TipoNo *vet, int new){
    TipoNo *aux;
    aux = vet;
    if(aux == NULL)
        return (criaNo(new));
    else{
        while(aux->dir != NULL)
            aux = aux->dir;
        aux->dir = (criaNo(new));
    }
    return vet;
}

TipoNo *remova(TipoNo *vet, int target){
    TipoNo *aux, *hold;
    aux = vet;
    if(aux == NULL)
        return (vet);
    else{
        while(aux->dir != NULL){
            if(aux->dir->num == target){
                hold = aux->dir;
                aux->dir = aux->dir->dir;
                free(hold);
            }
        }
    }
    return(vet);
}

TipoNo *busca(TipoNo *no, int target){
    TipoNo *aux;
    if(no==NULL)
        return(insereNo(no, target));
    else{
        if
        for(aux=vet; aux!=NULL; aux = aux->dir){
            if(aux->num == target)
                return (vet);
        }
    }
    return(insereNo(vet, target));
}

void main(){
    int i, aux;
    TipoNo *vet;
    vet = NULL;
    i = 1;
    while(i==1) {
        scanf("%i", &aux);
        if(aux > 0){
          if(vet == NULL){
            vet = criaNo(aux);
          }
          else{
            vet = insereNo(vet, aux);
          }
        }
        else{
          i = 0;
        }
    }
    scanf("%i", &aux);
    vet = busca(vet, aux);
    aux = conta(vet);
    printf("%i\n", aux-1);

}
