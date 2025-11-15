Gerenciador de Peças

📝 Descrição

Este é um programa em C que implementa um gerenciador de peças utilizando uma fila circular com capacidade para 5 peças e uma pilha com capacidade para 3 peças. O sistema permite executar ações estratégicas como jogar, reservar, recuperar e realizar trocas entre as peças da fila e da pilha. As peças são geradas automaticamente com tipos aleatórios ('I', 'O', 'T', 'L') e IDs únicos.

✨ Funcionalidades

Inicialização: Fila preenchida com 5 peças geradas aleatoriamente; pilha vazia.
Jogar uma peça: Remove a peça da frente da fila e gera uma nova.
Reservar uma peça: Move a peça da frente da fila para o topo da pilha (se houver espaço).
Usar uma peça reservada: Remove a peça do topo da pilha.
Trocar peça atual: Substitui a peça da frente da fila com o topo da pilha.
Troca múltipla: Alterna as 3 primeiras peças da fila com as 3 da pilha (se ambas tiverem pelo menos 3).
Exibir estado: Mostra o estado atual da fila e pilha após cada ação.
Encerrar: Sai do programa.

🔧 Requisitos

Compilador C (ex.: GCC).
Sistema operacional compatível com terminal (Windows, Linux, macOS).
Bibliotecas padrão incluídas: <stdio.h>, <stdlib.h>, <time.h>.

🚀 Instalação e Compilação

Clone ou baixe o repositório.
Navegue até o diretório do projeto.
Compile o código:

Copy code
gcc gerenciador_pecas.c -o gerenciador_pecas
Execute o programa:

Copy code
./gerenciador_pecas
(No Windows, use gerenciador_pecas.exe).
📖 Como Usar
Execute o programa e siga o menu interativo.
Escolha opções de 1 a 5 para ações, ou 0 para sair.
O estado da fila e pilha é exibido após cada ação.
📊 Exemplo de Uso

Copy code
Estado atual:
Fila de peças	[I 0] [L 1] [T 2] [O 3] [I 4] 
Pilha de reserva	(Topo -> base): Vazia

Opções disponíveis:
1 - Jogar peça da frente da fila
...
Opção escolhida: 2
Ação: Reservou [I 0]

🤝 Contribuição

Contribuições são bem-vindas! Abra uma issue ou pull request no GitHub.

📄 Licença
Este projeto é de uso educacional e não possui licença específica.

Sistema de Priorização de Componentes

📝 Descrição

Este programa em C implementa um sistema de priorização e montagem de componentes para uma torre de fuga, utilizando algoritmos de ordenação (Bubble Sort, Insertion Sort, Selection Sort) e busca binária. O jogador pode ordenar componentes por nome, tipo ou prioridade, medir o desempenho dos algoritmos e buscar um componente-chave após ordenação por nome.


✨ Funcionalidades

Cadastro de Componentes: Até 20 componentes com nome, tipo e prioridade (1-10).
Ordenação:
Bubble Sort por nome.
Insertion Sort por tipo.
Selection Sort por prioridade.
Busca Binária: Localiza um componente-chave após ordenação por nome.
Medição de Desempenho: Conta comparações e mede tempo de execução.
Exibição: Mostra componentes ordenados após cada operação.

🔧 Requisitos

Compilador C (ex.: GCC).
Sistema operacional compatível com terminal (Windows, Linux, macOS).
Bibliotecas padrão incluídas: <stdio.h>, <stdlib.h>, <string.h>, <time.h>.

🚀 Instalação e Compilação

Clone ou baixe o repositório.
Navegue até o diretório do projeto.
Compile o código:

Copy code
gcc sistema_priorizacao.c -o sistema_priorizacao
Execute o programa:

Copy code
./sistema_priorizacao
(No Windows, use sistema_priorizacao.exe).
📖 Como Usar
Execute o programa e siga o menu interativo.
Cadastre componentes, ordene por critério, busque o componente-chave e visualize o desempenho.
📊 Exemplo de Uso

Copy code
1. Cadastrar componentes
2. Ordenar por nome (Bubble Sort)
...
Opção escolhida: 2
Algoritmo: Bubble Sort por Nome
Comparações realizadas: 10
Tempo de execução: 0.000001 segundos
🤝 Contribuição
Contribuições são bem-vindas! Abra uma issue ou pull request no GitHub.

📄 Licença
Este projeto é de uso educacional e não possui licença específica.

Sistema de Detetive
📝 Descrição
Este é um programa em C que simula um jogo de detetive onde o jogador explora uma mansão representada como uma árvore binária, coleta pistas armazenadas em uma árvore BST, associa pistas a suspeitos via tabela hash e acusa um suspeito no final. A acusação é validada se houver pelo menos duas pistas apontando para o suspeito.

✨ Funcionalidades

Exploração da Mansão: Navegação interativa pela árvore binária (esquerda 'e', direita 'd', sair 's').
Coleta de Pistas: Pistas são coletadas e armazenadas em uma BST ordenada.
Associações: Tabela hash mapeia pistas a suspeitos.
Julgamento Final: Lista pistas coletadas, solicita acusação e verifica se há evidências suficientes.
Estruturas de Dados: Árvore binária para mansão, BST para pistas, hash table para associações.

🔧 Requisitos

Compilador C (ex.: GCC).
Sistema operacional compatível com terminal (Windows, Linux, macOS).
Bibliotecas padrão incluídas: <stdio.h>, <stdlib.h>, <string.h>.

🚀 Instalação e Compilação

Clone ou baixe o repositório.
Navegue até o diretório do projeto.
Compile o código:

Copy code
gcc sistema_detetive.c -o sistema_detetive
Execute o programa:

Copy code
./sistema_detetive
(No Windows, use sistema_detetive.exe).
📖 Como Usar
Execute o programa e explore a mansão coletando pistas.
Use 'e' para esquerda, 'd' para direita, 's' para sair.
No final, acuse um suspeito baseado nas pistas.

📊 Exemplo de Uso

Copy code
Você está na sala: Entrada
Pista encontrada: Uma chave enferrujada no chão.
Pista coletada!
Escolha: (e) esquerda, (d) direita, (s) sair: d
...

=== Fase de Julgamento ===

Pistas coletadas:
- Uma chave enferrujada no chão.
Digite o nome do suspeito que você acusa: Jardineiro
Parabéns! Você acusou corretamente. Há 2 pistas apontando para Jardineiro.

🤝 Contribuição
Contribuições são bem-vindas! Abra uma issue ou pull request no GitHub.

📄 Licença
Este projeto é de uso educacional e não possui licença específica.
