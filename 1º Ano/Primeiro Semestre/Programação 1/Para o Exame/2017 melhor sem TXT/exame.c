#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "exame.h"

tipoAgendamento *CriarNovoAgendamento(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    tipoAgendamento p;
    tipoAgendamento *backup=NULL;
    backup=vetorAgendamentos;
    p.custo=0;
    p.grauSat=0;

    int i,existe, cont;

    if(*quantClientes>0){
        printf("\n\n********** CRIAR AGENDAMENTO **********\n");
        p.codigo=*quantAgendamentos+1; //Cria codigo automatico para utilizador, vetor[0]=codigo 1... etc....
        p.numContribuinte=lerInteiro("\nInsira o seu numero de contribuinte:",CONTRIBUITE_MIN,CONTRIBUITE_MAX);
        for(i=0;i<*quantClientes;i++){
            if(p.numContribuinte==vetorClientes[i].numContribuinte){
                for(i=0;i<*quantClientes;i++){
                    if(p.numContribuinte==vetorClientes[i].numContribuinte){
                        do{
                            p.data=lerData();
                            p.hora=lerHorario();
                            existe=0;
                            for(i=0;i<*quantAgendamentos;i++){
                                if(p.data.dia==vetorAgendamentos[i].data.dia && p.data.mes==vetorAgendamentos[i].data.mes && p.data.ano==vetorAgendamentos[i].data.ano && p.hora.horas==vetorAgendamentos[i].hora.horas && p.hora.minutos==vetorAgendamentos[i].hora.minutos){
                                    printf("\nJa existe um agendamento nessa data a esse horario.");
                                    existe=1;
                                }
                            }
                        }while(existe);
                        lerString("\nInsira a descricao do seu problema:",p.desc,TEXTO_LONGO);

                        tipoAgendamento *NovoVetor=realloc(vetorAgendamentos,(*quantAgendamentos+1)*sizeof(tipoAgendamento));
                        if(NovoVetor==NULL){
                            printf("\nNao foi possivel alocar memoria.");
                            vetorAgendamentos=backup;
                        }else{
                            vetorAgendamentos=NovoVetor;
                            vetorAgendamentos[*quantAgendamentos]=p;
                            (*quantAgendamentos)++;
                            printf("\nAgendamento Registado com sucesso. Codigo do agendamento: %d", p.codigo);
                        }

                    }
                }
            }
        }
    }else{
        printf("\nNao e possivel criar agendamento. Nao existem clientes.");
    }
    return vetorAgendamentos;
}

void registarVisita(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos, int *totalVisitas){
    int i,verificaCodigo;
    if(*quantAgendamentos>0){
        printf("\n\n********** REGISTAR VISITA **********\n");
        verificaCodigo=lerInteiro("\nInsira o codigo do seu agendamento: ",1,*quantAgendamentos);
        for(i=0;i<*quantAgendamentos;i++){
            if(verificaCodigo==vetorAgendamentos[i].codigo){
                vetorAgendamentos[i].custo=lerFloat("\nInsira o custo da reparacao:", 0,999999);
                vetorAgendamentos[i].grauSat=lerInteiro("\nInsira o grau de satisfacao (1-Mau, 2-Bom, 3-Excelente):",1,3);
            }
        }


    }else{
        printf("\nNao foi possivel registar visita. Nao existem agendamentos.");
    }
    (*totalVisitas)++;

}

void consultarAgendamentos(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i;
    tipoAgendamento verificaData;
    if(*quantAgendamentos>0){
        printf("\n\n********** CONSULTAR AGENDAMENTOS POR DATA **********\n");

        printf("\nInsira a data do seu agendamento:");
        verificaData.data=lerData();
        printf("\nInsira o horario do seu agendamento:");
        verificaData.hora=lerHorario();

        for(i=0;i<*quantAgendamentos;i++){
            if(verificaData.data.dia==vetorAgendamentos[i].data.dia && verificaData.data.mes==vetorAgendamentos[i].data.mes && verificaData.data.ano==vetorAgendamentos[i].data.ano && verificaData.hora.horas==vetorAgendamentos[i].hora.horas && verificaData.hora.minutos==vetorAgendamentos[i].hora.minutos){
                printf("\n===== CLIENTE =====");
                printf("\nNome: %s\tTelefone: %d", vetorClientes[i].nome, vetorClientes[i].telefone);
                printf("\nMorada: %s\tContribuinte: %d", vetorClientes[i].morada, vetorClientes[i].numContribuinte);
                printf("\n===== AGENDAMENTO =====");
                printf("\nCodigo: %d.", vetorAgendamentos[i].codigo);
                //printf("\nData: %d/%d/%d/tHorario: %d:%dh", vetorAgendamentos[i].data.dia,vetorAgendamentos[i].data.mes,vetorAgendamentos[i].data.ano, vetorAgendamentos[i].hora.horas, vetorAgendamentos[i].hora.minutos);
                printf("\nDescricao: %s.", vetorAgendamentos[i].desc);
                printf("\nCusto: %.2f", vetorAgendamentos[i].custo);
                printf("\nGrau de Satisfacao: %d.\n", vetorAgendamentos[i].grauSat);
            }
        }

    }else{
        printf("\nNao existem clientes com agendamentos marcados.");
    }
}

void listarClientesAgendamentos(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos, int *totalVisitas){
    int i;
    int valor=0;
    if(*quantAgendamentos>0){
        printf("\n\n********** LISTA DE CLIENTES E RESPETIVOS AGENDAMENTOS **********\n");
        for(i=0;i<*quantAgendamentos;i++){
            if(vetorClientes[i].numContribuinte==vetorAgendamentos[i].numContribuinte){
                printf("\n===== CLIENTE =====");
                printf("\nNome: %s\tTelefone: %d", vetorClientes[i].nome, vetorClientes[i].telefone);
                printf("\nMorada: %s\tContribuinte: %d", vetorClientes[i].morada, vetorClientes[i].numContribuinte);
                printf("\n===== AGENDAMENTO =====");
                printf("\nCodigo: %d.", vetorAgendamentos[i].codigo);
                printf("\nData: %d/%d/%d\tHorario: %d:%dh", vetorAgendamentos[i].data.dia,vetorAgendamentos[i].data.mes,vetorAgendamentos[i].data.ano, vetorAgendamentos[i].hora.horas, vetorAgendamentos[i].hora.minutos);
                printf("\nDescricao: %s.", vetorAgendamentos[i].desc);
            if(vetorAgendamentos[i].grauSat>3){
                vetorAgendamentos[i].custo=valor;
                vetorAgendamentos[i].grauSat=valor;
            }

            if(vetorAgendamentos[i].grauSat>0){
                printf("\nCusto: %.2f", vetorAgendamentos[i].custo);
                printf("\nGrau de Satisfacao: %d.\n", vetorAgendamentos[i].grauSat);
                (*totalVisitas)++;
            }else{
                printf("\nVisita ainda nao foi efetuada.");
            }
            }
        }
    }else{
        printf("\nNao existem clientes registados.");
    }
}

void melhoresClientes(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i,j,maxAgendamentos;
    int contagem[MAX]={0};

    if(*quantAgendamentos>0){
        printf("\n\n********** LISTA DE MELHORES CLIENTES **********\n");
        for(i=0;i<*quantClientes;i++){
            for(j=0;j<*quantAgendamentos;j++){
                if(vetorAgendamentos[i].numContribuinte==vetorClientes[j].numContribuinte){
                    contagem[j]++;
                    if(contagem[i]>maxAgendamentos){
                        maxAgendamentos=contagem[j];
                    }
                }
            }
        }

        for(i=0;i<*quantClientes;i++){
            if(contagem[i]==maxAgendamentos && maxAgendamentos>0){
                printf("\nNumero de contribuinte: %d", vetorClientes[i].numContribuinte);
                printf("\nNome: %s", vetorClientes[i].nome);
                printf("\nMorada: %s", vetorClientes[i].morada);
                printf("\nTelefone: %d", vetorClientes[i].telefone);
                printf("\nQuantidade de Agendamentos: %d\n\n", maxAgendamentos);
            }
        }

    }else{
        printf("\nNao existem agendamentos.");
    }
}

void percentagensDeSatisfacao(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos){
    int i,total,a,b,c;
    float PA, PB, PC;
    total=0;
    a=0;
    b=0;
    c=0;

    if(*quantAgendamentos>0){
        printf("\n\n********** PERCENTAGEM DE GRAUS DE SATISFACAO **********\n");
        for(i=0;i<*quantAgendamentos;i++){
            if(vetorAgendamentos[i].grauSat=1){
                a++;
                total++;
            }
            if(vetorAgendamentos[i].grauSat=2){
                b++;
                total++;

            }
            if(vetorAgendamentos[i].grauSat=3){
                c++;
                total++;
            }
        }

        printf("\nTotal de Avaliacoes: %d.", total);
        PA=((float)a/total)*100;
        PB=((float)b/total)*100;
        PC=((float)c/total)*100;
        printf("\nPercentagens de Avaliacoes (Mau): %.2f", PA);
        printf("\nPercentagens de Avaliacoes (Bom): %.2f", PB);
        printf("\nPercentagens de Avaliacoes (Excelente): %.2f", PC);

    }else{
        printf("\nNao Existem Agendamentos");
    }
}

