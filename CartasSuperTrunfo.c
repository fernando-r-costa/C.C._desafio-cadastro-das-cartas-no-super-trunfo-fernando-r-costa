#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variáveis separadas por atributos de cada cidade.
    char codigoCarta_1[4], codigoCarta_2[4];
    char estado_1, estado_2;
    char cidade_1[31], cidade_2[31];
    unsigned int populacao_1, populacao_2;
    float area_1, area_2;
    float pib_1, pib_2;
    int pontosTuristicos_1, pontosTuristicos_2;
    float densidadePopulacional_1, densidadePopulacional_2;
    float pibPerCapita_1, pibPerCapita_2;
    float superPoder_1, superPoder_2;

    // Variáveis para comparação de cartas.
    int resultadoPopulacao, resultadoArea, resultadoPib, resultadoPontosTuristicos, resultadoDensidadePopulacional, resultadoPibPerCapita, resultadoSuperPoder;

    // Cadastro das Cartas:
    // Captura das entradas do usuário para cada atributo de cada carta.
    printf("*** Cadastro da Carta 1 ***\n");
    printf("Insira o estado: ");
    scanf(" %c", &estado_1);
    printf("Insira o código: ");
    scanf("%3s", codigoCarta_1);
    scanf("%*c"); // Limpeza do buffer de entrada.
    printf("Insira o nome da cidade: ");
    fgets(cidade_1, 31, stdin);
    cidade_1[strcspn(cidade_1, "\n")] = 0;
    printf("Insira a população: ");
    scanf("%d", &populacao_1);
    printf("Insira a área: ");
    scanf("%f", &area_1);
    printf("Insira o PIB: ");
    scanf("%f", &pib_1);
    printf("Insira a quantidade de pontos turísticos: ");
    scanf("%d", &pontosTuristicos_1);

    printf("\n*** Cadastro da Carta 2 ***\n");
    printf("Insira o estado: ");
    scanf(" %c", &estado_2);
    printf("Insira o código: ");
    scanf("%3s", codigoCarta_2);
    scanf("%*c"); // Limpeza do buffer de entrada.
    printf("Insira o nome da cidade: ");
    fgets(cidade_2, 31, stdin);
    cidade_2[strcspn(cidade_2, "\n")] = 0;
    printf("Insira a população: ");
    scanf("%d", &populacao_2);
    printf("Insira a área: ");
    scanf("%f", &area_2);
    printf("Insira o PIB: ");
    scanf("%f", &pib_2);
    printf("Insira a quantidade de pontos turísticos: ");
    scanf("%d", &pontosTuristicos_2);

    // Cálculo da Densidade Populacional e PIB per Capita:
    densidadePopulacional_1 = (float) populacao_1 / area_1;
    densidadePopulacional_2 = (float) populacao_2 / area_2;
    pibPerCapita_1 = (float) (pib_1*1000000000) / populacao_1;
    pibPerCapita_2 = (float) (pib_2*1000000000) / populacao_2;

    // Cálculo do Super Poder:
    superPoder_1 = populacao_1 + area_1 + pib_1 + pontosTuristicos_1 + (1 / densidadePopulacional_1) + pibPerCapita_1;
    superPoder_2 = populacao_2 + area_2 + pib_2 + pontosTuristicos_2 + (1 / densidadePopulacional_2) + pibPerCapita_2;

    // Resultado da Batalha de Cartas:
    resultadoPopulacao = populacao_1 > populacao_2;
    resultadoArea = area_1 > area_2;
    resultadoPib = pib_1 > pib_2;
    resultadoPontosTuristicos = pontosTuristicos_1 > pontosTuristicos_2;
    resultadoDensidadePopulacional = densidadePopulacional_1 < densidadePopulacional_2;
    resultadoPibPerCapita = pibPerCapita_1 > pibPerCapita_2;
    resultadoSuperPoder = superPoder_1 > superPoder_2;

    // Exibição dos Dados das Cartas:
    printf("\n### Carta 1: ###\n");
    printf("Estado: %c\n", estado_1);
    printf("Código: %s\n", codigoCarta_1);
    printf("Nome da Cidade: %s\n", cidade_1);
    printf("População: %d\n", populacao_1);
    printf("Área: %.2f km²\n", area_1);
    printf("PIB: %.2f bilhões de reais\n", pib_1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos_1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional_1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita_1);
    printf("Super Poder: %.2f\n", superPoder_1);
    
    printf("\n### Carta 2: ###\n");
    printf("Estado: %c\n", estado_2);
    printf("Código: %s\n", codigoCarta_2);
    printf("Nome da Cidade: %s\n", cidade_2);
    printf("População: %d\n", populacao_2);
    printf("Área: %.2f km²\n", area_2);
    printf("PIB: %.2f bilhões de reais\n", pib_2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos_2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional_2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita_2);
    printf("Super Poder: %.2f\n", superPoder_2);
    
    // Exibição do Resultado da Batalha de Cartas:
    printf("\n###*** Resultado da Batalha de Cartas: ***###\n");
    printf("*** Resultado (1): Venceu! ***\n");
    printf("*** Resultado (0): Perdeu! ***\n");
    printf("População: Carta 1 venceu? (%d)\n", resultadoPopulacao);
    printf("Área: Carta 1 venceu? (%d)\n", resultadoArea);
    printf("PIB: Carta 1 venceu? (%d)\n", resultadoPib);
    printf("Pontos Turísticos: Carta 1 venceu? (%d)\n", resultadoPontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu? (%d)\n", resultadoDensidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu? (%d)\n", resultadoPibPerCapita);
    printf("Super Poder: Carta 1 venceu? (%d)\n", resultadoSuperPoder);
    
    // Exibição da decisão de vitória para Densidade e PIB
    printf("\n>>> A cidade que possui a menor densidade demográfica é: ");
    if (densidadePopulacional_1 < densidadePopulacional_2) {
        printf("Carta 1 %s\n", cidade_1);
    } else {
        printf("Carta 2 %s\n", cidade_2);
    }

    printf("\n>>> A cidade que possui o maior PIB per capita é: ");
    if (pibPerCapita_1 > pibPerCapita_2) {
        printf("Carta 1 %s\n", cidade_1);
    } else {
        printf("Carta 2 %s\n", cidade_2);
    }

    // Escolha dos atributos para a batalha
    int atributoEscolhido1, atributoEscolhido2, batalha1, batalha2;

    printf("\nEscolha o primeiro atributo para a batalha:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Sua escolha: ");
    scanf("%d", &atributoEscolhido1);

    switch (atributoEscolhido1) {
        case 1:
            printf("\nAtributo escolhido: População\n");
            if (resultadoPopulacao) {
                printf("Carta 1 %s\n", cidade_1);
                batalha1 = resultadoPopulacao;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha1 = resultadoPopulacao;
            }
            break;
        case 2:
            printf("\nAtributo escolhido: Área\n");
            if (resultadoArea) {
                printf("Carta 1 %s\n", cidade_1);
                batalha1 = resultadoArea;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha1 = resultadoArea;
            }
            break;
        case 3:
            printf("\nAtributo escolhido: PIB\n");
            if (resultadoPib) {
                printf("Carta 1 %s\n", cidade_1);
                batalha1 = resultadoPib;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha1 = resultadoPib;
            }
            break;
        case 4:
            printf("\nAtributo escolhido: Número de Pontos Turísticos\n");
            if (resultadoPontosTuristicos) {
                printf("Carta 1 %s\n", cidade_1);
                batalha1 = resultadoPontosTuristicos;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha1 = resultadoPontosTuristicos;
            }
            break;
        case 5:
            printf("\nAtributo escolhido: Densidade Populacional\n");
            if (resultadoDensidadePopulacional) {
                printf("Carta 1 %s\n", cidade_1);
                batalha1 = resultadoDensidadePopulacional;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha1 = resultadoDensidadePopulacional;
            }
            break;
        default:
            printf("Opção inválida.\n");
    }

    printf("\nEscolha o segundo atributo para a batalha:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Sua escolha: ");
    scanf("%d", &atributoEscolhido2);

    (atributoEscolhido1 == atributoEscolhido2) ? (printf("Você escolheu o mesmo atributo!\n"), exit(0)) : 0;

    switch (atributoEscolhido2) {
        case 1:
            printf("\nAtributo escolhido: População\n");
            if (resultadoPopulacao) {
                printf("Carta 1 %s\n", cidade_1);
                batalha2 = resultadoPopulacao;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha2 = resultadoPopulacao;
            }
            break;
        case 2:
            printf("\nAtributo escolhido: Área\n");
            if (resultadoArea) {
                printf("Carta 1 %s\n", cidade_1);
                batalha2 = resultadoArea;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha2 = resultadoArea;
            }
            break;
        case 3:
            printf("\nAtributo escolhido: PIB\n");
            if (resultadoPib) {
                printf("Carta 1 %s\n", cidade_1);
                batalha2 = resultadoPib;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha2 = resultadoPib;
            }
            break;
        case 4:
            printf("\nAtributo escolhido: Número de Pontos Turísticos\n");
            if (resultadoPontosTuristicos) {
                printf("Carta 1 %s\n", cidade_1);
                batalha2 = resultadoPontosTuristicos;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha2 = resultadoPontosTuristicos;
            }
            break;
        case 5:
            printf("\nAtributo escolhido: Densidade Populacional\n");
            if (resultadoDensidadePopulacional) {
                printf("Carta 1 %s\n", cidade_1);
                batalha2 = resultadoDensidadePopulacional;
            } else {
                printf("Carta 2 %s\n", cidade_2);
                batalha2 = resultadoDensidadePopulacional;
            }
            break;
        default:
            printf("Opção inválida.\n");
    }

    // Exibição do resultado da batalha
    printf("\n### Resultado Final da Batalha ###\n");
    if (batalha1 == 1 && batalha2 == 1) {
        printf("Carta 1 %s venceu ambas as batalhas!\n", cidade_1);
    } else if (batalha1 == 0 && batalha2 == 0) {
        printf("Carta 2 %s venceu ambas as batalhas!\n", cidade_2);
    } else {
        printf("Houve empate!\n");
    }

    return 0;
}
