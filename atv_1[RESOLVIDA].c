#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct{
    int info;
    int prox;
} NO;

typedef struct{
    NO lista[max];
    int dispo;
    int L;
} LISTA;

void inicializaDispo(LISTA* L)
{
    L->dispo = 0;
    L->L = -1;
    L->lista[max - 1].prox = - 1;

    for(int i = 0; i < max - 1; i++)
    {
        L->lista[i].prox = i + 1;
        L->lista[i].info = -1;
    }

}

void insertNo(LISTA* lista, int info)
{
    int noDispo = lista->dispo;
    lista->dispo = lista->lista[lista->dispo].prox;

    if(lista->L == -1 || lista->lista[lista->L].info > info)
    {
        lista->lista[noDispo].info = info;
        lista->lista[noDispo].prox = lista->L;
        lista->L = noDispo;
        return;
    }

    int prev = lista->L;
    int atual = lista->lista[lista->L].prox;

    while (atual != -1 && lista->lista[atual].info < info)
    {
        prev = atual;
        atual = lista->lista[atual].prox;
    }

    lista->lista[noDispo].info = info;
    lista->lista[noDispo].prox = atual;
    lista->lista[prev].prox = noDispo;
}



void removeIntervalo(LISTA* lista, int vi, int vf)
{
    int* ponteiroProxNo = &lista->L;
    int ultimoNo = -1;

    while (*ponteiroProxNo != -1 && lista->lista[*ponteiroProxNo].info < vi)
    {
        ultimoNo = *ponteiroProxNo;
        ponteiroProxNo = &lista->lista[*ponteiroProxNo].prox;
    }

    while (*ponteiroProxNo != -1 && lista->lista[*ponteiroProxNo].info <= vf)
    {
        int proximo = lista->lista[*ponteiroProxNo].prox;
        lista->lista[*ponteiroProxNo].prox = lista->dispo;
        lista->dispo = *ponteiroProxNo;
        *ponteiroProxNo = proximo;
    }

    if (ultimoNo != -1) {
        *ponteiroProxNo = -1;
    }
}


void imprimeLista(LISTA* lista)
{
    int atual = lista->L;

    if(lista->L == -1)
    {
        printf("\nA lista esta vazia");
        return;
    }

    printf("\nA lista eh composta por:");

    while (atual != -1)
    {
        printf("\n%d", lista->lista[atual].info);
        atual = lista->lista[atual].prox;
    }
}

int main(){

    LISTA lista;

    inicializaDispo(&lista);
    insertNo(&lista,5);
    insertNo(&lista,7);
    insertNo(&lista,13);
    insertNo(&lista,17);
    insertNo(&lista,9);
    insertNo(&lista,15);
    imprimeLista(&lista);
    removeIntervalo(&lista,8,22);
    imprimeLista(&lista);


}
