#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "veiculo.h"
#include "exame.h"

void listarVeiculosPesados(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos){
    int i, totalPesados;
    float percentagem;
    totalPesados=0;
    if(quantVeiculos>0){
        printf("\n\n********** LISTA DE VEICULOS PESADOS **********\n");
        for(i=0;i<quantVeiculos;i++){
            if(vetorVeiculos[i].tipo==2){
                printf("\nMatricula: %s \nMarca: %s. \nTotal de Kms: %d\n", vetorVeiculos[i].matricula, vetorVeiculos[i].marca, vetorVeiculos[i].totalKms);
                totalPesados++;
            }
        }
    }
    else{
        printf("\nNao existem veiculos registados.");
    }
    percentagem=((float)totalPesados/quantVeiculos)*100;
    printf("\nPercentagem de veiculos pesados: %.2f%%\n", percentagem);

}

void listarVeiculosMarca(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos){
    int i;
    char procurado[TEXTO_CURTO];
    char t[TEXTO_CURTO];
    int tt;

    int veiculos,kmtotal;
    kmtotal=0;
    veiculos=0;
    int media;
    media=0;

    if(quantVeiculos>0){
        printf("\n\n********** LISTAR VEICULOS POR MARCA **********\n");
        lerString("\nInsira a marca que procura: ", procurado, TEXTO_CURTO);
        converteMaiuscula(procurado);
        for(i=0;i<quantVeiculos;i++){
            if(strcmp(procurado,vetorVeiculos[i].marca)==0 && vetorVeiculos[i].anoRegisto>2020){
                tt=vetorVeiculos[i].tipo;
                switch(tt){
                    case 1:
                        strcpy(t,"Ligeiro");
                        break;
                    case 2:
                        strcpy(t,"Pesado");
                        break;
                    case 3:
                        strcpy(t,"Reboque");
                        break;
                }

                printf("\nModelo: %s.\nTipo: %s.\n", vetorVeiculos[i].modelo, t);
                veiculos++;
                kmtotal+=vetorVeiculos[i].totalKms;
            }
        }

    }else{
        printf("\nNao existem veiculos registados.");
    }

    media=(kmtotal/veiculos);
    printf("\nMedia de Kms percorridos: %dkm", media);
}

void atualizarDistanciaPercorrida(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos){
    int i, nova, att;
    nova=0;
    att=0;

    if(quantVeiculos>0){
            printf("\n\n********** ATUALIZAR DISTANCIA PERCORRIDA **********\n");
            for(i=0;i<quantVeiculos;i++){
                escreverVeiculo(vetorVeiculos[i]);
                nova=lerInteiro("\nInsira os Kms atualizados do veiculo:", vetorVeiculos[i].totalKms, 999999);
                att=nova-vetorVeiculos[i].totalKms;
                printf("Kms percorridos ate agora: %d\n", att);
                vetorVeiculos[i].totalKms=nova;
            }


    }else{
        printf("\nNao existem veiculos registados.");
    }

}

tipoInspecao *CriarNovaInspecao(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantVeiculos, int *quantInspecoes){
    tipoInspecao p;
    tipoInspecao *backup;
    backup=vetorInspecoes;

    int i;
    int existe;
    existe=0;

    char matricula[TAM_MATRICULA];
    int encontrada;


    if(*quantVeiculos>0){
        printf("\n\n********** REGISTAR NOVA INSPECAO **********\n");
        p.codigo=*quantInspecoes+1;

        lerString("\nInsira a matricula do automovel: ", matricula, TAM_MATRICULA);
        converteMaiuscula(matricula);
        encontrada=procurarVeiculo(vetorVeiculos,*quantVeiculos,matricula);
        if(encontrada==-1){
            printf("\nMatricula nao encontrada.");
            return 0;
        }

        strcpy(p.matricula, matricula);
        p.totalKms = vetorVeiculos[encontrada].totalKms;

        p.Data.dia=lerInteiro("\nInsira o dia:",0,31);
        p.Data.mes=lerInteiro("\nInsira o Mes:",0,12);
        p.Data.ano=lerInteiro("\nInsira o Ano:",2000,2030);

        lerString("\nDigite o resultado (Aprovado/Reprovado): ",p.resultado, TEXTO_CURTO);

        lerString("\nDigite anotacoes sobre a inspecao: ",p.anotacoes, TEXTO_LONGO);

        p.custo = lerFloat("\nInsira o custo:", 0 ,9999);

        tipoInspecao *NovoVetor=realloc(vetorInspecoes,(*quantInspecoes+1)*sizeof(tipoInspecao));
        if(NovoVetor==NULL){
            printf("\nNao foi Possivel Alocar Memoria");
            vetorInspecoes=backup;
        }
        else{
            vetorInspecoes=NovoVetor;
            vetorInspecoes[*quantInspecoes]=p;
            (*quantInspecoes)++;
            printf("\nInspecao Registado com sucesso. Codigo da Inspecao.: %d", p.codigo);
        }




    }else{
        printf("\nNao existem veiculos registados. Nao é possivel registar inspecao.");
    }
    return vetorInspecoes;

}

void listarDadosInspecoes(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantVeiculos, int *quantInspecoes){
    int i,j;
    int total;
    total=0;
    if(*quantVeiculos>0){
        printf("\n\n********** LISTA DE DADOS DE INSPECOES **********\n");
        for(i=0;i<*quantVeiculos;i++){
                printf("\n===== DADOS VEICULO %d =====\n",i+1);
                printf("\nMatricula: %s\t Tipo: %d.\nTotal de Kms: %d\n", vetorVeiculos[i].matricula, vetorVeiculos[i].tipo, vetorVeiculos[i].totalKms);
                printf("\n===== DADOS INSPECOES =====\n");
            for(j=0;j<*quantInspecoes;j++){
                if(strcmp(vetorInspecoes[j].matricula, vetorVeiculos[i].matricula)==0){
                    printf("\nCodigo: %d\tData: %d/%d/%d", vetorInspecoes[j].codigo, vetorInspecoes[j].Data.dia, vetorInspecoes[j].Data.mes, vetorInspecoes[j].Data.ano);
                    printf("\nResultado: %s\tCusto: %.2f", vetorInspecoes[j].resultado, vetorInspecoes[j].custo);
                    printf("\nAnotacoes: %s.\n", vetorInspecoes[j].anotacoes);
                    total++;

                    }else{
                        total=0;
                    }
            }
            printf("\nTotal de Inspecoes Efetuadas: %d.\n", total);
        }

    }else{
        printf("\nNao existem veiculos registados.");
    }
}

//INSPECOES NUMA DATA FICHEIRO TXT

void veiculosMenosFiaveis(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantVeiculos, int *quantInspecoes){
    int i,j, minAprov, inspecoesRegistadas, aprovacoesRegistadas;
    float percentagem[*quantVeiculos];
    char aprovado[TEXTO_CURTO]="APROVADO";

    minAprov=100;
    inspecoesRegistadas=0;
    aprovacoesRegistadas=0;

    if(*quantInspecoes>0){
        printf("\n\n********** VEICULOS MENOS FIAVEIS **********\n");
        for(i=0;i<*quantInspecoes;i++){
            percentagem[i]=0;
            for(j=0;j<*quantVeiculos;j++){
                if(strcmp(vetorInspecoes[j].matricula,vetorVeiculos[i].matricula)==0){
                    inspecoesRegistadas++;
                    if(strcmp(vetorInspecoes[j].resultado, aprovado)==0){
                        aprovacoesRegistadas++;
                    }
                }
            }

            percentagem[i]=((float)aprovacoesRegistadas/inspecoesRegistadas)*100;
            if(percentagem[i]<minAprov){
                minAprov=percentagem[i];
            }

        }

        for(i=0;i<*quantVeiculos;i++){
            if(percentagem[i]==minAprov){
                escreverVeiculo(vetorVeiculos[i]);
            }
        }

    }else{
        printf("\nImpossivel determninar os veiculos menos fiaveis. Nao existem inspecoes registadas.");
    }
}

//
