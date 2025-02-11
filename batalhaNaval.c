#include <stdio.h>

#define TAB_LINHA 10
#define TAB_COLUNA 10
#define POD_LINHA 3
#define POD_COLUNA 5
#define LINHA_ADD_POD 6  // Linha que o poder será inserido
#define COLUNA_ADD_POD 4 // Coluna que o poder será inserido

int receberItemMenu(int MIN, int MAX)
{
    int item = 0;
    do
    {
        printf("Digite a opção desejada: ");
        scanf(" %d", &item);

        if (item < MIN || item > MAX)
        {
            printf("\nRespeite os limites! (%d - %d)\n", MIN, MAX);
        }

    } while (item < MIN || item > MAX);
    return item;
}

void mostrarTabuleiro(int tabuleiro[TAB_LINHA][TAB_COLUNA])
{
    printf("\n================= TABULEIRO ================\n\n");
    printf(" O | A | B | C | D | E | F | G | H | I | J |\n");
    for (int i = 0; i < TAB_LINHA; i++)
    {
        printf(" %d ", i);
        for (int j = 0; j < TAB_COLUNA; j++)
        {
            if (j == 0)
            {
                printf("| %d |", tabuleiro[i][j]);
            }
            else
            {
                printf(" %d |", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

void addPodCone(int tabuleiro[TAB_LINHA][TAB_COLUNA], int poder[POD_LINHA][POD_COLUNA])
{
    for (int i = 0; i < POD_LINHA; i++)
    {
        for (int j = 0; j < POD_COLUNA; j++)
        {
            if (poder[i][j] != 0)
            {
                tabuleiro[LINHA_ADD_POD + i][COLUNA_ADD_POD + j] = poder[i][j];
            }
        }
    }
}

void addPodLosango(int tabuleiro[TAB_LINHA][TAB_COLUNA], int poder[POD_LINHA][POD_COLUNA])
{
    for (int i = 0; i < POD_LINHA; i++)
    {
        for (int j = 0; j < POD_COLUNA; j++)
        {
            if (poder[i][j] != 0)
            {
                tabuleiro[LINHA_ADD_POD + i][COLUNA_ADD_POD + j] = poder[i][j];
            }
        }
    }
}

void addPodCruz(int tabuleiro[TAB_LINHA][TAB_COLUNA], int poder[POD_LINHA][POD_COLUNA])
{
    for (int i = 0; i < POD_LINHA; i++)
    {
        for (int j = 0; j < POD_COLUNA; j++)
        {
            if (poder[i][j] != 0)
            {
                tabuleiro[LINHA_ADD_POD + i][COLUNA_ADD_POD + j] = poder[i][j];
            }
        }
    }
}

int main()
{
    int tabuleiro[TAB_LINHA][TAB_COLUNA] = {};
    int poder_Cone[POD_LINHA][POD_COLUNA] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1}};    // Matriz 3x5 com uma pirâmide preenchida de "1"s e o restante "0"s
    int poder_Losango[POD_LINHA][POD_COLUNA] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}}; // Matriz 3x5 com um losango preenchido de "1"s e o restante "0"s
    int poder_Cruz[POD_LINHA][POD_COLUNA] = {{0, 0, 1, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 1, 0, 0}};    // Matriz 3x5 com uma cruz de "1"s e o restante "0"s
    int menu, poderEscolhido;

    printf("\n====== MENU: ======\n");
    printf("1 - Ver o tabuleiro\n");
    printf("2 - Inserir navios\n");
    printf("3 - Ativar poder no tabuleiro\n\n");

    menu = receberItemMenu(1, 3);

    switch (menu)
    {
    case 1:
        printf("\nVEJA O TABULEIRO:\n\n");
        mostrarTabuleiro(tabuleiro);
        break;

    case 2:
        // Inserindo navio na horizontal:

        tabuleiro[6][3] = 3;
        tabuleiro[6][4] = 3;
        tabuleiro[6][5] = 3;

        // Inserindo navio na vertical:

        tabuleiro[1][3] = 3;
        tabuleiro[2][3] = 3;
        tabuleiro[3][3] = 3;

        // Inserindo navio na diagonal:

        tabuleiro[5][9] = 3;
        tabuleiro[4][8] = 3;
        tabuleiro[3][7] = 3;

        // Inserindo navio na diagonal:

        tabuleiro[1][8] = 3;
        tabuleiro[2][7] = 3;
        tabuleiro[3][6] = 3;
        tabuleiro[4][5] = 3;

        mostrarTabuleiro(tabuleiro);
        break;
    case 3:
        printf("\n==== MENU PODERES: ====\n");
        printf("1 - Poder cone\n");
        printf("2 - Poder losango\n");
        printf("3 - Poder cruz\n\n");

        poderEscolhido = receberItemMenu(1, 3);

        switch (poderEscolhido)
        {
        case 1:
            addPodCone(tabuleiro, poder_Cone);
            break;
        case 2:
            addPodLosango(tabuleiro, poder_Losango);
            break;
        case 3:
            addPodCruz(tabuleiro, poder_Cruz);
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }

    mostrarTabuleiro(tabuleiro);

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
