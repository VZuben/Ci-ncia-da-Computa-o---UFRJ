#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "def.h"

/* #ifndef utilizado para evitar duplicações dos protótipos */
#ifndef FUNCOES_H
#define FUNCOES_H

/* Protótipos de todas as funções exportadas no módulo funcoes.c */

void print_tabuleiro(jogador j, jogador j_outro);
void transicao(jogador j_saida);
void preenche_tabuleiro(unsigned char **tabuleiro);
void coloca_navios(jogador j, jogador j_outro);
void coloca_navio(jogador j, int navio, char lin1, int col1, char lin2, int col2);
int  checa_validade_navio(jogador j, int navio, char lin1, int col1, char lin2, int col2);
int  verifica_area_tiro (jogador j, jogador j_outro, int lin, int col);
int  avalia_ataque(jogador j, jogador j_outro, int lin, int col);
void ataque(jogador j, jogador j_outro);
int  checa_derrota(jogador j_atingido);


#endif