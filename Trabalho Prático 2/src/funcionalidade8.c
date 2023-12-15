/*  
*   Lucas Lima Romero - 13676325
*   Marco Antonio Gaspar Garcia - 11833581
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionalidades.h"
#include "registros.h"
#include "funcoesCriadas.h"
#include "funcoesFornecidas.h"
#include "grafo.h"

// Funcionalidade 8: gera um Grafo a partir de um arquivo binário

void geraGrafo(char *nomeArquivoBIN){ 

    // Abrindo o arquivo binário
    FILE *ArquivoBIN = fopen(nomeArquivoBIN, "rb");
    if (ArquivoBIN == NULL){
        printf("Falha no processamento do arquivo.\n");
        return;
    }

    // Lê o cabeçalho do arquivo binário
    Cabecalho *cabecalho = criaCabecalho();
    leCabecalhoBin(ArquivoBIN, cabecalho);

    // Verifica se o arquivo está consistente
    if (cabecalho->status == '0'){
        printf("Falha no processamento do arquivo.\n");
        free(cabecalho);
        fclose(ArquivoBIN);
        return;
    }

    // Criando as estruturas que iremos utilizar
    Grafo *grafo = criaGrafo();
    Registro *r;

    // Variáveis para percorrer o arquivo
    const unsigned int tamTotal = 13 + TAM_REGISTRO * (cabecalho->proxRRN - 1);
    unsigned int byteOffset = 13;

    // Percorre o arquivo binário lendo os registros
    while (byteOffset <= tamTotal){
        
        // Lendo o registro
        r = criaRegistro();
        r = leRegistro(byteOffset, r, ArquivoBIN);

        // Verifica se o registro foi removido
        if (r->removido == '1'){
            byteOffset += TAM_REGISTRO;
            free(r);
            continue;
        }

        // Insere o registro no grafo
        insereGrafo(grafo, r);

        byteOffset += TAM_REGISTRO;
    }

    

    //destroiGrafo(grafo);


    fclose(ArquivoBIN);
    free(cabecalho);
}
