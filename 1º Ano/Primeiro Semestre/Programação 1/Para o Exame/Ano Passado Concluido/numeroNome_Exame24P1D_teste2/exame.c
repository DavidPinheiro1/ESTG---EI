#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "veiculo.h"
#include "exame.h"

//PARTE 1 - EXAME

void listarVeiculosPesados(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos){
    int i;
    float percentagem;
    int pesados=0;
    if(quantVeiculos>0){
        printf("\n\n*********** LISTAGEM dos VEICULOS ***********\n\n");
        for(i=0;i<quantVeiculos;i++){
            if(vetorVeiculos[i].tipo==2){
                pesados++;
                escreverVeiculo(vetorVeiculos[i]);
            }
        }
    }
    else{
        printf("\nVeiculos Nao Encontrados.");
    }

    percentagem=((float)pesados/quantVeiculos)*100;
    printf("\nPercentagem de veiculos pesados: %.2f%%", percentagem);

}

void listarVeiculosPorMarca(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos){
    int i;
    char procurada[TAM_MATRICULA];
    int quantMediaKMs=0;

    if(quantVeiculos>0){
        printf("\n\n*********** LISTAGEM dos VEICULOS por MARCA ***********\n\n");

        lerString("\nInsira a Marca que Procura:", procurada, TAM_MATRICULA);
        converteMaiuscula(procurada);
        for(i=0;i<quantVeiculos;i++){
            if(strcmp(vetorVeiculos[i].marca, procurada)==0 && vetorVeiculos[i].anoRegisto > 2020){
                quantMediaKMs+=vetorVeiculos[i].totalKms;
                printf("\nMarca: %s    |    Modelo: %s    |    Ano: %d", vetorVeiculos[i].marca, vetorVeiculos[i].modelo, vetorVeiculos[i].anoRegisto);
            }
        }
    }

    else{
        printf("\nVeiculos Nao Inseridos..");
    }

    printf("\nQuantidade Media de KMs: %d.", quantMediaKMs);

}

void atualizarDistanciaPercorrida(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos){
    int i;
    int nova;
    int distperc;
    int agora, total;
    total=0;

    if(quantVeiculos>0){
        printf("\n\n*********** ATUALIZAR DISTANCIA PERCORRIDA ***********\n\n");

        for(i=0;i<quantVeiculos;i++){
            printf("\nVeiculo n%d: ",i+1);
            escreverVeiculo(vetorVeiculos[i]);
            distperc=vetorVeiculos[i].totalKms;
            vetorVeiculos[i].totalKms=lerInteiro("\nInsira os KMs Atualizados do Veiculo: ",0,MAX_TOTAL_KMS);
            nova=vetorVeiculos[i].totalKms;
            agora=nova-distperc;
            total+=agora;
            printf("Distancia Percorrida: %d\n", agora);
        }

        printf("\nDistancia Total Percorrida: %dKms", total);

    }

    else{
        printf("\nVeiculos Nao Inseridos..");
    }

}

//PARTE 2 - EXAME

tipoInspecao* registarInspecaoNova(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantInspecoes, int quantVeiculos){
 int i,novoCodigo,posicao,existente;
 tipoInspecao p;
 tipoInspecao *backup = NULL;
 backup=vetorInspecoes;

 if(quantVeiculos>0){

    //para o codigo
    do{
    novoCodigo=lerInteiro("\nInsira o codigo da Inspecao:",0,9999);
    existente=0;
    for(i=0;i<*quantInspecoes;i++){
        if(novoCodigo==vetorInspecoes[i].codigo){
            printf("\nEsse Codigo ja esta Registado. Tente Novamente.");
            existente=1;
        }
    }
    }while(existente);

    //para o resto da informacao da inspecao
    lerString("\nInsira a Matricula do Veiculo:",p.matricula,TAM_MATRICULA);
    converteMaiuscula(p.matricula);
    posicao=procurarVeiculo(vetorVeiculos,quantVeiculos,p.matricula);
    if(posicao==-1){
        printf("\nEssa Matricula Nao Existe.");
    }
    else{
        printf("\nInsira a Data da Inspecao:");
        p.dia=lerInteiro("\nInsira o dia: (dd)",0,31);
        p.mes=lerInteiro("\nInsira o mes: (mm)",0,12);
        p.ano=lerInteiro("\nInsira o ano: (aaaa)",2025,2030);
        p.totalKms=vetorVeiculos[posicao].totalKms;
        lerString("\nIndique o Resultado da Inspecao (Aprovado/Reprovado):",p.resultado,TEXTO_CURTO);
        converteMaiuscula(p.resultado);
        lerString("\nIndique anotacoes sobre a inspecao:",p.anotacoes,TEXTO_LONGO);
        converteMaiuscula(p.anotacoes);
        p.custo=lerFloat("\nInsira o Custo da Inspecao:", 0,9999);
        p.codigo=novoCodigo;



        tipoInspecao *NovoVetor=realloc(vetorInspecoes,(*quantInspecoes+1)*sizeof(tipoInspecao));
        if(NovoVetor==NULL){
            printf("\nNao Foi Possivel Alocar Memoria.");
            vetorInspecoes=backup;
        }else{
            vetorInspecoes=NovoVetor;
            vetorInspecoes[*quantInspecoes]=p;
            (*quantInspecoes)++;
            printf("\nInspecao Registada com Sucesso.");
        }
    }
 }
    return vetorInspecoes;
}

void listarInspecoesVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantInspecoes, int quantVeiculos){
    int i,j,inspecao;
    int tiponovo;
    char t[TEXTO_CURTO]="Desconhecido";

    inspecao=0;

    if(quantVeiculos>0){
        printf("\n\n********** LISTA DE INSPECOES **********");
        for(i=0;i<quantVeiculos;i++){
            printf("\nMatricula: %s", vetorVeiculos[i].matricula);
            tiponovo=vetorVeiculos[i].tipo;
            switch(tiponovo){
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
            printf("\nTipo: %s", t);
            printf("\nTotal de Kms: %d", vetorVeiculos[i].totalKms);
            printf("\n\n===== SOBRE A INSPECAO =====\n");
            inspecao=0;
            for(j=0;j<quantInspecoes;j++){
                if(strcmp(vetorInspecoes[j].matricula,vetorVeiculos[i].matricula)==0){
                    printf("\nCodigo: %d",vetorInspecoes[j].codigo);
                    printf("\nData: %d/%d/%d", vetorInspecoes[j].dia, vetorInspecoes[j].mes, vetorInspecoes[j].ano);
                    printf("\nResultado: %s", vetorInspecoes[j].resultado);
                    printf("\nAnotacoes: %s", vetorInspecoes[j].anotacoes);
                    printf("\nCusto: %.2f\n", vetorInspecoes[j].custo);
                    inspecao++;
                }
            }
            printf("Total de Inspecoes Registadas para este veiculos: %d\n\n", inspecao);
            printf("\n\n=========================\n\n");
        }
    }
    else{
        printf("\nNao existem veiculos.\n");
    }
}

void mostrarVeiculosMenosFiaveis(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantInspecoes, int quantVeiculos){
    int i,j, minAprov, inspecoesRegistadas, aprovacoesRegistadas;
    float percentagem[quantVeiculos];
    char aprovado[TEXTO_CURTO]="APROVADO";

    minAprov=100;
    inspecoesRegistadas=0;
    aprovacoesRegistadas=0;

    printf("\n\n********** VEICULOS MENOS VIAVEIS **********\n\n");
    if(quantVeiculos>0){
        for(i=0;i<quantVeiculos;i++){
            percentagem[i]=0;
            for(j=0;j<quantInspecoes;j++){
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
        for(i=0;i<quantVeiculos;i++){
            if(percentagem[i]==minAprov){
                escreverVeiculo(vetorVeiculos[i]);
            }
        }

    }
    else{
        printf("/nNao Existem Veiculos Inseridos.");
    }

}

void escreverFicheiroTextoInspecoes(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantInspecoes, int quantVeiculos){
    FILE *ficheiro;
    int i, j;
    int dia,mes,ano;

    ficheiro = fopen("InspecoesData.txt", "w");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        if(quantVeiculos > 0){
        dia = lerInteiro("\nDia: ", 0,31);
        mes = lerInteiro("\nMes: ", 0,12);
        ano = lerInteiro("\nAno: ", 2025,2030);

        for(i=0; i<quantInspecoes; i++){
                fprintf(ficheiro, "\n Marca: %s", vetorVeiculos[i].marca);
                fprintf(ficheiro, "\n Tipo de veiculo: %d", vetorVeiculos[i].tipo);

                    if(ano == vetorInspecoes[i].ano && mes == vetorInspecoes[i].mes && dia == vetorInspecoes[i].dia){
                        fprintf(ficheiro, "\n Codigo: %d", vetorInspecoes[i].codigo);
                        fprintf(ficheiro, "\n Matricula: %s", vetorInspecoes[i].matricula);
                        fprintf(ficheiro, "\n Total de kms: %d", vetorInspecoes[i].totalKms);
                        fprintf(ficheiro, "\n Data: %02d/%02d/%04d", vetorInspecoes[i].dia, vetorInspecoes[i].mes, vetorInspecoes[i].ano);
                        fprintf(ficheiro, "\n Resultado da inspecao: %s", vetorInspecoes[i].resultado);
                        fprintf(ficheiro, "\n Descricao: %s", vetorInspecoes[i].anotacoes);
                        fprintf(ficheiro, "\n Custo: %.2f\n\n", vetorInspecoes[i].custo);
                }
            }
        }
        else{
            printf("Nao existem veiculos");
        }

        fclose(ficheiro);

}
}

//escrever ficheiro de texto por data de inspecao
