#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coordenadas[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[coordenadas[i][0]][coordenadas[i][1]] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Definição dos navios
    int navioVertical[TAMANHO_NAVIO][2] = {{2, 3}, {3, 3}, {4, 3}};
    int navioHorizontal[TAMANHO_NAVIO][2] = {{6, 5}, {6, 6}, {6, 7}};
    int navioDiagonal1[TAMANHO_NAVIO][2] = {{1, 1}, {2, 2}, {3, 3}};
    int navioDiagonal2[TAMANHO_NAVIO][2] = {{7, 2}, {8, 3}, {9, 4}};
    
    // Posicionar navios no tabuleiro
    posicionarNavio(tabuleiro, navioVertical, TAMANHO_NAVIO);
    posicionarNavio(tabuleiro, navioHorizontal, TAMANHO_NAVIO);
    posicionarNavio(tabuleiro, navioDiagonal1, TAMANHO_NAVIO);
    posicionarNavio(tabuleiro, navioDiagonal2, TAMANHO_NAVIO);
    
    // Exibir tabuleiro completo
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
