/*  
*   Lucas Lima Romero - 13676325
*   Marco Antonio Gaspar Garcia - 11833581
*/

#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include <stdio.h>

// Funcionalidade 1
void criaTabela(char *nomeArquivoCSV, char *nomeArquivoBIN);

// Funcionalidade 2
void recuperaDados(const char* nomeArquivoBIN);

// Funcionalidade 3
void buscaPorCampo(char *nomeArquivoBIN, int N);

// Funcionalidade 4
void buscaPorRRN(char *nomeArquivoBIN, int RRN);
void buscaArquivoDados(FILE *arquivoBIN, int rrn);

// Funcionalidade 5
void geraArquivoIndice(char *nomeArquivoBIN, char *nomeArquivoIND);

// Funcionalidade 6
void buscaComIndice(char *nomeArquivoBIN, char *nomeArquivoIND, int n);

// Funcionalidade 7
void insercaoNosArquivos(char *nomeArquivoBIN, char *nomeArquivoIND, int n);

#endif
