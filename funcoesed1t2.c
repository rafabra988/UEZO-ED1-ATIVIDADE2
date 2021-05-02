#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoesed1t2.h"

struct elemento{
    int info;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Elemento * ini_ponto;
Elemento * ult_ponto;

void FilaVazia(){
    Elemento *aux;
    aux=(Elemento*)malloc(sizeof(Elemento));
    ini_ponto=aux;
    ult_ponto=aux;
}

void inserir(int add){
    Elemento *aux;
    aux=(Elemento*)malloc(sizeof(Elemento));
    aux->info = add;
    ult_ponto->prox=aux;
    ult_ponto=ult_ponto->prox;
    aux->prox=NULL;
}

void imprimir(){
    Elemento *aux;
    aux= ini_ponto->prox;
    while(aux!=NULL){
        printf("%d -> ",aux->info);
        aux=aux->prox;
    }
    printf("NULL");
}

void pesquisar(int x){
    int cont=0;
    Elemento *aux;
    aux= ini_ponto->prox;
    while(aux!=NULL){
        if(x==aux->info){
            printf("elemento encontrado");
            cont=1;
            aux=NULL;
        }else{
            aux=aux->prox;
        }
    }
    if(!cont){
        printf("elemento n�o foi encontrado");
    }

}

void remover(int x){
    int cont=0;
    Elemento *segundaux;
    Elemento *aux;
    aux= ini_ponto->prox;
    segundaux=ini_ponto;
    while(aux!=NULL){
        if(x==aux->info){
            printf("elemento removido");
            cont=1;
            segundaux->prox = aux->prox;
            free(aux);
        }else{
            segundaux=aux;
            aux=aux->prox;
        }
    }
    if(!cont){
        printf("elemento n�o foi encontrado");
    }

}

//__________________________________________ex1___________________________________________
void ordenar(){
    Elemento *aux=ini_ponto;
    while(aux != NULL){
        Elemento *segundaux=aux->prox;
        while(segundaux!=NULL){
            if(aux->info > segundaux->info){
                int temp = aux->info;
                aux->info = segundaux->info;
                segundaux->info = temp;
            }
            segundaux=segundaux->prox;
        }
        aux=aux->prox;
    }
}

void removdup(){
    ordenar();
    Elemento *segundaux, *aux;
    aux= ini_ponto;
    segundaux=ini_ponto;
    while(aux!=NULL){
        if(aux->info == segundaux->info){
            segundaux->prox=aux->prox;
            free(aux);
            aux=segundaux->prox;
        }else{
            segundaux=aux;
            aux=aux->prox;
        }
    }
}

//__________________________________________ex2___________________________________________

void pulareapagar(int m, int n){
    Elemento *segundaux;
    Elemento *aux;
    aux= ini_ponto->prox;
    segundaux=ini_ponto;
    while(aux!=NULL){
        for(int i=0;i<m;i++){
            if(aux!=NULL){
                segundaux=aux;
                aux=aux->prox;
            }
        }
        for(int i=0;i<n;i++){
            if(aux!=NULL){
                segundaux->prox=aux->prox;
                free(aux);
                aux=segundaux->prox;
            }

        }
    }
}

//__________________________________________ex3___________________________________________

void movinit(){
    Elemento *segundaux;
    Elemento *aux;
    Elemento *tercaux;
    aux= ini_ponto->prox;
    segundaux=ini_ponto;
    tercaux=ini_ponto->prox;
    tercaux=tercaux->prox;
    while(aux!=NULL){
        segundaux=aux;
        aux=aux->prox;
    }
    int p=ini_ponto->prox;
    ini_ponto->prox=aux;
    ini_ponto->prox=p;
    free(aux);
}
