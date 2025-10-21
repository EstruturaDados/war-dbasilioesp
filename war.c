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

int opcao;
int maxTerritorios;
int atacante, defensor;
Territorio* territorios;

void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void alocarMapa() {
    printf("Digite quantos territorios no mapa: ");
    scanf("%d", &maxTerritorios);
    limparBufferEntrada();

    free(territorios);
    territorios = (Territorio*)malloc(maxTerritorios * sizeof(Territorio));
}

void inicializarTerritorios() {
    for (int i = 0; i < maxTerritorios; i++) {
        printf("\n----- Cadastro Territorio %d ------\n\n", i + 1);

        printf("Digite o nome: ");
        fgets(territorios[i].nome, MAX_NOME, stdin);

        printf("Digite a cor: ");
        fgets(territorios[i].cor, MAX_COLOR, stdin);

        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';
        
        printf("Digite quantidade de tropas: ");
        scanf("%d", &territorios[i].num_tropas);
        limparBufferEntrada();
    }

    printf("\n\nTERRITORIOS CADASTRADOS.\n\n");
}

void exibirMapa() {
    printf("=============================\n");
    printf("MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=============================\n\n");

    for (int i = 0; i < maxTerritorios; i++) {
        printf("%d. %s (%s, Tropas: %d)\n", i + 1, territorios[i].nome, territorios[i].cor, territorios[i].num_tropas);
    }
}

void faseDeAtaque() {
    printf("--- FASE DE ATAQUE ---\n");
    printf("Escolha o territorio atacante (1 a %d): ", maxTerritorios);
    scanf("%d", &atacante);
    limparBufferEntrada();

    printf("Escolha o territorio defensor (1 a %d): ", maxTerritorios);
    scanf("%d", &defensor);
    limparBufferEntrada();
}


// --- Função Principal (main) ---
int main() {
    printf("============================================================================\n");
    printf("PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO\n");
    printf("============================================================================\n");

    alocarMapa();
    inicializarTerritorios();
    exibirMapa();
    
    do {
        faseDeAtaque();
        
    } while (opcao != 0);


    free(territorios);
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

