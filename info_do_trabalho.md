# Trabalho 2 - Árvores Balanceadas no Mundo Real

## Informações Gerais

* Equipes de 3 pessoas[cite: 1].
* UMA equipe deverá ter 4 membros devido ao número de estudantes participando da disciplina (19)[cite: 1]. O trabalho dessa equipe deverá ter complexidade de acordo com o número de participantes[cite: 2].
* **Entrega:** 23:55 horas do dia 11/06/2025 [cite: 3]
* **Defesa:** aula do dia 12/06/2025 [cite: 3]

## Contexto

Sua equipe foi contratada para desenvolver um sistema de busca eficiente para uma base de dados de pessoas, onde cada registro é identificado por um número de ID numérico e seu primeiro nome[cite: 4]. O sistema deve permitir inserção, remoção e pesquisa rápida desses registros de pessoas, garantindo desempenho estável mesmo com grandes volumes de dados[cite: 4].

## Objetivo

Implementar e utilizar uma estrutura de árvore balanceada para indexar, buscar e analisar dados[cite: 5].
* Cada equipe deverá propor uma variante diferente de árvore binária de busca (ABB) balanceada[cite: 6].
* Nenhuma estrutura de ABB poderá ser repetida entre equipes[cite: 7].
* A escolha ou designação das estruturas será feita no início do projeto via Fórum disponível no Moodle[cite: 8].
* A ordem de envio no Fórum resolverá possíveis repetições de árvores[cite: 8].

## Descrição Geral

Cada grupo deverá pesquisar, estudar, selecionar, implementar e justificar o uso de alguma ABB balanceada diferente da AVL[cite: 9].

Cada equipe deverá:
1.  Selecionar e justificar a árvore escolhida[cite: 10].
2.  Implementar a árvore escolhida do zero (não copiar bibliotecas prontas)[cite: 10].
3.  Implementar um sistema de linha de comando que permite inserir, pesquisar e remover elementos na árvore, além de demonstrar a organização dos elementos na mesma[cite: 11].

---

## Requisitos Específicos

* Linguagem C [cite: 12]
* Documentação do código [cite: 12]
* Interface via terminal para inserção, remoção, pesquisa e visualização [cite: 12]

### Divisão das responsabilidades de implementação

### Entrega e Defesa

Em um arquivo zip, entregar:
* Relatório (até uma página) identificando a equipe, bem como as responsabilidades / atividades de cada um[cite: 12].
* Código-fonte do sistema documentado[cite: 12].

**Defesa:**
* Breve demonstração do sistema funcionando (1 minuto)[cite: 12].
* Explicação da lógica do código-fonte com foco no balanceamento da ABB (3 minutos; 1 para cada operação / pessoa)[cite: 12].
* Esclarecimento de dúvidas / perguntas do professor (3 - 5 minutos)[cite: 12].

## Critérios de Avaliação

Como definido anteriormente, o Trabalho 2 vale 30 pontos, a serem distribuídos da seguinte forma[cite: 12]:
* Adequação e Complexidade da árvores escolhida (3 pontos) [cite: 12]
* Interface para demonstração da árvore (3 pontos) [cite: 12]
* Inserção: Funcionamento e Domínio na Explicação (8 pontos) [cite: 12]
* Remoção: Funcionamento e Domínio na Explicação (8 pontos) [cite: 12]
* Pesquisa: Funcionamento e Domínio na Explicação (8 pontos) [cite: 12]

A avaliação, relativa a cada membro da equipe, será baseada no seguinte[cite: 12]:

| Critério | Descrição Detalhada | Níveis de Desempenho |
| :--- | :--- | :--- |
| **1. Adequação e Complexidade da Árvore Escolhida** | Escolha e justificativa de uma árvore binária de busca balanceada (exceto AVL), com complexidade apropriada para o objetivo do trabalho. | **- 3 pts:** Árvore bem escolhida, com justificativa sólida, adequada ao contexto e com complexidade compatível. <br> **- 2 pts:** Árvore razoável, mas com justificativa incompleta ou de complexidade limitada. <br> **- 1 pt:** Escolha inadequada ou mal justificada. <br> **- 0 pt:** Árvore não justificada ou incorreta. |
| **2. Interface de Demonstração via Terminal** | Implementação funcional e amigável de uma interface para inserção, remoção, pesquisa e visualização da árvore. | **- 3 pts:** Interface completa, funcional e fácil de usar. Permite inserção, remoção, pesquisa e visualização clara. <br> **- 2 pts:** Interface funcional, mas com limitações de usabilidade ou ausência parcial de comandos. <br> **- 1 pt:** Interface incompleta, difícil de usar ou com comandos quebrados. <br> **- 0 pt:** Interface não funcional ou ausente. |
| **3. Inserção: Funcionamento e Domínio na Explicação** | Inserção de elementos na árvore funciona corretamente e os alunos demonstram domínio técnico ao explicá-la. | **- 7-8 pts:** Inserção corretamente implementada, mantém balanceamento; explicação clara e detalhada. <br> **- 5-6 pts:** Inserção implementada corretamente com pequenas falhas; explicação razoável. <br> **- 3-4 pts:** Funcionamento parcial ou balanceamento incorreto; explicação confusa. <br> **- 0-2 pts:** Inserção incorreta ou ausente; explicação inexistente ou errada. |
| **4. Remoção: Funcionamento e Domínio na Explicação** | Remoção de elementos da árvore com manutenção do balanceamento e boa explicação da lógica usada. | **- 7-8 pts:** Remoção corretamente implementada e bem explicada, com ênfase no balanceamento. <br> **- 5-6 pts:** Implementação correta com explicação adequada. <br> **- 3-4 pts:** Remoção funciona parcialmente ou com falhas no balanceamento. <br> **- 0-2 pts:** Remoção incorreta ou ausente; explicação deficiente. |
| **5. Pesquisa: Funcionamento e Domínio na Explicação** | Capacidade de buscar elementos na árvore e explicar o processo de forma clara e segura. | **- 7-8 pts:** Busca eficiente, correta e bem explicada. <br> **- 5-6 pts:** Implementação correta com explicação razoável. <br> **- 3-4 pts:** Busca com falhas ou explicação fraca. <br> **- 0-2 pts:** Busca mal implementada ou explicação ausente/incorreta. |