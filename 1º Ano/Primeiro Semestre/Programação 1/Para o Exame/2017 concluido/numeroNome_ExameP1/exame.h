#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED

#define FRACO 1
#define BOM 2
#define EXCELENTE 3

typedef struct{
    int codigo; //unico e automatico
    int numcontr;
    tipoData data;
    tipoHorario hora;
    char descricao[TEXTO_LONGO];
    float custo;
    int grauSatisfacao;
}tipoAgendamento;

tipoAgendamento* AdicionarNovoAgendamento(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void listarClienteMarcacoes(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void registarVisita(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void consultarAgendamentos(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void listarMelhoresClientes(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);
void ListarPercentagens(tipoAgendamento *vetorAgendamentos, tipoCliente vetorClientes[MAX], int *quantClientes, int *quantAgendamentos);

#endif // EXAME_H_INCLUDED
