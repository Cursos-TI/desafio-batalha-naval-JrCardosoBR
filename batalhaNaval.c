#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void exibirNavio(char *nome, int coordenadas[][2], int tamanho) {
    printf("%s:\n", nome);
    for (int i = 0; i < tamanho; i++) {
        printf("(%d, %d)\n", coordenadas[i][0], coordenadas[i][1]);
    }
    printf("\n");
}

int main() {
    // Definição dos navios
    int navioVertical[TAMANHO_NAVIO][2] = {{2, 3}, {3, 3}, {4, 3}}; // Exemplo de posição vertical
    int navioHorizontal[TAMANHO_NAVIO][2] = {{6, 5}, {6, 6}, {6, 7}}; // Exemplo de posição horizontal
    
    // Exibir coordenadas dos navios
    exibirNavio("Navio Vertical", navioVertical, TAMANHO_NAVIO);
    exibirNavio("Navio Horizontal", navioHorizontal, TAMANHO_NAVIO);
    
    return 0;
}
