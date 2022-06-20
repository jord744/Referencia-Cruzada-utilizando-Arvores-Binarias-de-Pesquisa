#include <stdio.h>
#include <stdlib.h>

struct letra{
  char letra;
  struct letra *prox;
  struct palavra *arvoreBinaria;
};
typedef struct letra LETRA;

struct palavra{
  char palavra[30];
  int ocorrencias;
  struct palavra *esq;
  struct palavra *dir;
};

typedef struct palavra PALAVRA;

struct indice{
  struct letra *inicio;
  struct letra *fim;
};

typedef struct indice INDICE;

void inicializa_tabela(INDICE tabela[]){
  for(int i = 0; i < 26; i++){
    tabela[i].inicio = NULL;
    tabela[i].fim = NULL;
  }
}

void insere_letras(INDICE tabela[]){
  for(int i = 97; i < 123; i++){
    LETRA *nodo = (LETRA *)malloc(sizeof(LETRA));
    nodo -> letra = i;
    nodo -> prox = NULL;
    nodo -> arvoreBinaria = NULL;

    int chave = 26 % 10;

    if(tabela[chave].inicio == NULL){
      tabela[chave].inicio = nodo;
      tabela[chave].fim = nodo;
    } else {
      tabela[chave].fim -> prox = nodo;
      tabela[chave].fim = nodo;
    }
  }
}

void escreve_tabela(INDICE tabela[]){
    int i;

    for(i=0; i<26; i++){
        
        LETRA *aux = tabela[i].inicio;
        while ( aux != NULL ){
            printf("%c\n", aux-> letra);
            aux = aux->prox;
        }
        
    }
}


int main(void) {

  INDICE tabela[26];
  
  inicializa_tabela(tabela);

  insere_letras(tabela);

  escreve_tabela(tabela);


  
  return 0;
}