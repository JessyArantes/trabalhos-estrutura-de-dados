Explicações e Comentários sobre o Código
Estruturas de Dados: A fila é implementada como um array circular de tamanho fixo 5, com front, rear e count_fila para gerenciar inserções e remoções. A pilha é um array de tamanho 3 com top para operações LIFO.
Geração de Peças: A função gerarPeca cria peças com tipo aleatório e ID incremental, garantindo unicidade.
Manutenção da Fila: Sempre que uma peça é removida da fila (jogar ou reservar), uma nova é gerada automaticamente para manter a fila com 5 peças.
Validações: Cada ação verifica condições (ex.: espaço na pilha, elementos suficientes) antes de executar.
Troca Múltipla: Baseada no exemplo fornecido, as 3 primeiras da fila são invertidas ao ir para a pilha, e as da pilha vão para a fila na ordem topo-base.
Usabilidade: A saída é clara, com exibição do estado após cada ação, e o menu é intuitivo.
Legibilidade e Documentação: O código é modular, com funções separadas para cada ação, nomes descritivos e comentários explicativos.
