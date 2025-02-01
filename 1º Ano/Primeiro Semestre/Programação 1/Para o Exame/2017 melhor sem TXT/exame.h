#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED


typedef struct{
    int codigo;
    int numContribuinte;
    tipoData data;
    tipoHorario hora;
    char desc[TEXTO_LONGO];
    float custo;
    int grauSat;
}tipoAgendamento;

tipoAgendamento *CriarNovoAgendamento(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void registarVisita(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos, int *totalVisitas);
void consultarAgendamentos(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void listarClientesAgendamentos(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos, int *totalVisitas);
void melhoresClientes(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void percentagensDeSatisfacao(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);


#endif // EXAME_H_INCLUDED
