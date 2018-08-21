#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Trabalho para a dissiplina de AED-II d na UNIFESP
Marcos Eduardo Lopes Honorato. RA: 86379
Este arquivo é de intuito didático apenas
*/

typedef struct aluno{
    int nota;
    char nome[25];
}Taluno;

bool EhFolha(int index, int tamanho){
      if (index < int(tamanho/2))
          return true;
      else
          return false;
}

void novoAluno(Taluno *classe, int index){
      Taluno novato = malloc(sizeof(Taluno));
      printf("Informe o Nome do aluno\n");
      scanf("%s\n", novato.nome);
      printf("informe a nota do aluno\n");
      scanf("%i\n", novato.nota);
      printf("[%s, ua%i]\n", novato.nome, novato.nota);

      classe[index] = novato;
      return;
}


void refaz(Taluno *classe, int index, int tamanho){
    Taluno aux = classe[index];
    int indFil = index*2;

    while (EhFolha(index, tamanho) == true) {

        if ((indFil+1 <= tamanho-1 && classe[indFil+1] != NULL){//existe F-dir
            if(classe[indFil].nota <= classe[indFil+1].nota){  //compara notas esq-dir
                if(classe[index].nota < classe[indFil+]){    //compara notas pai-dir
                    classe[index] = classe[indFil];
                    index = indFil;   //swap
                }
            }
            else{
                if(classe[index].nota < classe[indFil].nota){//compara nota pai-esq
                  classe[index] = classe[indFil+1];
                  index = indFil+1;
                }
                else break; //nao e menor que os filhos
            }
        }

        else{//caso dir n existe, esq existe
            if(classe[index].nota < classe[indFil]){//compara notas pai-esq
                classe[index] = classe[indFil];
                index = indFil;   //swap
            }
            else break; //nao e menor que o esq
        }
    }
    return;
}
