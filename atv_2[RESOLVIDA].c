#include <stdio.h>
#include <stdlib.h>

typedef struct CELULA{

    int info;
    struct CELULA* prox;

} CELULA;

typedef struct{

    int nElements;
    CELULA* head;

} LISTA;

void bootLista(LISTA** l){

    (*l)->nElements = -1;
    (*l)->head = NULL;
}

CELULA* getNO(LISTA** dispo){

    if((*dispo)->head == NULL)
    {
        printf("Não existem nós disponíveis");
        return NULL;
    }

    CELULA* newCelula = (*dispo)->head;
    (*dispo)->head = (*dispo)->head->prox;

    return newCelula;

}

void criaNO(LISTA** dispo){

    CELULA* newCelula = (CELULA*)malloc(sizeof(CELULA));

    if(newCelula == NULL){

        printf("\nFalha na alocação (1)");

        return;
    }

    if((*dispo)->head == NULL)
    {
        newCelula->prox = NULL;
        (*dispo)->head = newCelula;

        return;
    }

    newCelula->prox = (*dispo)->head;
    (*dispo)->head = newCelula;
    
}

void insertOrdenado(LISTA** l, LISTA ** dispo, int elem){

    CELULA* newCelula = getNO(dispo);

    if(newCelula == NULL){

        printf("\nA alocação falhou (0)");
        return;
    }

    newCelula->info = elem;
    newCelula->prox = NULL;

    // First Insertion;

    if((*l)->head == NULL || (*l)->head->info > elem){

        newCelula->prox = (*l)->head;
        (*l)->head = newCelula;
        (*l)->nElements++;
        return;
    }

    // All Insertion;

    CELULA* i = (*l)->head;

    while(i->prox != NULL && i->prox->info < elem){

        i = i->prox;
    }

    newCelula->prox = i->prox;
    i->prox = newCelula;

}

void removeIntervalo(LISTA** l, LISTA** dispo, int vi, int vf){

    CELULA* i = (*l)->head;
    CELULA* prev = NULL;

    while(i != NULL && i->info < vi){

        prev = i;
        i = i->prox;

    }

    while(i != NULL && i->info <= vf){

        CELULA* aux = i->prox;
        i->prox = (*dispo)->head;
        (*dispo)->head = i;
        i = aux;
    }

    if(prev == NULL){

        (*l)->head = i;

    }else{

        prev->prox = i;
    }

    return;

}

void printList(LISTA *l)
{
    CELULA* i = l->head;

    printf("\nA lista eh composta por: ");

    while(i != NULL){

        printf("\n%d",i->info);
        i = i->prox;

    }
}

int main(){

    LISTA *l = (LISTA *)malloc(sizeof(LISTA));
    LISTA *dispo = (LISTA *)malloc(sizeof(LISTA));

    bootLista(&l);
    bootLista(&dispo);

    criaNO(&dispo);
    criaNO(&dispo);
    insertOrdenado(&l,&dispo,10);
    insertOrdenado(&l,&dispo,5);
    removeIntervalo(&l,&dispo,10,11);
    insertOrdenado(&l,&dispo,3);
    printList(l);

    free(l);
    free(dispo);
}