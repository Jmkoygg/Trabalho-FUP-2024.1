# Gestor de Estoque em C

Este é um sistema de gestão de estoque desenvolvido em C para simular o gerenciamento de produtos de um mercado, feito para um trabalho da matéria de fundamentos da programção pela UFC. O sistema utiliza um arquivo de texto para persistência dos dados, permitindo adicionar, editar, remover produtos e realizar operações de compra e reabastecimento.

## 📋 Funcionalidades

- **Processar Compra**: Registra a venda de produtos, atualizando a quantidade no estoque.
- **Reabastecer Estoque**: Adiciona novas unidades de produtos ao estoque.
- **Visualizar Produtos**: Exibe a lista completa de produtos e suas respectivas quantidades.
- **Editar Produto**: Permite alterar o nome e a quantidade de um produto existente.
- **Adicionar Produto**: Adiciona um novo produto ao estoque.
- **Remover Produto**: Exclui um produto do estoque.
- **Persistência de Dados**: Armazena os produtos e suas quantidades em um arquivo chamado `estoque.txt`.

## 🛠️ Tecnologias e Estruturas Utilizadas

- Linguagem: **C**
- Estrutura de Dados: **Struct**
- Manipulação de Arquivos: `fopen`, `fprintf`, `fscanf`
- Organização do Código: Modularização com funções separadas para cada operação.

