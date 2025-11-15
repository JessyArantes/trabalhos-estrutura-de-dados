#include stdio.h
#include stdlib.h
#include time.h

// Definição da struct para representar uma peça
typedef struct {
    char nome;  // Tipo da peça: 'I', 'O', 'T', 'L'
    int id;     // ID único da peça
} Peca;

// Estruturas de dados globais
Peca fila[5];          // Fila circular com capacidade para 5 peças
int front = 0;         // Índice da frente da fila
int rear = 4;          // Índice do final da fila
int count_fila = 5;    // Contador de elementos na fila (sempre 5, exceto no início)

Peca pilha[3];         // Pilha com capacidade para 3 peças
int top = -1;          // Índice do topo da pilha (-1 se vazia)

int id_global = 0;     // Contador global para IDs únicos das peças

// Função para gerar uma nova peça aleatória
Peca gerarPeca() {
    Peca p;
    char tipos[] = {'I', 'O', 'T', 'L'};
    p.nome = tipos[rand() % 4];  // Escolhe um tipo aleatório
    p.id = id_global++;          // Atribui ID único e incrementa
    return p;
}

// Função para inicializar a fila com 5 peças e a pilha vazia
void init() {
    srand(time(NULL));  // Semente para aleatoriedade
    for (int i = 0; i < 5; i++) {
        fila[i] = gerarPeca();  // Preenche a fila com peças geradas
    }
}

// Função para exibir o estado atual da fila e da pilha
void exibir() {
    printf("Estado atual:\n");
    printf("Fila de peças\t");
    for (int i = 0; i < 5; i++) {
        int idx = (front + i) % 5;  // Calcula o índice circular
        printf("[%c %d] ", fila[idx].nome, fila[idx].id);
    }
    printf("\nPilha de reserva\t(Topo -> base): ");
    if (top == -1) {
        printf("Vazia");
    } else {
        for (int i = top; i >= 0; i--) {  // Exibe do topo para a base
            printf("[%c %d] ", pilha[i].nome, pilha[i].id);
        }
    }
    printf("\n\n");
}

// Ação 1: Jogar uma peça (dequeue da fila e gerar nova)
void jogar() {
    if (count_fila > 0) {
        Peca removida = fila[front];  // Remove da frente
        front = (front + 1) % 5;      // Atualiza frente
        count_fila--;                 // Decrementa contador (temporariamente)
        // Gera nova peça para manter a fila cheia
        fila[rear] = gerarPeca();
        rear = (rear + 1) % 5;        // Atualiza rear
        count_fila++;                 // Restaura contador
        printf("Ação: Jogou [%c %d]\n\n", removida.nome, removida.id);
    } else {
        printf("Ação: Fila vazia, não pode jogar\n\n");
    }
}

// Ação 2: Reservar uma peça (move da frente da fila para o topo da pilha)
void reservar() {
    if (count_fila > 0 && top < 2) {  // Verifica se há espaço na pilha
        Peca p = fila[front];         // Pega da frente
        front = (front + 1) % 5;      // Atualiza frente
        count_fila--;                 // Decrementa contador
        pilha[++top] = p;             // Empilha
        // Gera nova peça para manter a fila cheia
        fila[rear] = gerarPeca();
        rear = (rear + 1) % 5;        // Atualiza rear
        count_fila++;                 // Restaura contador
        printf("Ação: Reservou [%c %d]\n\n", p.nome, p.id);
    } else {
        printf("Ação: Não pode reservar (fila vazia ou pilha cheia)\n\n");
    }
}

// Ação 3: Usar uma peça reservada (pop da pilha)
void usar() {
    if (top >= 0) {
        Peca p = pilha[top--];  // Remove do topo
        printf("Ação: Usou [%c %d]\n\n", p.nome, p.id);
    } else {
        printf("Ação: Pilha vazia, não pode usar\n\n");
    }
}

// Ação 4: Trocar peça atual (frente da fila com topo da pilha)
void trocar_atual() {
    if (count_fila > 0 && top >= 0) {
        Peca temp = fila[front];     // Troca
        fila[front] = pilha[top];
        pilha[top] = temp;
        printf("Ação: Trocou frente da fila [%c %d] com topo da pilha [%c %d]\n\n",
               temp.nome, temp.id, fila[front].nome, fila[front].id);
    } else {
        printf("Ação: Não pode trocar (fila vazia ou pilha vazia)\n\n");
    }
}

// Ação 5: Troca múltipla (troca as 3 primeiras da fila com as 3 da pilha)
void troca_multipla() {
    if (count_fila >= 3 && top >= 2) {  // Verifica se ambas têm pelo menos 3 peças
        // Armazena temporariamente as 3 primeiras da fila
        Peca fila_temp[3];
        for (int i = 0; i < 3; i++) {
            int idx = (front + i) % 5;
            fila_temp[i] = fila[idx];
        }
        // Armazena temporariamente as 3 da pilha (topo para base)
        Peca pilha_temp[3];
        for (int i = 0; i < 3; i++) {
            pilha_temp[i] = pilha[top - i];
        }
        // Coloca as da pilha nas 3 primeiras da fila (na ordem topo-base)
        for (int i = 0; i < 3; i++) {
            int idx = (front + i) % 5;
            fila[idx] = pilha_temp[i];
        }
        // Coloca as da fila na pilha, invertidas (para manter LIFO)
        for (int i = 0; i < 3; i++) {
            pilha[top - i] = fila_temp[2 - i];  // Inverte a ordem
        }
        printf("Ação: Troca múltipla realizada\n\n");
    } else {
        printf("Ação: Não pode fazer troca múltipla (fila ou pilha com menos de 3 peças)\n\n");
    }
}

// Função principal
int main() {
    init();  // Inicializa as estruturas
    int op;
    do {
        exibir();  // Exibe o estado atual
        printf("Opções disponíveis:\n");
        printf("1 - Jogar peça da frente da fila\n");
        printf("2 - Enviar peça da fila para a pilha de reserva\n");
        printf("3 - Usar peça da pilha de reserva\n");
        printf("4 - Trocar peça da frente da fila com o topo da pilha\n");
        printf("5 - Trocar os 3 primeiros da fila com as 3 peças da pilha\n");
        printf("0 - Sair\n");
        printf("Opção escolhida: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                jogar();
                break;
            case 2:
                reservar();
                break;
            case 3:
                usar();
                break;
            case 4:
                trocar_atual();
                break;
            case 5:
                troca_multipla();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n\n");
        }
    } while (op != 0);
    return 0;
}
