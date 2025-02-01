/*
* @folder numeroNome_ExameP1
* @brief Gest�o da inspecao de veiculos
* @date 09-01-2024
* @author (COLOCAR O NUMERO, NOME E EMAIL)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoesGenericas.h"
#include "veiculo.h"
#include "exame.h"

int menu(int quantVeiculos);

/** ------------------------------ main ------------------------------ **/

int main()
{
    tipoInspecao *vetorInspecoes = NULL;
    int quantInspecoes;
    quantInspecoes = 0;


    tipoVeiculo vetorVeiculos[MAX_VEICULOS];
    int quantVeiculos, opcao, opcaoGravar;

    quantVeiculos = 0;

    lerFicheiroBinarioVeiculos(vetorVeiculos, &quantVeiculos);

    do
    {
        opcao = menu(quantVeiculos);
        switch (opcao)
        {
        case 1:  // inserir novo Veiculos
            quantVeiculos=inserirNovoVeiculo(vetorVeiculos, quantVeiculos);
            break;
        case 2 : // Listar Veiculos
            listarVeiculos(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 3:
            listarVeiculosPesados(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 4:
            listarVeiculosPorMarca(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 5:
            atualizarDistanciaPercorrida(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 6:
            vetorInspecoes=registarInspecaoNova(vetorVeiculos, vetorInspecoes, &quantInspecoes, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 7:
            listarInspecoesVeiculo(vetorVeiculos, vetorInspecoes, quantInspecoes, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 8:
            mostrarVeiculosMenosFiaveis(vetorVeiculos, vetorInspecoes, quantInspecoes, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 9:
            escreverFicheiroTextoInspecoes(vetorVeiculos, vetorInspecoes, quantInspecoes, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 0:
            printf("\n\n Saida!");
            break;
        }
    }
    while (opcao != 0);

    printf("\n\n Deseja armazenar no ficheiro os dados dos veiculos (1-Sim  2-Nao) \n ");
    opcaoGravar=lerInteiro("\t\t Indique a opcao:", 1, 2);
    if (opcaoGravar==1)
    {
        escreverFicheiroBinarioVeiculos(vetorVeiculos, quantVeiculos);
    }

    free(vetorInspecoes);
    return 0;
}

/** ------------------------------ Menu Principal ------------------------------ **/

int menu(int quantVeiculos)
{
    int opcao;

    printf("\n\n---------------- INSPECAO DE VEICULOS DE FROTA ----------------\n");
    printf("\nTOTAL VEICULOS: %d\n\n", quantVeiculos);

    printf("\n- VEICULOS -\n");
    printf("\t1  - Adicionar novo Veiculos\n\t2  - Listar Veiculos\n");

    printf(" - EXAME -\n");
    printf("\t3  - Listar Veiculos Pesados \n\t4  - Listar Veiculos por Marca\n");
    printf("\t5  - Atualizar Distancia Percorrida\n\t6  - Registar Inspecao\n");
    printf("\t7  - Listar Inspecoes por Veiculo \n\t8  - Veiculos Menos Fiaveis \n");
    printf("\t9  - Escrever Ficheiro de texto \n");

    printf("\n\t0  - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 9);

    return opcao;
}




