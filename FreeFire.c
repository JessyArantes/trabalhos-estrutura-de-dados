#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da struct Componente
typedef struct {
    char nome[30];     // Nome do componente
    char tipo[20];     // Tipo do componente
    int prioridade;    // Prioridade (1 a 10)
} Componente;

// Array global para armazenar os componentes (até 20)
Componente componentes[20];
int numComponentes = 0;  // Número atual de componentes cadastrados

// Contador global de comparações (usado pelas funções de ordenação)
int comparacoes = 0;

// Função para exibir os componentes formatados
void mostrarComponentes(Componente comp[], int n) {
    printf("\nComponentes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Nome: %s | Tipo: %s | Prioridade: %d\n", i + 1, comp[i].nome, comp[i].tipo, comp[i].prioridade);
    }
    printf("\n");
}

// Função para cadastrar componentes (até 20)
void cadastrarComponentes() {
    printf("Quantos componentes deseja cadastrar? (máximo 20): ");
    scanf("%d", &numComponentes);
    getchar();  // Limpa o buffer do scanf
    if (numComponentes > 20) numComponentes = 20;
    for (int i = 0; i < numComponentes; i++) {
        printf("Componente %d:\n", i + 1);
        printf("Nome: ");
        fgets(componentes[i].nome, 30, stdin);
        componentes[i].nome[strcspn(componentes[i].nome, "\n")] = 0;  // Remove newline
        printf("Tipo: ");
        fgets(componentes[i].tipo, 20, stdin);
        componentes[i].tipo[strcspn(componentes[i].tipo, "\n")] = 0;  // Remove newline
        printf("Prioridade (1-10): ");
        scanf("%d", &componentes[i].prioridade);
        getchar();  // Limpa buffer
    }
}

// Bubble Sort por nome (string)
void bubbleSortNome(Componente comp[], int n) {
    comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;  // Conta cada comparação
            if (strcmp(comp[j].nome, comp[j + 1].nome) > 0) {
                Componente temp = comp[j];
                comp[j] = comp[j + 1];
                comp[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort por tipo (string)
void insertionSortTipo(Componente comp[], int n) {
    comparacoes = 0;
    for (int i = 1; i < n; i++) {
        Componente chave = comp[i];
        int j = i - 1;
        while (j >= 0 && strcmp(comp[j].tipo, chave.tipo) > 0) {
            comparacoes++;  // Conta cada comparação no while
            comp[j + 1] = comp[j];
            j--;
        }
        comp[j + 1] = chave;
        if (j >= 0) comparacoes++;  // Conta a última comparação se entrou no while
    }
}

// Selection Sort por prioridade (int)
void selectionSortPrioridade(Componente comp[], int n) {
    comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;  // Conta cada comparação
            if (comp[j].prioridade < comp[minIdx].prioridade) {
                minIdx = j;
            }
        }
        Componente temp = comp[minIdx];
        comp[minIdx] = comp[i];
        comp[i] = temp;
    }
}

// Busca Binária por nome (apenas após ordenação por nome)
int buscaBinariaPorNome(Componente comp[], int n, char chave[]) {
    int esquerda = 0, direita = n - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(comp[meio].nome, chave);
        if (cmp == 0) {
            return meio;  // Encontrado
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;  // Não encontrado
}

// Função para medir tempo e comparações de um algoritmo de ordenação
void medirTempo(void (*algoritmo)(Componente[], int), Componente comp[], int n, const char* nomeAlgoritmo) {
    clock_t inicio = clock();
    algoritmo(comp, n);  // Chama a função de ordenação
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Algoritmo: %s\n", nomeAlgoritmo);
    printf("Comparações realizadas: %d\n", comparacoes);
    printf("Tempo de execução: %.6f segundos\n", tempo);
}

// Função principal com menu interativo
int main() {
    int opcao;
    char chaveBusca[30];
    int ordenadoPorNome = 0;  // Flag para indicar se foi ordenado por nome

    do {
        printf("\n=== Sistema de Priorização de Componentes para Torre de Fuga ===\n");
        printf("1. Cadastrar componentes\n");
        printf("2. Ordenar por nome (Bubble Sort)\n");
        printf("3. Ordenar por tipo (Insertion Sort)\n");
        printf("4. Ordenar por prioridade (Selection Sort)\n");
        printf("5. Buscar componente-chave por nome (após ordenação por nome)\n");
        printf("6. Mostrar componentes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpa buffer

        switch (opcao) {
            case 1:
                cadastrarComponentes();
                ordenadoPorNome = 0;  // Reseta flag
                break;
            case 2:
                if (numComponentes > 0) {
                    medirTempo(bubbleSortNome, componentes, numComponentes, "Bubble Sort por Nome");
                    mostrarComponentes(componentes, numComponentes);
                    ordenadoPorNome = 1;  // Marca como ordenado por nome
                } else {
                    printf("Nenhum componente cadastrado.\n");
                }
                break;
            case 3:
                if (numComponentes > 0) {
                    medirTempo(insertionSortTipo, componentes, numComponentes, "Insertion Sort por Tipo");
                    mostrarComponentes(componentes, numComponentes);
                    ordenadoPorNome = 0;  // Não é por nome
                } else {
                    printf("Nenhum componente cadastrado.\n");
                }
                break;
            case 4:
                if (numComponentes > 0) {
                    medirTempo(selectionSortPrioridade, componentes, numComponentes, "Selection Sort por Prioridade");
                    mostrarComponentes(componentes, numComponentes);
                    ordenadoPorNome = 0;  // Não é por nome
                } else {
                    printf("Nenhum componente cadastrado.\n");
                }
                break;
            case 5:
                if (ordenadoPorNome && numComponentes > 0) {
                    printf("Digite o nome do componente-chave: ");
                    fgets(chaveBusca, 30, stdin);
                    chaveBusca[strcspn(chaveBusca, "\n")] = 0;  // Remove newline
                    int pos = buscaBinariaPorNome(componentes, numComponentes, chaveBusca);
                    if (pos != -1) {
                        printf("Componente-chave encontrado na posição %d: %s\n", pos + 1, componentes[pos].nome);
                        printf("Torre ativada! Montagem pode começar.\n");
                    } else {
                        printf("Componente-chave não encontrado.\n");
                    }
                } else {
                    printf("Primeiro ordene por nome (opção 2).\n");
                }
                break;
            case 6:
                if (numComponentes > 0) {
                    mostrarComponentes(componentes, numComponentes);
                } else {
                    printf("Nenhum componente cadastrado.\n");
                }
                break;
            case 0:
                printf("Saindo do sistema.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
