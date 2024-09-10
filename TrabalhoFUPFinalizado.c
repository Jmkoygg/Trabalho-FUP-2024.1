#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 20;

struct Produtos {
    char nome[50];
    int quantidade;
};
//Funções de Menu
void Menu() {
    puts("Bem vindo ao gestor de estoque do mercado, o que deseja fazer?");
    puts("1-Processar Compra");
    puts("2-Processar Reabastecimento de estoque");
    puts("3-Ver produtos do estoque");
    puts("4-Editar produto");
    puts("5-Adicionar novo produto no estoque");
    puts("6-Remover produto do estoque");
    puts("0-Encerrar");
}
void voltar() {
    puts("Voltando para o menu!");
    printf("Pressione Enter para continuar...\n");
    while (getchar() != '\n');
    getchar();
}
//Funções de Produto
void escolherProduto(struct Produtos array[], int p) {
    for (int i = 0; i < p; i++) {
        printf("%d-%s\n", i, array[i].nome);
    }
}
void Mostrarprodutos(struct Produtos array[], int p) {
    for (int i = 0; i < p; i++) {
        printf("Item %d: %s, %d\n", i, array[i].nome, array[i].quantidade);
    }
}
//Funções de estoque
void SalvarEstoque(struct Produtos array[], int p) {
    FILE *file = fopen("estoque.txt", "w");
    if (file == NULL) {
        puts("Erro ao abrir o arquivo estoque.txt para escrita.");
        return;
    }

    for (int i = 0; i < p; i++) {
        fprintf(file, "%s;%d\n", array[i].nome, array[i].quantidade);
    }

    fclose(file);
}
void CarregarEstoque(struct Produtos array[], int *p) {
    FILE *file = fopen("estoque.txt", "r");
    if (file == NULL) {
        puts("Erro ao abrir o arquivo estoque.txt para leitura.");
        *p = 0;
        return;
    }

    *p = 0;
    while (fscanf(file, "%49[^;];%d\n", array[*p].nome, &array[*p].quantidade) == 2) {
        (*p)++;
    }

    fclose(file);
}
//Funções do programa
void processarCompra(struct Produtos array[], int p) {
    int e, c;
    puts("Escolha qual produto foi comprado");
    escolherProduto(array, p);
    scanf("%d", &e);
    if (e < 0 || e >= p) {
        puts("Produto inválido!");
    } else {
        puts("Quantos Produtos foram comprados?");
        scanf("%d", &c);
        if (array[e].quantidade-c < 0) {
            puts("Compra cancelada, quantidade de produto insuficiente");
        } else {
            array[e].quantidade -= c;
            printf("Compra registrada, nova quantidade de %s é %d\n", array[e].nome, array[e].quantidade);
        }
    }
}

void processarReabastecimento(struct Produtos array[], int p) {
    int e, c;
    puts("Escolha qual produto foi reabastecido");
    escolherProduto(array, p);
    scanf("%d", &e);
    if (e < 0 || e >= p) {
        puts("Produto inválido!");
    } else {
        puts("Quantos Produtos chegaram?");
        scanf("%d", &c);
        array[e].quantidade += c;
        printf("O reabastecimento foi registrado, nova quantidade de %s é %d\n", array[e].nome, array[e].quantidade);
    }
}

void editarProduto(struct Produtos array[], int p) {
    int e, c, o2;
    puts("Escolha o produto para ser editado");
    escolherProduto(array, p);
    scanf("%d", &e);
    if (e < 0 || e >= p) {
        puts("Produto inválido!");
    } else {
        puts("Deseja mudar o nome do produto?");
        puts("1-Sim, 2-Não");
        scanf("%d", &o2);
        if (o2 == 1) {
            puts("Digite o nome desejado");
            scanf("%s", array[e].nome);
        }
        puts("Qual a quantidade atual dos produtos?");
        scanf("%d", &c);
        if (c < 0) {
            puts("A quantidade de produto não pode ser negativa");
        } else {
            array[e].quantidade = c;
            printf("A quantidade de %s foi atualizada para %d\n", array[e].nome, array[e].quantidade);
        }
    }
}

void adicionarProduto(struct Produtos array[], int *p) {
    if (*p < N) {
        puts("Insira o nome do novo produto");
        scanf("%s", array[*p].nome);
        puts("Insira a quantidade do novo produto");
        scanf("%d", &array[*p].quantidade);
        (*p)++;
        puts("Produto registrado com sucesso");
    } else {
        puts("Estoque cheio");
    }
}

void removerProduto(struct Produtos array[], int *p) {
    int e;
    puts("Qual produto deseja remover?");
    escolherProduto(array, *p);
    scanf("%d", &e);
    if (e >= 0 && e < *p) {
        for (int i = e; i < *p - 1; i++) {
            strcpy(array[i].nome, array[i + 1].nome);
            array[i].quantidade = array[i + 1].quantidade;
        }
        (*p)--;
        puts("Produto removido com sucesso!");
    } else {
        puts("Produto inválido!");
    }
}



int main() {
    struct Produtos array[N];
    int o, p = 0;
    CarregarEstoque(array, &p);

    while (1) {
        Menu();
        scanf("%d", &o);
        switch (o) {
            case 0:
                SalvarEstoque(array, p);
                exit(0);

            case 1:
                processarCompra(array, p);
                break;

            case 2:
                processarReabastecimento(array, p);
                break;

            case 3:
                Mostrarprodutos(array, p);
                break;

            case 4:
                editarProduto(array, p);
                break;

            case 5:
                adicionarProduto(array, &p);
                break;

            case 6:
               removerProduto(array, &p);
                break;

            default:
                puts("Opção inválida, tente novamente");
                break;
        }
    SalvarEstoque(array, p);
    voltar();
    }
}
