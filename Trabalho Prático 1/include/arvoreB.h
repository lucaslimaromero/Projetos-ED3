/*  
*   Lucas Lima Romero - 13676325
*   Marco Antonio Gaspar Garcia - 11833581
*/

#ifndef ARVORE_B_H
#define ARVORE_B_H

#define M 3
#define STRING_TAM 55

// Estrutura que define um Nó (ou página) de Árvore B
typedef struct _Node{ 
    
    int nroChavesNo, alturaNo, RRNdoNo;

    int P[M + 1];       
    int PR[M];
    char C[M][STRING_TAM];  // Tornar dinâmico posteriormente

    // De acordo com a especificação do projeto:
    // P1 == P[0]; P2 == P[1]; P3 == P[2]; P4 == P[3]
    // PR1 == PR[0] ...
    // C1 == C[0] ...
    // e assim por diante...
    // Os últimos elementos serão apenas para guardar temporariamente para fazer os splits
    
} Node;

// Estrutura do Cabeçalho do Arquivo de Índice da Árvore-B
typedef struct{
    char status;
    int noRaiz;
    int RRNproxNo;
} CabecalhoIndice;

// Função que cria um Nó de árvore B
Node *criaNode(void);




#endif
