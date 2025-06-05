# ED1-T2
Trabalho de estrutura de dados 1 sobre arvores balanceadas

## Pessoa 1 – Criação, destruição e funções auxiliares [Leonardo]

1. Heap* criarHeap(int capacidade);
  - Aloca memória para a struct Heap.
  - Inicializa tamanho = 0 e define capacidade.
  - Aloca o vetor (int* dados) com a capacidade desejada.

---

2. void destruirHeap(Heap* h);
  - Libera a memória alocada para o vetor e para a struct Heap.

---

3. int pai(int i);
  - Retorna o índice do pai do elemento no índice i.
  - Fórmula: (i - 1) / 2

---

4. int filhoEsq(int i);
  - Retorna o índice do filho esquerdo do elemento no índice i.
  - Fórmula: 2 * i + 1

---

5. int filhoDir(int i);
  - Retorna o índice do filho direito do elemento no índice i.
  - Fórmula: 2 * i + 2

---

6. int estaVazio(Heap* h);
  - Retorna 1 se tamanho == 0, senão 0.

---

7. int estaCheio(Heap* h);
  - Retorna 1 se tamanho == capacidade, senão 0.

---

## Pessoa 2 – Inserção e ajuste (subir) [Fabio]

8. void inserir(Heap* h, int valor);
  - Verifica se o heap está cheio.
  - Insere o valor na última posição (h->dados[h->tamanho] = valor).
  - Incrementa o tamanho.
  - Chama subir() para reorganizar o heap.

---

9. void subir(Heap* h, int i);
  - Enquanto o elemento for menor que o pai, troca os dois.
  - Continua subindo até a posição correta ser encontrada.
  - Mantém a propriedade do Heap Mínimo: pais menores que filhos.

---
## Pessoa 3 – Remoção, ajuste (descer) e visualização [Vinicius]

10. int removerMin(Heap* h);
  - Verifica se o heap está vazio.
  - Armazena o menor valor (raiz = dados[0]) para retornar depois.
  - Substitui a raiz pelo último elemento do heap.
  - Diminui o tamanho.
  - Chama descer() para reorganizar o heap.

---

11. void descer(Heap* h, int i);
  - Enquanto o elemento for maior que o menor filho, troca os dois.
  - Continua descendo até a posição correta ser encontrada.
  - Mantém a propriedade do Heap Mínimo.

---

12. int obterMin(Heap* h);
  - Retorna o valor da raiz do heap (posição 0).
  - Não remove nada.

---

13. void imprimirHeap(Heap* h);
  - Percorre o vetor do heap e imprime os elementos na ordem de armazenamento.