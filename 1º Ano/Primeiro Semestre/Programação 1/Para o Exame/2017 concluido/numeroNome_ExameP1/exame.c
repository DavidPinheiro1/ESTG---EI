#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "exame.h"



tipoAgendamento* AdicionarNovoAgendamento(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    tipoAgendamento p;
    tipoAgendamento *backup=NULL;
    backup=vetorAgendamentos;

    int i, existente, codigoUnico, contEx;
    codigoUnico=0;
    contEx=0;

    if(*quantClientes>0){
        printf("\n\n********** ADICIONAR NOVO AGENDAMENTO **********\n");
        codigoUnico=*quantAgendamentos+1;

        p.codigo=codigoUnico;

        p.numcontr=lerInteiro("\nInsira o seu Numero de Contribuinte: ", CONTRIBUITE_MIN, CONTRIBUITE_MAX);
        for(i=0;i<*quantClientes;i++){
            if(p.numcontr==vetorClientes[i].numContribuinte){
                do{
                p.data=lerData();
                p.hora=lerHorario();
                existente=0;
                for(i=0;i<*quantAgendamentos;i++){
                    if((p.data.dia==vetorAgendamentos[i].data.dia) && (p.data.mes==vetorAgendamentos[i].data.mes) && (p.data.ano==vetorAgendamentos[i].data.ano) && (p.hora.horas==vetorAgendamentos[i].hora.horas) && (p.hora.minutos==vetorAgendamentos[i].hora.minutos)){
                        printf("\nJa existe um agendamento nessa data a essa hora.");
                        existente=1;
                    }
                }
                }while(existente);

        lerString("\nInsira a descricao do problema do eletrodomestico:", p.descricao, TEXTO_LONGO);
        //p.custo=lerFloat("\nInsira o Custo da Reparacao:",0,9999);

        //p.grauSatisfacao=lerInteiro("\nInsira o seu grau de Satisfacao (1 - Fraco, 2 - Bom, 3 - Excelente)",FRACO,EXCELENTE);


        tipoAgendamento *NovoVetor=realloc(vetorAgendamentos,(*quantAgendamentos+1)*sizeof(tipoAgendamento));
        if(NovoVetor==NULL){
            printf("\nNao foi Possivel Alocar Memoria");
            vetorAgendamentos=backup;
        }
        else{
            vetorAgendamentos=NovoVetor;
            vetorAgendamentos[*quantAgendamentos]=p;
            (*quantAgendamentos)++;
            printf("\nAgendamento Registado com sucesso. Codigo da marcacao: %d", p.codigo);
        }
            }
        }



    }
    return vetorAgendamentos;
}

void listarClienteMarcacoes(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i, clientes=0;

    if(*quantClientes>0){
        clientes=*quantClientes;
        printf("\n\n********** LISTAR CLIENTES e MARCACOES **********\n");
        for(i=0;i<clientes;i++){
            if(vetorClientes[i].numContribuinte==vetorAgendamentos[i].numcontr){
                printf("\nNumero de contribuinte: %d        Nome: %s", vetorClientes[i].numContribuinte, vetorClientes[i].nome);
                printf("\nTelefone: %d      Morada: %s",vetorClientes[i].telefone, vetorClientes[i].morada);
                printf("\nCodigo da marcacao: %d", vetorAgendamentos[i].codigo);
                printf("\nDescricao: %s", vetorAgendamentos[i].descricao);
                printf("\nData: %d/%d/%d -- %d:%dh\n\n", vetorAgendamentos[i].data.dia, vetorAgendamentos[i].data.mes, vetorAgendamentos[i].data.ano, vetorAgendamentos[i].hora.horas, vetorAgendamentos[i].hora.minutos);
                //printf("\nCusto da Reparacao: %.2f", vetorAgendamentos[i].custo);
                //printf("\nGrau de Satisfacao: %d\n\n", vetorAgendamentos[i].grauSatisfacao);
                }
                else{
                    printf("\nNumero de contribuinte: %d        Nome: %s", vetorClientes[i].numContribuinte, vetorClientes[i].nome);
                    printf("\nTelefone: %d      Morada: %s",vetorClientes[i].telefone, vetorClientes[i].morada);
                    printf("\nEste Usuario Nao Tem Marcacoes\n\n");
                }
            }
        }
    else{
        printf("\nNao Existem Clientes com Marcacoes.");
    }
}

void registarVisita(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i, codigo, teste;
    teste=0;
    codigo=0;
    if(*quantAgendamentos>0){
        printf("\n\n********** REGISTAR VISITA **********\n");
        for(i=0;i<*quantAgendamentos;i++){
            if(vetorAgendamentos[i].codigo>-1){
                teste++;
            }
        }
        codigo=lerInteiro("\nInsira o codigo da marcacao:", 1, teste);
        vetorAgendamentos[codigo-1].custo=lerFloat("\nInsira o custo da reparacao/visita:",0,9999);
        vetorAgendamentos[codigo-1].grauSatisfacao=lerInteiro("\nInsira o grau de satisfacao (1-Fraco ,2-Bom, 3-Excelente)", 1,3);
        printf("\nVisita Registada Com Sucesso.");
    }
    else{
        printf("\nNao Existem Agendamentos");
    }
}

void consultarAgendamentos(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i,dia,mes,ano,total;
    total=0;
    if(*quantAgendamentos>0){
        printf("\n\n********** CONSULTAR AGENDAMENTOS POR DATA **********\n");
        printf("\nIndique a data que deseja consultar os agendamentos:");
        dia=lerInteiro("\nDia: ",0,31);
        mes=lerInteiro("\nMes: ",0,12);
        ano=lerInteiro("\nAno: ",ANO_MIN,ANO_MAX);
        for(i=0;i<*quantAgendamentos;i++){
            if((vetorAgendamentos[i].data.ano==ano)&&(vetorAgendamentos[i].data.mes==mes)&&(vetorAgendamentos[i].data.dia==dia)){
                printf("\nData: %d/%d/%d", vetorAgendamentos[i].data.dia,vetorAgendamentos[i].data.mes,vetorAgendamentos[i].data.ano);
                printf("\nDescricao: %s", vetorAgendamentos[i].descricao);
                printf("\nCodigo: %d",vetorAgendamentos[i].codigo);
                printf("\nN Contribuinte: %d", vetorAgendamentos[i].numcontr);
                printf("\n");
                total++;
            }
        }

    }
    else{
        printf("\nNao Existem Agendamentos.");
    }
    printf("\nTotal de Agendamentos nesta data: %d", total);

}

void listarMelhoresClientes(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i,j, maxAgendamentos;
    int contagens[MAX]={0};
    maxAgendamentos=0;


    if(*quantAgendamentos>0){
        printf("\n\n********** MELHORES CLIENTES **********\n");


        for(i=0;i<*quantAgendamentos;i++){
            for(j=0;j<*quantClientes;j++){
                if(vetorAgendamentos[i].numcontr==vetorClientes[j].numContribuinte){
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

void ListarPercentagens(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i, total;
    int a,b,c;
    float percentagemA,percentagemB,percentagemC;
    a=0;
    b=0;
    c=0;
    total=0;


    if(*quantAgendamentos>0){
        printf("\n\n********** LISTA DE SATISFACAO **********\n");

        for(i=0;i<*quantAgendamentos;i++){
            if(vetorAgendamentos[i].grauSatisfacao==1){
                a++;
                total++;
            }
            else if(vetorAgendamentos[i].grauSatisfacao==2){
                b++;
                total++;
            }
            else if(vetorAgendamentos[i].grauSatisfacao==3){
                c++;
                total++;
            }
        }


        percentagemA=((float)a/total)*100;
        percentagemB=((float)b/total)*100;
        percentagemC=((float)c/total)*100;
        printf("\nMau - %.2f%%", percentagemA);
        printf("\nBom - %.2f%%", percentagemB);
        printf("\nExcelente - %.2f%%", percentagemC);

    }
    else{
        printf("\nNao Existem Agendamentos.");
    }

    }



