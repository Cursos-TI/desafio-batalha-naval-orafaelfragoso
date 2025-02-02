#include <stdio.h>
#include <stdlib.h> // Inclui a biblioteca para usar abs

#define BOARD_SIZE 10 // Tamanho do tabuleiro (10x10)

// Estrutura e funções auxiliares
typedef struct {
    int x, y;
} Position;

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]);
int isValidPosition(int x, int y); // Declaração da função isValidPosition

// Funções principais para os níveis
void levelNovice();
void levelAdventurer();
void levelMaster();

// Funções específicas para posicionar navios e aplicar habilidades
void placeVerticalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int length);
void placeHorizontalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int length);
void placeDiagonalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int length, int direction);
void applyConeAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y);
void applyCrossAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y);
void applyOctahedronAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y);

int main() {
    int choice;

    printf("=== Batalha Naval ===\n");
    printf("Escolha o nível do desafio:\n");
    printf("1 - Nível Novato\n");
    printf("2 - Nível Aventureiro\n");
    printf("3 - Nível Mestre\n");
    printf("0 - Sair\n");

    while (1) {
        printf("\nDigite sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                levelNovice();
                break;
            case 2:
                levelAdventurer();
                break;
            case 3:
                levelMaster();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

/**
 * @brief Verifica se uma posição é válida no tabuleiro.
 *
 * @param x Coordenada X da posição.
 * @param y Coordenada Y da posição.
 * @return Retorna `1` se a posição for válida ou `0` caso contrário.
 */
int isValidPosition(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

/**
 * @brief Exibe o tabuleiro no console.
 *
 * @param board Matriz representando o tabuleiro.
 */
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Implementa o nível Novato.
 *
 * Posiciona dois navios no tabuleiro: um vertical e um horizontal.
 */
void levelNovice() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    // Posicionar navios
    placeVerticalShip(board, 2, 2, 3); // Navio vertical de tamanho 3
    placeHorizontalShip(board, 5, 5, 4); // Navio horizontal de tamanho 4

    // Exibir as coordenadas dos navios
    printf("\nTabuleiro após posicionar os navios (Nível Novato):\n");
    printBoard(board);
}

/**
 * @brief Implementa o nível Aventureiro.
 *
 * Posiciona quatro navios no tabuleiro: dois na diagonal e dois em direções básicas.
 */
void levelAdventurer() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    // Posicionar navios
    placeVerticalShip(board, 1, 1, 4); // Navio vertical de tamanho 4
    placeHorizontalShip(board, 7, 7, 3); // Navio horizontal de tamanho 3
    placeDiagonalShip(board, 3, 3, 3, 1); // Navio diagonal crescente (\)
    placeDiagonalShip(board, 6, 6, 3, -1); // Navio diagonal decrescente (/)

    // Exibir o tabuleiro completo
    printf("\nTabuleiro após posicionar os navios (Nível Aventureiro):\n");
    printBoard(board);
}

/**
 * @brief Implementa o nível Mestre.
 *
 * Aplica habilidades especiais no tabuleiro: cone, cruz e octaedro.
 */
void levelMaster() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    // Aplicar habilidades especiais
    applyConeAbility(board, 4, 4);
    applyCrossAbility(board, 7, 7);
    applyOctahedronAbility(board, 2, 2);

    // Exibir o tabuleiro com as áreas afetadas
    printf("\nTabuleiro após aplicar habilidades especiais (Nível Mestre):\n");
    printBoard(board);
}

/**
 * @brief Posiciona um navio verticalmente no tabuleiro.
 *
 * @param board Matriz representando o tabuleiro.
 * @param x Coordenada X inicial.
 * @param y Coordenada Y inicial.
 * @param length Tamanho do navio.
 */
void placeVerticalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int length) {
    for (int i = 0; i < length; i++) {
        if (x + i < BOARD_SIZE) {
            board[x + i][y] = 3;
        }
    }
}

/**
 * @brief Posiciona um navio horizontalmente no tabuleiro.
 *
 * @param board Matriz representando o tabuleiro.
 * @param x Coordenada X inicial.
 * @param y Coordenada Y inicial.
 * @param length Tamanho do navio.
 */
void placeHorizontalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int length) {
    for (int i = 0; i < length; i++) {
        if (y + i < BOARD_SIZE) {
            board[x][y + i] = 3;
        }
    }
}

/**
 * @brief Posiciona um navio diagonalmente no tabuleiro.
 *
 * @param board Matriz representando o tabuleiro.
 * @param x Coordenada X inicial.
 * @param y Coordenada Y inicial.
 * @param length Tamanho do navio.
 * @param direction Direção da diagonal: +1 para crescente (\), -1 para decrescente (/).
 */
void placeDiagonalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int length, int direction) {
    for (int i = 0; i < length; i++) {
        if (x + i < BOARD_SIZE && y + direction * i >= 0 && y + direction * i < BOARD_SIZE) {
            board[x + i][y + direction * i] = 3;
        }
    }
}

/**
 * @brief Aplica a habilidade especial em cone no tabuleiro.
 *
 * O cone é representado por uma matriz triangular com vértice em (x,y).
 */
void applyConeAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) >= abs(j) && isValidPosition(x + i, y + j)) {
                board[x + i][y + j] = 1;
            }
        }
    }
}

/**
 * @brief Aplica a habilidade especial em cruz no tabuleiro.
 *
 * A cruz é formada por linhas verticais e horizontais centradas em (x,y).
 */
void applyCrossAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        if (isValidPosition(x + i, y)) {
            board[x + i][y] = 1;
        }
        if (isValidPosition(x, y + i)) {
            board[x][y + i] = 1;
        }
    }
}

/**
 * @brief Aplica a habilidade especial em octaedro no tabuleiro.
 *
 * O octaedro é formado por uma matriz losangular centrada em (x,y).
 */
void applyOctahedronAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2 && isValidPosition(x + i, y + j)) {
                board[x + i][y + j] = 1;
            }
        }
    }
}
