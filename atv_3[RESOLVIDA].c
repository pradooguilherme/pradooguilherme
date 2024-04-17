#include <stdio.h>
#include <stdlib.h>

struct info{
    int numb;
    int clasf;
};

typedef struct info Info;

struct elemento{

    Info* aluno;
    struct elemento* prox;

};

typedef struct elemento Elemento;

Elemento* iniciarLista(){
    return NULL;
}

Elemento* novoDado(){
    int numb,clasf;

    printf("\nInsira o número do aluno: ");
    scanf("%d",&numb);

    printf("\nInsir a classificação do aluno: ");
    scanf("%d",&clasf);

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));

    if(novo == NULL){
        printf("\nERRO DE ALOCAÇÃO");
        free(novo);
        return NULL;
    }

    novo->aluno = (Info*) malloc(sizeof(Info));

    if(novo->aluno == NULL){
        printf("ERRO DE ALOCAÇÃO");
        free(novo->aluno);
        return NULL;
    }

    novo->aluno->numb = numb;
    novo->aluno->clasf = clasf;
    novo->prox = NULL;

    return novo;
}

Elemento* insertOrdenado(Elemento* minhaLista){

    Elemento* novo = novoDado();

    Elemento* aux1 = NULL;
    Elemento* aux2 = minhaLista;

    while(aux2 != NULL && aux2->aluno->numb < novo->aluno->numb)
    {
        aux1 = aux2;
        aux2 = aux2->prox;
    }

    if(aux1 == NULL)
    {
        novo->prox = minhaLista;
        minhaLista = novo;
    }else{
        novo->prox = aux1->prox;
        aux1->prox = novo;
    }

    return minhaLista;
}

Elemento* removeElemento(Elemento* minhaLista, int numb){

    if(minhaLista == NULL)
    {
        printf("\nA lista está vazia");
        return NULL;
    }

    Elemento* aux = NULL;

    for(Elemento* aux2 = minhaLista; aux2 != NULL; aux2 = aux2->prox)
    {
        if(aux2->aluno->numb == numb){

            if(aux == NULL)
            {
                minhaLista = aux2->prox;
                return minhaLista;
            }

            aux->prox = aux2->prox;
            return minhaLista;
        }

        aux = aux2;
    }

    printf("\nNâo foi encontrado");
    return minhaLista;
}

void imprimeLista(Elemento* minhaLista)
{
    Elemento* aux = minhaLista;

    int i = 0;

    for(aux; aux != NULL; aux = aux->prox){

        i++;
        printf("\nAluno: %d\nNúmero: %d\nClassificação: %d\n------\n",i,aux->aluno->numb,aux->aluno->clasf);

    }
}

int main(){

    Elemento* L = iniciarLista();

    L = insertOrdenado(L);
    imprimeLista(L);
    L = insertOrdenado(L);
    imprimeLista(L);
    L = insertOrdenado(L);
    imprimeLista(L);
    printf("-------------");
    removeElemento(L,2);
    imprimeLista(L);
    printf("-------------");
    removeElemento(L,10);
    imprimeLista(L);
    printf("-------------");


}