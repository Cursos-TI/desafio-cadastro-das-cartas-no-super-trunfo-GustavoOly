#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para definir um molde comum para todas as cartas.
typedef struct {
    char *estado;
    char *codigo_da_carta;
    char *cidade;
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// função para fazer o cadastro da carta na lista.
Carta *cadastrar_cartas(Carta *cartas, int tamanho_lista) {
    cartas = (Carta *)realloc(cartas, (tamanho_lista + 1) * sizeof(Carta));
    if (cartas == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    cartas[tamanho_lista].estado = (char *)malloc(30 * sizeof(char));
    cartas[tamanho_lista].codigo_da_carta = (char *)malloc(20 * sizeof(char));
    cartas[tamanho_lista].cidade = (char *)malloc(30 * sizeof(char));

    printf("Digite o estado: ");
    scanf("%s", cartas[tamanho_lista].estado);
    getchar();

    printf("Digite o codigo da carta: ");
    scanf(" %s", cartas[tamanho_lista].codigo_da_carta);
    getchar();

    printf("Digite a cidade: ");
    scanf(" %s", cartas[tamanho_lista].cidade);
    getchar();

    printf("Digite a populacao: ");
    scanf("%lu", &cartas[tamanho_lista].populacao);
    getchar();

    printf("Digite a area: ");
    scanf("%f", &cartas[tamanho_lista].area);
    getchar();

    printf("Digite o pib: ");
    scanf("%f", &cartas[tamanho_lista].pib);
    getchar();

    printf("Digite os pontos turisticos: ");
    scanf("%i", &cartas[tamanho_lista].pontos_turisticos);
    getchar();

    cartas[tamanho_lista].densidade_populacional =
        cartas[tamanho_lista].populacao / cartas[tamanho_lista].area;
    printf("Densidade populacional: %.2f\n",
           cartas[tamanho_lista].densidade_populacional);

    cartas[tamanho_lista].pib_per_capita =
        cartas[tamanho_lista].pib / cartas[tamanho_lista].populacao;
    printf("Pib per capita: %.2f\n", cartas[tamanho_lista].pib_per_capita);

    cartas[tamanho_lista].super_poder =
        cartas[tamanho_lista].pib_per_capita + cartas[tamanho_lista].populacao +
        cartas[tamanho_lista].pontos_turisticos + cartas[tamanho_lista].area +
        cartas[tamanho_lista].densidade_populacional +
        cartas[tamanho_lista].pib;
    printf("Super poder: %.2f\n", cartas[tamanho_lista].super_poder);

    return cartas;
}

// procedimento para exibir os membros das cartas.
void exibir_cartas(Carta *cartas, int size) {
    if (cartas == NULL) {
        printf("A lista está vazia\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        if (cartas[i].estado == NULL || cartas[i].codigo_da_carta == NULL ||
            cartas[i].cidade == NULL) {
            printf("Erro: A carta na posição %d contém um ponteiro nulo.\n", i);
            continue;
        }
        printf("\nEstado: %s\n", cartas[i].estado);
        printf("Codigo da carta: %s\n", cartas[i].codigo_da_carta);
        printf("Cidade: %s\n", cartas[i].cidade);
        printf("Populacao: %lu\n", cartas[i].populacao);
        printf("Area: %.2f\n", cartas[i].area);
        printf("Pib: %.2f\n", cartas[i].pib);
        printf("Pontos turisticos: %i\n", cartas[i].pontos_turisticos);
        printf("Densidade populacional: %.2f\n",
               cartas[i].densidade_populacional);
        printf("Pib per capita: %.2f\n", cartas[i].pib_per_capita);
        printf("Super poder: %.2f\n", cartas[i].super_poder);
    }
}

// função para fazer a comparação de poderes entre duas cartas.
int comparar_cartas(Carta *cartas, int tamanho_lista) {
    int carta1_index = -1, carta2_index = -1;
    char *carta1;
    char *carta2;
    carta1 = (char *)malloc(20 * sizeof(char));
    carta2 = (char *)malloc(20 * sizeof(char));
    puts("Escolha a primeira carta, especificando seu codigo:");
    scanf("%s", carta1);
    puts("Escolha a segunda carta, especificando seu codigo:");
    scanf("%s", carta2);
    if (cartas == NULL) {
        printf("A lista de cartas está vazia\n");
        return 1;
    }
    for (int i = 0; i < tamanho_lista; i++) {
        if (strcmp(cartas[i].codigo_da_carta, carta1) == 0) {
            carta1_index = i;
        }
        if (strcmp(cartas[i].codigo_da_carta, carta2) == 0) {
            carta2_index = i;
        }
    }
    if (carta1_index == -1 || carta2_index == -1) {
        printf("Carta não encontrada\n");
        return 1;
    }
    printf("População: %lu vs %lu - %s\n", cartas[carta1_index].populacao,
           cartas[carta2_index].populacao,
           cartas[carta1_index].populacao > cartas[carta2_index].populacao
               ? "Carta 1 venceu"
               : "Carta 2 venceu");
    printf("Área: %.2f vs %.2f - %s\n", cartas[carta1_index].area,
           cartas[carta2_index].area,
           cartas[carta1_index].area > cartas[carta2_index].area
               ? "Carta 1 venceu"
               : "Carta 2 venceu");
    printf("PIB: %.2f vs %.2f - %s\n", cartas[carta1_index].pib,
           cartas[carta2_index].pib,
           cartas[carta1_index].pib > cartas[carta2_index].pib
               ? "Carta 1 venceu"
               : "Carta 2 venceu");
    printf("PIB per capita: %.2f vs %.2f - %s\n",
           cartas[carta1_index].pib_per_capita,
           cartas[carta2_index].pib_per_capita,
           cartas[carta1_index].pib_per_capita >
                   cartas[carta2_index].pib_per_capita
               ? "Carta 1 venceu"
               : "Carta 2 venceu");
    printf("Densidade populacional: %.2f vs %.2f - %s\n",
           cartas[carta1_index].densidade_populacional,
           cartas[carta2_index].densidade_populacional,
           cartas[carta1_index].densidade_populacional <
                   cartas[carta2_index].densidade_populacional
               ? "Carta 1 venceu"
               : "Carta 2 venceu");
    printf("Pontos turísticos: %i vs %i - %s\n",
           cartas[carta1_index].pontos_turisticos,
           cartas[carta2_index].pontos_turisticos,
           cartas[carta1_index].pontos_turisticos >
                   cartas[carta2_index].pontos_turisticos
               ? "Carta 1 venceu"
               : "Carta 2 venceu");
    printf("Super poder: %.2f vs %.2f - %s\n", cartas[carta1_index].super_poder,
           cartas[carta2_index].super_poder,
           cartas[carta1_index].super_poder > cartas[carta2_index].super_poder
               ? "Carta 1 venceu"
               : "Carta 2 venceu");

    return 0;
}

// função principal
int main() {
    int navegacao;
    int tamanho_lista = 0;
    Carta *cartas = NULL;
    do {
        puts("\n1 - Cadastrar lista");
        puts("2 - Ver listas cadastradas");
        puts("3 - Comparar poderes");
        puts("0 - Sair");

        printf("\nDigito: ");
        scanf("%i", &navegacao);

        switch (navegacao) {
        case 1:
            cartas = cadastrar_cartas(cartas, tamanho_lista);
            tamanho_lista++;
            break;
        case 2:
            exibir_cartas(cartas, tamanho_lista);
            break;
        case 3:
            comparar_cartas(cartas, tamanho_lista);
            break;
        case 0:
            puts("Até a proxima");
            break;
        default:
            printf("\033[31m"
                   "\n=================="
                   "\nOpção invalida\n"
                   "==================\n"
                   "\033[0m");
        };
    } while (navegacao != 0);
    for (int i = 0; i < tamanho_lista; i++) {
        free(cartas[i].estado);
        free(cartas[i].codigo_da_carta);
        free(cartas[i].cidade);
    }
    free(cartas);
    return 0;
}
