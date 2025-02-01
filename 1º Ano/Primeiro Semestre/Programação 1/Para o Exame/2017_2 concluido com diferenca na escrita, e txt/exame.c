#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "exame.h"

tipoAgendamento* AdicionarNovoAgendamento(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){

    tipoAgendamento p;
    tipoAgendamento *backup=NULL;
    backup=vetorAgendamento;

    int i,j,existe;

    //dados para o agendamento:codigo unico e auto, numero de cont, data e hora n podem ser iguais, descricao.

    if(*quantClientes>0){
        printf("\n\n********** ADICIONAR AGENDAMENTO **********\n");

        p.codigo=*quantAgendamentos+1;

        p.numContribuinte=lerInteiro("\nInsira o seu numero de contribuinte:", CONTRIBUITE_MIN, CONTRIBUITE_MAX);
        for(i=0;i<*quantClientes;i++){
            if(p.numContribuinte==vetorClientes[i].numContribuinte){
                do{
                p.custo=0;
                p.grauSatisfacao=0;
                p.Data=lerData();
                p.Hora=lerHorario();
                existe=0;
                for(i=0;i<*quantAgendamentos;i++){
                    if((p.Data.dia==vetorAgendamento[i].Data.dia) && (p.Data.mes==vetorAgendamento[i].Data.mes) && (p.Data.ano==vetorAgendamento[i].Data.ano) && (p.Hora.horas==vetorAgendamento[i].Hora.horas) && (p.Hora.minutos==vetorAgendamento[i].Hora.minutos)){
                        printf("\nJa existe um agendamento nessa data a essa hora.");
                        existe=1;
                    }
                }
                }while(existe);

        lerString("\nInsira a descricao do problema do eletrodomestico:", p.descricao, TEXTO_LONGO);
        //p.custo=lerFloat("\nInsira o Custo da Reparacao:",0,9999);

        //p.grauSatisfacao=lerInteiro("\nInsira o seu grau de Satisfacao (1 - Fraco, 2 - Bom, 3 - Excelente)",FRACO,EXCELENTE);


        tipoAgendamento *NovoVetor=realloc(vetorAgendamento,(*quantAgendamentos+1)*sizeof(tipoAgendamento));
        if(NovoVetor==NULL){
            printf("\nNao foi Possivel Alocar Memoria");
            vetorAgendamento=backup;
        }
        else{
            vetorAgendamento=NovoVetor;
            vetorAgendamento[*quantAgendamentos]=p;
            (*quantAgendamentos)++;
            printf("\nAgendamento Registado com sucesso. Codigo da marcacao: %d", p.codigo);
        }
            }
        }



    }
    return vetorAgendamento;

}

void registarVisita(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i,codigo,existe, procura;
    codigo=0;
    if(*quantAgendamentos>0){
        printf("\n\n********** REGISTAR VISITA **********\n");

        codigo=*quantAgendamentos;
        procura=lerInteiro("\nInsira o codigo da agenda:",1, codigo);
        existe=0;
        for(i=0;i<*quantAgendamentos;i++){
            if(procura==vetorAgendamento[i].codigo){
                vetorAgendamento[i].custo=lerFloat("\nInsira o custo da reparacao:",0,999999);
                vetorAgendamento[i].grauSatisfacao=lerInteiro("\nInsira o grau de satisfacao (1-Mau, 2-Bom, 3-Excelente):",1,3);
            }
        }

    }else{
        printf("\nNao Existem Agendamentos Para Marcar Visitas.");
    }
}

void consultarAgendamento(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    //listar todos os agendamentos - datas - nomes - codigos - n contri - morada -n telefone
    int i;
    int dia,mes,ano,existe;

    if(*quantAgendamentos>0){
            printf("\n\n********** LISTA DE AGENDAMENTOS **********\n");
            do{
            printf("\nInsira a data que deseja consultar:");
            dia=lerInteiro("\nDia:",1,31);
            mes=lerInteiro("\nMes:",1,12);
            ano=lerInteiro("\nAno:",ANO_MIN,ANO_MAX);
            existe=0;
            for(i=0;i<*quantAgendamentos;i++){
                if(dia==vetorAgendamento[i].Data.dia && mes==vetorAgendamento[i].Data.mes && ano==vetorAgendamento[i].Data.ano){
                    printf("\nNome: %s      Morada: %s", vetorClientes[i].nome, vetorClientes[i].morada);
                    printf("\nNumero Contribuinte: %d       Telefone: %d", vetorClientes[i].numContribuinte, vetorClientes[i].telefone);
                    printf("\nData: %d/%d/%d        Horario: %d:%dh", vetorAgendamento[i].Data.dia, vetorAgendamento[i].Data.mes, vetorAgendamento[i].Data.ano, vetorAgendamento[i].Hora.horas, vetorAgendamento[i].Hora.minutos);
                    printf("\nDescricao: %s.", vetorAgendamento[i].descricao);
                    printf("\nGrau de satisfacao: %d", vetorAgendamento[i].grauSatisfacao);
                    printf("\nCusto: %.2f", vetorAgendamento[i].custo);
                    printf("\nCodigo do agendamento: %d\n", vetorAgendamento[i].codigo);
                    existe=1;
                }
            }
            }while(existe!=1);
    }else{
        printf("\nNao Existem Agendamentos.");
    }

}

void listarClientesAgendamentos(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i;
    if(*quantAgendamentos>0){
        printf("\n********** LISTA DE CLIENTES E RESPETIVOS AGENDAMENTOS **********");
        for(i=0;i<*quantAgendamentos;i++){
            printf("\nNome: %s      Morada: %s", vetorClientes[i].nome, vetorClientes[i].morada);
            printf("\nNumero Contribuinte: %d       Telefone: %d", vetorClientes[i].numContribuinte, vetorClientes[i].telefone);
            printf("\nData: %d/%d/%d        Horario: %d:%dh", vetorAgendamento[i].Data.dia, vetorAgendamento[i].Data.mes, vetorAgendamento[i].Data.ano, vetorAgendamento[i].Hora.horas, vetorAgendamento[i].Hora.minutos);
            printf("\nDescricao: %s.", vetorAgendamento[i].descricao);
            printf("\nGrau de satisfacao: %d", vetorAgendamento[i].grauSatisfacao);
            printf("\nCusto: %.2f", vetorAgendamento[i].custo);
            printf("\nCodigo do agendamento: %d\n", vetorAgendamento[i].codigo);
        }

    }else{
        printf("\nNao Existem Clientes com Agendamentos.");
    }


}

void listarMelhorCliente(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
   int i,j, maxAgendamentos;
    int contagens[MAX]={0};
    maxAgendamentos=0;


    if(*quantAgendamentos>0){
        printf("\n\n********** MELHORES CLIENTES **********\n");


        for(i=0;i<*quantAgendamentos;i++){
            for(j=0;j<*quantClientes;j++){
                if(vetorAgendamento[i].numContribuinte==vetorClientes[j].numContribuinte){
                    contagens[j]++;
                    if(contagens[j]>maxAgendamentos){
                        maxAgendamentos=contagens[j];
                    }
                }
            }
        }

        for(i=0;i<*quantClientes;i++){
            if(contagens[i]==maxAgendamentos && maxAgendamentos>0){
                printf("\nNumero de contribuinte: %d", vetorClientes[i].numContribuinte);
                printf("\nNome: %s", vetorClientes[i].nome);
                printf("\nMorada: %s", vetorClientes[i].morada);
                printf("\nTelefone: %d", vetorClientes[i].telefone);
                printf("\nQuantidade de Agendamentos: %d\n\n", maxAgendamentos);
            }
        }
    }
    else{
        printf("\nNao Existem Agendamentos.");
    }

}

void percentagemGrauSatisfacao(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i,m,b,e;
    int total;
    float percentagemM, percentagemB, percentagemE;
    total=0;
    percentagemM=0;
    percentagemB=0;
    percentagemE=0;
    m=0;
    b=0;
    e=0;

    if(*quantAgendamentos>0){
        printf("\n\n********** PERCENTAGEM DE GRAUS DE SATISFACAO **********\n");
        for(i=0;i<*quantAgendamentos;i++){
            if(vetorAgendamento[i].grauSatisfacao>0){
                if(vetorAgendamento[i].grauSatisfacao==1){
                    m++;
                    total++;
                }
                if(vetorAgendamento[i].grauSatisfacao==2){
                    b++;
                    total++;
                }
                if(vetorAgendamento[i].grauSatisfacao==3){
                    e++;
                    total++;
                }
            }
        }

        percentagemM=((float)m/total)*100;
        percentagemB=((float)b/total)*100;
        percentagemE=((float)e/total)*100;

        printf("\nTotal de Avaliacoes %d", total);
        printf("\nMa Satisfacao: %.2f%%", percentagemM);
        printf("\nBoa Satisfacao: %.2f%%", percentagemB);
        printf("\nExcelente Satisfacao: %.2f%%", percentagemE);

    }else{
        printf("\nNao Existem Agendamentos");
    }
}

void escreverFicheiroTexto(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){

    int i,j,tipo;
    char t[TEXTO_BREVE];

    FILE *fp = fopen("dados.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
    }
    else{
        if (*quantAgendamentos == 0) {
            printf("Nao Ha Agendamentos Registados.\n");
        }
        else{
            for (i=0;i<*quantClientes;i++){
                fprintf(fp, "Nome: %s       Morada: %s\n", vetorClientes[i].nome, vetorClientes[i].morada);
                fprintf(fp, "Telefone: %d       Contribuinte: %d\n", vetorClientes[i].telefone, vetorClientes[i].numContribuinte);
                if(vetorClientes[i].numContribuinte!=vetorAgendamento[i].numContribuinte){
                  fprintf(fp, "Este Cliente Nao Tem Agendamentos\n");
                }
                else{
                    fprintf(fp, "Código: %d\n", vetorAgendamento[i].codigo);
                    fprintf(fp, "Descricao: %s\n", vetorAgendamento[i].descricao);
                    fprintf(fp, "Data: %d/%d/%d\n", vetorAgendamento[i].Data.dia, vetorAgendamento[i].Data.mes, vetorAgendamento[i].Data.ano);
                    fprintf(fp, "Grau de Satisfacao: %d\n", vetorAgendamento[i].grauSatisfacao);
                    fprintf(fp, "Custo: %.2f\n", vetorAgendamento[i].custo);
                }
                fprintf(fp, "-------------------------------\n");
            }
        }


        //
        }
            fclose(fp);
    }



//void
