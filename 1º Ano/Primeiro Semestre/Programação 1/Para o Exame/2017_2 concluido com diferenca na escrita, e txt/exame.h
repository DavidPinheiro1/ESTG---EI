#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED

typedef struct{
    int codigo;
    int numContribuinte;
    tipoData Data;
    tipoHorario Hora;
    char descricao[TEXTO_LONGO];
    float custo;
    int grauSatisfacao;
}tipoAgendamento;

tipoAgendamento* AdicionarNovoAgendamento(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void registarVisita(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void consultarAgendamento(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void listarClientesAgendamentos(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);

void percentagemGrauSatisfacao(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void listarMelhorCliente(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void escreverFicheiroTexto(tipoAgendamento *vetorAgendamento, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);


#endif // EXAME_H_INCLUDED
