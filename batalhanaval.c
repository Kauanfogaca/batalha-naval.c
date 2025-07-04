#include <stdio.h>
// Define o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

//Função para inicializar o tabuleiro com água (o)
void inicializarTabuleiro(int
 tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++){
            tabuleiro[i][j] = 0;
        }
    }
 }
 //Função para imprimir o tabuleiro
 void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    printf("   ");
    for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d", j); //Índices de coluna
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            printf("%2d |", i); //Índices de linha
            
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%2d ", tabuleiro[i][j]);
            }
            printf("\n");
    }
 }

 //Função para posicionar um navio horizontalmente
 int posicionarNavioHorizontal(int
    tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna){
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites;
        }

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if(tabuleiro[linha][coluna + i] != 0) {
                return 0; // Sobreposição
            }
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
            }
            return 1; //Sucesso
        }
    // Função para posicionar um navio verticalmente
    int posicionarNavioVertical(int
        tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
            // Verifica se o navio cabe no tabuleiro verticalmente
            if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO){
        return 0; //Fora dos limites
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0){
            return 0; // Sobreposição
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[linha + i] [coluna] = 3;
    }
    return 1; //Sucesso
        }

int main () {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (definidas diretamente no código)
        int linhaH = 2, colunaH = 4; // Horizontal
        int linhaV = 5, colunaV = 6; // Vertical

        //Posiciona o navio horizontal 
        if (!
        posicionarNavioHorizontal(tabuleiro, linhaH, colunaH)) {
            printf("Erro ao posicionar o navio horizontal!\n");
            return 1;
        }
        //Posiciona o navio vertical 
        if (!
        posicionarNavioVertical(tabuleiro, linhaV, colunaV)) {
            printf("Erro ao posicionar o navio vertical!\n");
            return 1;
        }

        // Exibe o tabuleiro no console
        printf("***BATALHA NAVAL***\n");
        exibirTabuleiro(tabuleiro);

        return 0;
}