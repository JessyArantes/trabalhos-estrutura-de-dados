#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct para um cômodo (nó da árvore binária)
typedef struct Sala {
    char nome[50];          // Nome do cômodo
    char pista[100];        // Pista associada ao cômodo
    struct Sala *esquerda;  // Ponteiro para filho esquerdo
    struct Sala *direita;   // Ponteiro para filho direito
} Sala;

// Definição da struct para uma pista (nó da BST)
typedef struct Pista {
    char descricao[100];    // Descrição da pista
    struct Pista *esquerda; // Ponteiro para filho esquerdo
    struct Pista *direita;  // Ponteiro para filho direito
} Pista;

// Definição da struct para entrada da tabela hash (lista encadeada para colisões)
typedef struct EntradaHash {
    char pista[100];        // Chave: pista
    char suspeito[50];      // Valor: suspeito
    struct EntradaHash *proximo;  // Próximo na lista
} EntradaHash;

// Tabela hash com tamanho fixo (10 buckets)
#define TAMANHO_HASH 10
EntradaHash *tabelaHash[TAMANHO_HASH] = {NULL};

// Função hash simples baseada na soma dos caracteres da pista
unsigned int hash(char *pista) {
    unsigned int valor = 0;
    for (int i = 0; pista[i] != '\0'; i++) {
        valor += pista[i];
    }
    return valor % TAMANHO_HASH;
}

// Função para criar um cômodo dinamicamente
Sala *criarSala(char *nome, char *pista) {
    Sala *novaSala = (Sala *)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    strcpy(novaSala->pista, pista);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função para inserir uma pista na BST
Pista *inserirPista(Pista *raiz, char *pista) {
    if (raiz == NULL) {
        Pista *novaPista = (Pista *)malloc(sizeof(Pista));
        if (novaPista == NULL) {
            printf("Erro de alocação de memória.\n");
            exit(1);
        }
        strcpy(novaPista->descricao, pista);
        novaPista->esquerda = NULL;
        novaPista->direita = NULL;
        return novaPista;
    }
    if (strcmp(pista, raiz->descricao) < 0) {
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    } else if (strcmp(pista, raiz->descricao) > 0) {
        raiz->direita = inserirPista(raiz->direita, pista);
    }
    return raiz;
}

// Função para inserir na tabela hash
void inserirNaHash(char *pista, char *suspeito) {
    unsigned int indice = hash(pista);
    EntradaHash *novaEntrada = (EntradaHash *)malloc(sizeof(EntradaHash));
    if (novaEntrada == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    strcpy(novaEntrada->pista, pista);
    strcpy(novaEntrada->suspeito, suspeito);
    novaEntrada->proximo = tabelaHash[indice];
    tabelaHash[indice] = novaEntrada;
}

// Função para encontrar suspeito de uma pista na tabela hash
char *encontrarSuspeito(char *pista) {
    unsigned int indice = hash(pista);
    EntradaHash *atual = tabelaHash[indice];
    while (atual != NULL) {
        if (strcmp(atual->pista, pista) == 0) {
            return atual->suspeito;
        }
        atual = atual->proximo;
    }
    return NULL;  // Não encontrado
}

// Função para explorar as salas de forma interativa
void explorarSalas(Sala *raiz, Pista **raizPistas) {
    Sala *atual = raiz;
    char escolha;
    while (atual != NULL) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        printf("Pista encontrada: %s\n", atual->pista);
        // Insere a pista na BST
        *raizPistas = inserirPista(*raizPistas, atual->pista);
        printf("Pista coletada!\n");
        printf("Escolha: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &escolha);
        if (escolha == 'e') {
            atual = atual->esquerda;
        } else if (escolha == 'd') {
            atual = atual->direita;
        } else if (escolha == 's') {
            break;
        } else {
            printf("Escolha inválida. Tente novamente.\n");
        }
    }
}

// Função para listar pistas em ordem (in-order traversal da BST)
void listarPistas(Pista *raiz) {
    if (raiz != NULL) {
        listarPistas(raiz->esquerda);
        printf("- %s\n", raiz->descricao);
        listarPistas(raiz->direita);
    }
}

// Função para contar pistas de um suspeito específico
int contarPistasSuspeito(Pista *raiz, char *suspeito) {
    if (raiz == NULL) return 0;
    char *suspeitoPista = encontrarSuspeito(raiz->descricao);
    int count = (suspeitoPista != NULL && strcmp(suspeitoPista, suspeito) == 0) ? 1 : 0;
    return count + contarPistasSuspeito(raiz->esquerda, suspeito) + contarPistasSuspeito(raiz->direita, suspeito);
}

// Função para verificar o suspeito final
void verificarSuspeitoFinal(Pista *raizPistas) {
    printf("\n=== Fase de Julgamento ===\n");
    printf("Pistas coletadas:\n");
    listarPistas(raizPistas);
    printf("\nDigite o nome do suspeito que você acusa: ");
    char suspeitoAcusado[50];
    scanf("%s", suspeitoAcusado);
    int numPistas = contarPistasSuspeito(raizPistas, suspeitoAcusado);
    if (numPistas >= 2) {
        printf("Parabéns! Você acusou corretamente. Há %d pistas apontando para %s.\n", numPistas, suspeitoAcusado);
    } else {
        printf("Acusação incorreta. Apenas %d pistas apontam para %s. Tente novamente em outra partida.\n", numPistas, suspeitoAcusado);
    }
}

// Função para liberar memória da árvore de salas (recursiva)
void liberarArvoreSalas(Sala *raiz) {
    if (raiz != NULL) {
        liberarArvoreSalas(raiz->esquerda);
        liberarArvoreSalas(raiz->direita);
        free(raiz);
    }
}

// Função para liberar memória da BST de pistas (recursiva)
void liberarBSTPistas(Pista *raiz) {
    if (raiz != NULL) {
        liberarBSTPistas(raiz->esquerda);
        liberarBSTPistas(raiz->direita);
        free(raiz);
    }
}

// Função para liberar memória da tabela hash
void liberarHash() {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        EntradaHash *atual = tabelaHash[i];
        while (atual != NULL) {
            EntradaHash *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

// Função principal
int main() {
    // Construção manual da árvore binária da mansão
    Sala *raiz = criarSala("Entrada", "Uma chave enferrujada no chão.");
    raiz->esquerda = criarSala("Sala de Jantar", "Um prato quebrado com restos de comida.");
    raiz->direita = criarSala("Biblioteca", "Um livro aberto com anotações estranhas.");
    raiz->esquerda->esquerda = criarSala("Cozinha", "Uma faca suja de sangue.");
    raiz->esquerda->direita = criarSala("Quarto Principal", "Um diário com entradas suspeitas.");
    raiz->direita->esquerda = criarSala("Escritório", "Documentos falsificados.");
    raiz->direita->direita = criarSala("Porão", "Ferramentas manchadas.");

    // Inicialização da BST de pistas
    Pista *raizPistas = NULL;

    // Preenchimento da tabela hash com associações pista-suspeito
    inserirNaHash("Uma chave enferrujada no chão.", "Jardineiro");
    inserirNaHash("Um prato quebrado com restos de comida.", "Cozinheiro");
    inserirNaHash("Um livro aberto com anotações estranhas.", "Bibliotecário");
    inserirNaHash("Uma faca suja de sangue.", "Cozinheiro");
    inserirNaHash("Um diário com entradas suspeitas.", "Esposa");
    inserirNaHash("Documentos falsificados.", "Advogado");
    inserirNaHash("Ferramentas manchadas.", "Jardineiro");

    // Exploração interativa
    printf("Bem-vindo ao Detective Quest!\n");
    printf("Explore a mansão coletando pistas. Use 'e' para esquerda, 'd' para direita, 's' para sair.\n");
    explorarSalas(raiz, &raizPistas);

    // Verificação final
    verificarSuspeitoFinal(raizPistas);

    // Liberação de memória
    liberarArvoreSalas(raiz);
    liberarBSTPistas(raizPistas);
    liberarHash();

    return 0;
}
