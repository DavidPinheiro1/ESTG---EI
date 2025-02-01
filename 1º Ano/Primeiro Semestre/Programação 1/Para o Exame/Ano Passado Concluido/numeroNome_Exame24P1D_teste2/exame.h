#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED

void listarVeiculosPesados(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void listarVeiculosPorMarca(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void atualizarDistanciaPercorrida(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

typedef struct{
    int codigo;
    char matricula[TAM_MATRICULA];
    int totalKms;
    int dia;
    int mes;
    int ano;
    char resultado[TEXTO_CURTO];
    char anotacoes[TEXTO_LONGO];
    float custo;
}tipoInspecao;

tipoInspecao* registarInspecaoNova(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantInspecoes, int quantVeiculos);
void listarInspecoesVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantInspecoes, int quantVeiculos);
void mostrarVeiculosMenosFiaveis(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantInspecoes, int quantVeiculos);
void escreverFicheiroTextoInspecoes(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantInspecoes, int quantVeiculos);

#endif // EXAME_H_INCLUDED
