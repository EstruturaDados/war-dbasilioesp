#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//

#define MAX_NOME 50
#define MAX_COLOR 10
#define MAX_TERRITORIOS 5

typedef struct  {
    char nome[MAX_NOME];
    char cor[MAX_COLOR];
    int num_tropas;
} Territorio;


void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal (main) ---
int main() {

    Territorio territorios[MAX_TERRITORIOS];
    int iT = 0; // indice territorios
    int opcao;

    do {
        printf("============================================================================\n");
        printf("PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO\n");
        printf("============================================================================\n");
        printf("1 - Cadastrar territorio\n");
        printf("2 - Mostrar mapa\n");
        printf("0 - Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch(opcao) {
            case 1:
                if (iT < MAX_TERRITORIOS) {
                    printf("---- Cadastro do Territorio ----\n\n");

                    printf("Digite o nome: ");
                    fgets(territorios[iT].nome, MAX_NOME, stdin);

                    printf("Digite a cor: ");
                    fgets(territorios[iT].cor, MAX_COLOR, stdin);

                    territorios[iT].nome[strcspn(territorios[iT].nome, "\n")] = "\0";
                    territorios[iT].cor[strcspn(territorios[iT].cor, "\n")] = "\0";
                    //  buffer[strcspn(buffer, "\n")] = '\0';

                    printf("Digite quantidade de tropas: ");
                    scanf("%d", &territorios[iT].num_tropas);
                    limparBufferEntrada();

                    iT++;
                    printf("Territorio cadastrado.\n\n");
                } else {
                    printf("Máximo de territorios cadastrados! Reinicie o sistema.\n\n");
                }

                printf("Digite Enter para continuar...");
                getchar();
                break;
            case 2: 
                printf("\n\n---- Mapa ----\n\n");

                if (iT == 0) {
                    printf("Nenhum territorio cadastrado\n");
                } else {
                    for (int i = 0; i < iT; i++) {
                        printf("---------\n");
                        printf("TERRITORIO: %s\n", territorios[i].nome);
                        printf("Cor: %s\n", territorios[i].cor);
                        printf("Tropas: %d\n", territorios[i].num_tropas);
                    }
                    printf("---------\n\n");
                }

                printf("Digite Enter para continuar...");
                getchar();
            break;
            default: break;
        }

    } while (opcao != 0);

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.

