#ifndef FUNCOESGENERICAS_H_INCLUDED
#define FUNCOESGENERICAS_H_INCLUDED

#define MIN_ANO 2025
#define MAX_ANO 2030

typedef struct{
    int dia, mes, ano;
} tipoData;

typedef struct{
    int hora, minuto;
} tipoHorario;

tipoData lerData(char msg[]);
void escreverData(tipoData data);

tipoHorario lerHorario (void);
void escreverHorario(tipoHorario horario);

float lerFloat (char msg[], float limMin, float limMax);
int lerInteiro (char msg[], int limMin, int limMax);
void lerString (char msg[], char texto[], int tamMax);

void limparBuffer(void);
void converteMaiuscula(char texto[]);

#endif // FUNCOESGENERICAS_H_INCLUDED
