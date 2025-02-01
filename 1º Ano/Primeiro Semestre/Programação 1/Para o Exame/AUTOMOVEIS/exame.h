#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED

typedef struct{
    int codigo;
    char matricula[TAM_MATRICULA];
    int totalKms;
    tipoData Data;
    char resultado[TEXTO_CURTO];
    char anotacoes[TEXTO_LONGO];
    float custo;
}tipoInspecao;

void listarVeiculosPesados(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void listarVeiculosMarca(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void atualizarDistanciaPercorrida(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
tipoInspecao *CriarNovaInspecao(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantVeiculos, int *quantInspecoes);
void listarDadosInspecoes(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantVeiculos, int *quantInspecoes);

void veiculosMenosFiaveis(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int *quantVeiculos, int *quantInspecoes);

#endif // EXAME_H_INCLUDED
