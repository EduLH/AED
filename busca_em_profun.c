#include <stdio.h>
#include <stdlib.h>

/*lista de adja*/
typedef struct no{
    int chave;
    struct no *prox;
}Tno;
typedef Tno* Pno;

/*item de utilidades passado em AED2*/
typedef struct no_util{
    int distancia;  //para utilizar na distancia
    int pai;    //para utilizar na consulta do pai
    int chave;  //chave do NO atual
    struct no_util *prox;
}Tno_util;
typedef Tno_util* Pno_util;

/*coluna*/
typedef struct col{
    int chave, visited; //visited eh a parte da 'coloracao'
    Pno lista;
    struct col *prox;
}Tcol;
typedef Tcol* Pcol;

Pcol Cria_vertebra(int col_chave, Pcol coluna){	//criando a coluna do grafo...
  //Esqueci o nome do termo ai botei coluna msm

  Pcol coluna_aux, ultimo_item;	//c_aux ira quardar o ponteiro pra coluna
                                //u_item ira guardar o final da coluna

  if(coluna == NULL){
    coluna_aux = malloc(sizeof(Tcol));
    coluna_aux->chave = col_chave;
    coluna_aux->visited = 0;
    coluna_aux->lista = NULL;
    coluna_aux->prox = NULL;
    return(coluna_aux); //criou coluna
  }

  for(coluna_aux = ultimo_item = coluna;
	  ultimo_item->prox != NULL;
	  ultimo_item = ultimo_item->prox){	//para acessar a ultima vertebra
      if(ultimo_item->chave == col_chave)
      return(coluna);	//vertebra ja existe
  }

  ultimo_item->prox = malloc(sizeof(Tcol));	//pra n ter q declarar mais variaveis
  ultimo_item = ultimo_item->prox;	//att o u_item
	ultimo_item->chave = col_chave;
  ultimo_item->lista = NULL;
  ultimo_item->prox = NULL;

  return(coluna_aux);
}

Pcol Encontra_vertebra(int chave_vertebra, Pcol Coluna){
  Pcol vertebra_aux;
  //esse FOR esta assim para nao "ficar mto longo"
  for(vertebra_aux = Coluna;
      vertebra_aux != NULL;
      vertebra_aux = vertebra_aux->prox) {

    if(vertebra_aux->chave == chave_vertebra)
      return(vertebra_aux);	//achou e retorna o ponteiro
  }
  return(NULL);	//nao achou
}

void Popula_vertebra(int chave_vertebra, int chave_lista, Pcol Coluna){
  Pcol vertebra = Encontra_vertebra(chave_vertebra, Coluna);
  //para encontrar a vertebra a ser "populada"
  //"populada" = colocar as ligacoes
  int chave;
  Pno ultimo_item;	//para nao ficar percorrendo a lista toda hora

  if (vertebra == NULL)//Se nao existe, cria uma VERTEBRA com a CHAVE
	  vertebra = Cria_vertebra(chave_vertebra, Coluna);

  if (vertebra->lista == NULL){
    ultimo_item = vertebra->lista;
    ultimo_item = malloc(sizeof(Tno));
    ultimo_item->chave = chave;
    ultimo_item->prox = NULL;
  }
  else{
    for(ultimo_item = vertebra->lista;
        ultimo_item->prox != NULL;
  	    ultimo_item = ultimo_item->prox){	//ir para ultimo item da lista
  		   if(ultimo_item->chave == chave_lista)
  			    return;	//item ja inserido na lista
    }
      ultimo_item->prox = malloc(sizeof(Tno));
      ultimo_item = ultimo_item->prox;
      ultimo_item->chave = chave;
      ultimo_item->prox = NULL;
	}
	return;	//inseriu com sucesso
}

void analisa_entrada(int vertebra, int chave_no, int operacao, Pcol coluna){
	switch(operacao){	//condicoes passadas no PDF da aula de AEDII (2018/1)
		case 1:
			Popula_vertebra(vertebra, chave_no, coluna);
			break;
		case 2:
			Popula_vertebra(vertebra, chave_no, coluna);
			Popula_vertebra(chave_no, vertebra, coluna);
			break;
	}
  return;
}

void Pega_entrada(int descricoes, Pcol coluna){//p Main
	int i, chave_vertebra, chave_lista, operacao;

	for(i = 0; i < descricoes; i++){ //le inputs e cria Vertb e Listas
		scanf("%i %i %i", &chave_vertebra, &chave_lista, &operacao);
		if (Encontra_vertebra(chave_vertebra, coluna) == NULL){
			coluna = Cria_vertebra(chave_vertebra, coluna); //caso ainda n existam Vertebras
			analisa_entrada(chave_vertebra, chave_lista, operacao, coluna);
		}
		else
			analisa_entrada(chave_vertebra, chave_lista, operacao, coluna);
	}
  return;
}

/*--------ate aqui foi parte de gerar o grafo--------*/

/*---------------------------------------------------*/

/*-----aqui comeca parte d busca em profundidade-----*/

int not_in(int target, Pno_util lista_util){
Pno_util walker;

  for(walker = lista_util; walker != NULL; walker = walker->prox){
    if(walker->chave == target)
      return(1); //Encontrou o item!
  }
  return(0);  //nao encontrou o item
}

Pno_util Gera_lista_util(Pcol Coluna){ //p Main
  //metodologia de BuscEmProfun dada na aula de AED2

  Pcol coluna_aux = Coluna;
  Pno_util Util, ultimo_item;
  Util = malloc(sizeof(Tno_util));
  Util->pai = -1; //para indicar que foi iniciada
  ultimo_item = Util;

  for( ;coluna_aux != NULL; coluna_aux = coluna_aux->prox){
    if(Util->pai == -1 || not_in(coluna_aux->chave, Util) == 0){
      if(ultimo_item != NULL)
        ultimo_item = ultimo_item->prox;
      ultimo_item = malloc(sizeof(Tno));
      ultimo_item->chave = coluna_aux->chave; //apenas um item por chave
      ultimo_item->pai = 0;
      ultimo_item->distancia = 9999; // ¯\_(ツ)_/¯
    }
  }
  return (Util);
}

Pno_util Busca_item_util(int chave, Pno_util lista_util){
  //busca um item na lista_util
  Pno_util Aux;
  for(Aux = lista_util; Aux != NULL; Aux = Aux->prox){
    if(Aux->chave == chave)
      return(Aux);
  }
  return(NULL);
}

void Busca_Largura(Pcol Comeco, Pcol Coluna, Pno_util Vet_util){//p Main

  Pno_util Muda_item, Util_comeco;
  Pno lista;
  Util_comeco = Busca_item_util(Comeco->chave, Vet_util);

  for (lista = Comeco->lista; lista != NULL; lista = lista->prox){
    Muda_item = Busca_item_util(lista->chave, Vet_util);

    //att os dados do item na lista_util
    if(Muda_item->distancia > Util_comeco->distancia){
      Muda_item->distancia = Util_comeco->distancia;
      Muda_item->pai = Util_comeco->chave;
    }
  }

  if(Comeco->visited == 1)
    return;

  Comeco->visited = 1;

  for (lista = Comeco->lista; lista != NULL; lista = lista->prox){
    Busca_Largura(Encontra_vertebra(lista->chave, Coluna), Coluna, Vet_util);
  }

  return;
}

void set_inicio(Pcol Coluna, Pno_util Vet_util){
  //seta a listaUtil para p primeiro item
  Pno_util primeiro = Busca_item_util(Coluna->chave, Vet_util);
  primeiro->distancia = 0;
  primeiro->pai = -1;
  return;
}

int prontinho(Pno_util lista_util){
  Pno_util walker = lista_util;
  for(; walker!= NULL; walker = walker->prox){
    if(walker->pai == 0 && walker->distancia ==  9999)
      return 0; //nao foi visitado todo o grafo
  }
  return 1; //foi visitado todo o grafo
}

void main(){
  int num_ruas, descricoes, valida;
  scanf("%i %i", &num_ruas, &descricoes);
  Pcol grafo;
  Pno_util lista_util;

  Pega_entrada(num_ruas, grafo);
  lista_util = Gera_lista_util(grafo);
  set_inicio(grafo, lista_util);

  Busca_Largura(grafo, grafo, lista_util);

  valida = prontinho(lista_util);

  printf("%i", valida);

}
