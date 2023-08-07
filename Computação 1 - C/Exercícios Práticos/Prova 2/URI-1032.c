/*  Nome: Pedro Henrique Figueiredo Von Zuben
     DRE: 119055699 
PROGRAMA: URI - 1032 (Lista de pessoas) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _PESSOA {
    char nome[80];
    char sexo;
    int idade;
    struct _PESSOA *p_prox;
} PESSOA;

int insere_pessoa(PESSOA *p_head, struct _PESSOA *p_novo) {
    PESSOA *p;

    if ((p = (PESSOA *)malloc(sizeof(PESSOA))) == NULL)   {
        printf("Falta Memoria \n");
        return 1;
    }

    strcpy (p->nome, p_novo->nome);

    p->sexo = p_novo->sexo;
    p->idade = p_novo->idade;
    p->p_prox = NULL;

    p->p_prox = p_head->p_prox;
    p_head->p_prox = p;

    return 0;
}

int main(void) {
    PESSOA *p_head, *p, pessoa1;

    p_head = NULL;

    if ((p = (PESSOA *)malloc(sizeof(PESSOA))) == NULL)   {
        printf("Falta Memoria \n");
        return 1;
    }
    /* insere os 1os dados na  lista */

    strcpy (p->nome, "Pessoa1");

    p->sexo = 'F';
    p->idade = 42;
    p->p_prox = NULL;
    p_head = p;  

    /* cria novos dados */

    strcpy (pessoa1.nome, "Pessoa2");

    pessoa1.sexo = 'M';
    pessoa1.idade = 18;
    pessoa1.p_prox = NULL;

    insere_pessoa (p_head, &pessoa1);

    p = p_head;

    while (p != NULL)  {

        printf("%s %c %d\n", p->nome, p->sexo, p->idade);
        p = p->p_prox;
    }

    return 0;
}