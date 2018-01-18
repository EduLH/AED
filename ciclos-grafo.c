#include <stdio.h>
#include <stdlib.h>

/*coluna da matriz*/
typedef struct no{
    int ponte;
    struct no *prox;
}Tno;
typedef Tno* Pno;

/*lineador*/
typedef struct col{
    int posi;
    Pno line;
    struct col *prox;
}Tcol;
typedef Tcol* Pcol;

Pcol criaMES(int NC){//ok
    int i;
    Pcol nova, aux, last;
    aux = last = NULL;
    for(i = 1; i<=NC; i++){//alocando a coluna e numerando itens

        nova = malloc(sizeof(Tcol));
        nova->posi = i;//itens numerados
        nova->line = NULL;
        nova->prox = NULL;
        if(aux==NULL)//caso espec1
            aux = last = nova;
        else{//caso espec2 para inserir no ultimo
            last->prox = nova;
            last = nova;
        }
    }
    return aux;
}

Pno CriaNo(int ligacao){//ok
    Pno novo;
    novo = malloc(sizeof(Tno));
    novo->ponte = ligacao;
    novo->prox = NULL;
    return novo;
}

Pno Enfileirador(Pcol fornecedor){//aq enlista termos ligados do vertice OK

    Pno aux, aux2, last, novo;
    aux = aux2 = last = novo = NULL;
    for(aux = fornecedor->line; aux!=NULL; aux = aux->prox){
        novo = malloc(sizeof(Tno));
        novo->ponte = aux->ponte;
        novo->prox = NULL;
        if(aux2 == NULL)//caso espec
            aux2 = last = novo;
        else{
            last->prox = novo;
            last = novo;
        }
    }
    return aux2;//retorna o comeco da lista
}

int finder(int v, Pno l){//retorna 0/1 para se achar ok
    Pno ant = NULL;
    Pno p;
    int i;
    i = 0;
    for(p = l; p!=NULL && p->ponte!=v; p = p->prox)
        ant = p;
    if(p == NULL)
        return i; //nao achou retorna 0
    if(ant == NULL){
        l = p->prox; //retira do inicio
        i++;
    }
    else{
        ant->prox = p->prox;
        i++;
    }
    free(p);
    return i;

}

Pno removedor(int v, Pno l){//ok
    Pno ant = NULL;
    Pno p;
    for(p = l; p!=NULL && p->ponte!=v; p = p->prox)
        ant = p;
    if(p == NULL)
        return l; //nao achou retorna lista
    if(ant == NULL)
        l = p->prox; //retira do inicio
    else
        ant->prox = p->prox;
    free(p);
    return l;
}


Pcol vertFinder(int i, Pcol Colunas){//retorna um vertice OK
    Pcol aux;
    for(aux = Colunas; aux->posi != i; aux = aux->prox);
    return aux;
}

int main()
{
    int NC, Pts, i, destino, chegada, maior, menor, resultado, Mod;
    Pcol Nova, aux;
    Pno ligantes, auc, incidenci, novo;
    resultado = Mod = 0;
    novo = auc = NULL;
    aux = NULL;
    scanf("%d %d", &NC, &Pts);
    Nova = criaMES(NC);
    for(i = 1; i <= Pts; i++){//deixando as coisas prontas
        scanf("%d %d", &destino, &chegada);
        if(destino < chegada){//selecionando o menor dos 2
            menor = destino;
            maior = chegada;
        }
        else{
            maior = destino;
            menor = chegada;
        }
        aux = vertFinder(menor, Nova);//achando o vertice
        if(maior <= NC)
            novo = CriaNo(maior);//alocado o no
        if(aux->line == NULL){//caso espec
            aux->line = novo;
        }
        else{
            for(auc = aux->line; auc->prox!=NULL; auc = auc->prox);//alocado para a ultima linha
            auc->prox = novo;
        }
    }
    aux = Nova;
    ligantes = Enfileirador(aux);
    for(auc = ligantes; auc != NULL; auc = auc->prox)
        printf("%d ", auc->ponte);
    /*------------------OK-----------------*/
    for(i = 1; i < NC; i++){//comecando a contar os ciclos ESTOU NA LINHA I
        ligantes = removedor(i++, ligantes);//para remover o iten da linha atual
        printf("---point---2\n");
        aux = aux->prox;
        for(auc = aux->line; auc != NULL; auc = auc->prox){
            resultado = resultado + finder(auc->ponte, ligantes);//verifico se existe ciclo na lista
            ligantes = removedor(i++, ligantes);//para remover o iten da lista
            printf("---point---b\n");

            /*if(finder(auc->ponte, ligantes) == 1){//removendo da matriz para quando for adicionar com o Enfileirador, nao ocorrer erro de reaparecer o numero
                printf("---point---c\n");
                while(incidenci != NULL){
                    printf("---point---d\n");
                    incidenci = aux->line;//estou na linha para remover incidencias
                    if(incidenci->ponte == auc->ponte){//caso no inicio
                        aux->line = aux->line->prox;
                        free(incidenci);
                        incidenci = NULL;
                    }
                    else{//outros
                        while(incidenci->prox != auc)
                            incidenci = incidenci->prox;
                        incidenci->prox = auc->prox;
                        free(auc);
                        auc = NULL;
                        incidenci = NULL;
                    }
                }
            }
        }*/
        ligantes = Enfileirador(aux);//adiciono a lista sem incidencias a lista atual
    }
    printf(" %d \n", resultado);
}
