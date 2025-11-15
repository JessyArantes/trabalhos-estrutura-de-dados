Gerenciador de Peças

Descrição

Este é um programa em C que implementa um gerenciador de peças utilizando duas estruturas de dados: uma fila circular com capacidade para 5 peças e uma pilha com capacidade para 3 peças. O sistema permite executar ações estratégicas como jogar, reservar, recuperar e realizar trocas entre as peças da fila e da pilha. As peças são geradas automaticamente com tipos aleatórios ('I', 'O', 'T', 'L') e IDs únicos.

O foco principal é demonstrar o uso combinado de fila circular e pilha, com operações de manipulação eficiente de elementos.

Funcionalidades
Inicialização: A fila é preenchida com 5 peças geradas aleatoriamente. A pilha começa vazia.
Jogar uma peça: Remove a peça da frente da fila e gera uma nova para manter a fila cheia.
Reservar uma peça: Move a peça da frente da fila para o topo da pilha (se houver espaço) e gera uma nova peça para a fila.
Usar uma peça reservada: Remove a peça do topo da pilha.
Trocar peça atual: Substitui a peça da frente da fila com o topo da pilha.
Troca múltipla: Alterna as três primeiras peças da fila com as três peças da pilha (se ambas tiverem pelo menos 3 peças).
Exibir estado: Mostra o estado atual da fila e da pilha após cada ação.
Encerrar: Sai do programa.
Requisitos
Compilador C (ex.: GCC).
Sistema operacional compatível com terminal (Windows, Linux, macOS).
Bibliotecas padrão incluídas: <stdio.h>, <stdlib.h>, <time.h>.
Como Compilar e Executar
Salve o código em um arquivo chamado gerenciador_pecas.c.
Abra um terminal e navegue até o diretório onde o arquivo está salvo.
Compile o programa usando GCC:

Copy code
gcc gerenciador_pecas.c -o gerenciador_pecas
Execute o programa:

Copy code
./gerenciador_pecas
No Windows, use gerenciador_pecas.exe em vez de ./gerenciador_pecas.
Exemplo de Uso
Após executar o programa, você verá o estado inicial da fila e pilha, seguido de um menu de opções. Escolha uma opção digitando o número correspondente e pressione Enter.

Exemplo de saída inicial:


Copy code
Estado atual:
Fila de peças	[I 0] [L 1] [T 2] [O 3] [I 4] 
Pilha de reserva	(Topo -> base): Vazia

Opções disponíveis:
1 - Jogar peça da frente da fila
2 - Enviar peça da fila para a pilha de reserva
3 - Usar peça da pilha de reserva
4 - Trocar peça da frente da fila com o topo da pilha
5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
0 - Sair
Opção escolhida: 2

Ação: Reservou [I 0]

Novo estado:
Fila de peças	[L 1] [T 2] [O 3] [I 4] [O 5] 
Pilha de reserva	(Topo -> base): [I 0]
Notas Técnicas
Fila Circular: Implementada com array de tamanho fixo, reutilizando espaço para eficiência.
Pilha: Implementada com array e índice de topo para operações LIFO.
Geração de Peças: Usa rand() para tipos aleatórios e um contador global para IDs únicos.
Validações: Operações só são executadas se as condições forem atendidas (ex.: espaço na pilha ou elementos suficientes).
Troca Múltipla: Baseada no exemplo fornecido, invertendo a ordem ao transferir entre estruturas para manter a lógica de fila e pilha.
O programa mantém a fila sempre com 5 peças, gerando novas automaticamente após remoções.
