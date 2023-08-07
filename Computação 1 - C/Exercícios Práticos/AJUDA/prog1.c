#include <stdio.h>
#include <string.h>

typedef struct _PESSOA {
    char nome[40]; int ano;
} PESSOA;

int main() {
    FILE *pa;
    char nome[40], linha[80];
    PESSOA turma [4], back[4];
    int i;
    for (i=0; i<4; i++) {
        puts ("Nome ?");
        fgets(turma[i].nome, 40, stdin);
        turma[i].nome[strlen(turma[i].nome)-1]='\0';
        puts("Ano ?"); fgets(linha, 80, stdin);
        sscanf(linha, "%d", &turma[i].ano);
    }

    puts("\nGravando\n");
    puts("Qual o nome do arquivo?"); fgets(nome, 40, stdin);

    nome[strlen(nome)-1]='\0';
    if ((pa = fopen(nome,"w+")) == NULL) {
        puts("Arquivo nao pode ser aberto");
        return 1;
    }
    for (i=0; i<4; i++) {
        if (fwrite(&turma[i], sizeof (PESSOA), 1, pa) != 1) {
            puts("Erro na escrita.");
        }
    }
    rewind(pa);
    for (i=0; i<4; i++) {
        if (fread( &back[i], sizeof(PESSOA), 1, pa ) != 1){
            if (feof(pa)) break;
            puts("Erro na leitura");
        }
    }
    for (i=0; i<4; i++) {
        printf("Nome = %s\n", back[i].nome);
        printf("Ano = %d\n\n", back[i].ano);
    }
    return 0;
}