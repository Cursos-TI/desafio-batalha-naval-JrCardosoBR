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

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, char tipo) {
    if (tipo == 'C') { // Cruz
        for (int i = -1; i <= 1; i++) {
            if (x + i >= 0 && x + i < TAMANHO_TABULEIRO) tabuleiro[x + i][y] = 1;
            if (y + i >= 0 && y + i < TAMANHO_TABULEIRO) tabuleiro[x][y + i] = 1;
        }
    } else if (tipo == 'O') { // Octaedro
        if (x > 0) tabuleiro[x - 1][y] = 1;
        if (x < TAMANHO_TABULEIRO - 1) tabuleiro[x + 1][y] = 1;
        if (y > 0) tabuleiro[x][y - 1] = 1;
        if (y < TAMANHO_TABULEIRO - 1) tabuleiro[x][y + 1] = 1;
    } else if (tipo == 'N') { // Cone
        if (x > 1) tabuleiro[x - 2][y] = 1;
        if (x > 0) {
            if (y > 0) tabuleiro[x - 1][y - 1] = 1;
            tabuleiro[x - 1][y] = 1;
            if (y < TAMANHO_TABULEIRO - 1) tabuleiro[x - 1][y + 1] = 1;
        }
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
    
    // Aplicar habilidades especiais
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cruz no centro
    aplicarHabilidade(tabuleiro, 2, 7, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 8, 2, 'N'); // Cone
    
    // Exibir tabuleiro completo
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
