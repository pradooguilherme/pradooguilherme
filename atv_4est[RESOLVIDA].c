/*

1. Considere as sequências de caracteres: 'C', 'aCa', 'abCba', 'baCab', 'aabCbaa',
'abaaCaaba'... . 

Uma sequência típica nesse conjunto pode ser descrita como wCwR,
na qual w contém a sequência de a's e b's, ou w é vazia, e wR é o reverso de w. Por
exemplo, se w = 'abb', então wR = 'bba'. 

Dada uma sequência de caracteres X de entrada qualquer (lida caractere por caractere a partir do teclado), faça um
programa em C que use uma ÚNICA estrutura do tipo pilha (não é permitido usar nenhuma outra estrutura auxiliar) para responder (na forma de mensagem)
se X pertence ou não ao conjunto de sequências, podendo ser descrito
por wCwR. 

Considerar que a sequência de entrada nunca é vazia, que 'C' aparece
uma única vez e que somente a's e b's aparecem em w.

Obs.: para resolver será necessário criar programas que inicializem
adequadamente as estruturas utilizadas. Resolva utilizando alocação estática e
dinâmica (dois programas).

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define max 10

typedef struct{

    char pilha[max];
    int topo;

} PILHA;

void bootPilha(PILHA* p){

    p->topo = -1;

}

char pop(PILHA* p){

    if(p->topo == - 1){

        printf("\nA pilha está vazia, impossível fazer a retirada");
        return '\0';

    }


    char elemento = p->pilha[p->topo];
    p->topo--;

    return elemento;
}

void push(PILHA* p, char letra){

    p->topo++;
    p->pilha[p->topo] = letra;

}

void verificaSequencia(PILHA* p){

    bool flag = true;
    char a,b;

    printf("\nPrimeira parte da sequência");

    while(flag != false){

        printf("\nInsira um caractere: ");
        scanf(" %c",&a);

        if(a == 'C'){
            flag = false;
        }else{
            push(p,a);
        }
    }

    flag = true;

    printf("\nSegunda parte da sequência");

    while(flag != false){

        printf("\nInsira um caractere: ");
        scanf(" %c",&b);

        a = pop(p);

        if(a != b){

            flag = false;

            printf("\nA sequência eh diferente");
            return;
        }

        printf("\nDeseja continuar ('s' para sim): ");
        scanf(" %c",&b);

        if(b != 's'){

            if(flag == true && p->topo == -1){

                printf("\nA sequência eh igual");
                return;

            }

            printf("A sequência eh diferente");
            return;

        }
    }
}

int main(){

    PILHA p;

    bootPilha(&p);
    verificaSequencia(&p);

}