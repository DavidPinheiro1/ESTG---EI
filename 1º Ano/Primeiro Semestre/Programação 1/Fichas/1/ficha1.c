#include <stdio.h>
#include <math.h>

int main()
{
    /* 1 */

    int a;
    float b;
    char c[] = "Tabulacao Char.";

    a = 1;
    b = 2.3;

    printf("Hello World! \n\n");
    printf("Exemplo de uma tabulacao: \n");
    printf("%d \n",a);
    printf("%f \n", b);
    printf("%s \n\n", c);

    float d;
    printf("Insira um valor: ");
    scanf("%f",&d);
    printf("\n");
    printf("%.2f \n\n",d);

    /* 2 */

    char e[] = "%";
    printf("__________________________________________\n");
    printf("|Componentes de Avaliacao                 |\n");
    printf("|                                         |\n");
    printf("|TestesEscritos          Projeto          |\n");
    printf("|     50%s                  50%s            |\n",e,e);
    printf("|                                         |\n");
    printf("|Aulas TP \+ Aulas PL                      |\n");
    printf("|_________________________________________|\n");

    float f;
    float g;
    printf("Insira o Valor do teste escrito: ");
    scanf("%f",&f);
    printf("Insira o Valor do projeto: ");
    scanf("%f",&g);

    printf("__________________________________________\n");
    printf("|Componentes de Avaliacao                 |\n");
    printf("|                                         |\n");
    printf("|TestesEscritos          Projeto          |\n");
    printf("|     %.f%s                  %.f%s            |\n",f,e,g,e);
    printf("|                                         |\n");
    printf("|Aulas TP \+ Aulas PL                      |\n");
    printf("|_________________________________________|\n");
    printf("\n");

    /* 3 */

    int h;
    printf("Insira um valor inteiro:");
    scanf("%d",&h);
    printf("Dobro do valor inteiro: %d",2*h);
    printf("\n\n");

    float i;
    const float PI = 3.1415;
    printf("Vamos Calcular o Perimetro e a Area de uma Circuferencia:\n");
    printf("Insira o Raio da circunferencia: ");
    scanf("%f",&i);
    double x = i, y = 2;
    double elevado = pow(x, y);
    printf("\n");
    printf("Perimetro: \n%.3f  \n\nArea: \n%.3f", 2*PI*i, PI*elevado);
    printf("\n");
    printf("\n");
    printf("Perimetro: \n\+%.3f  \n\nArea: \n\+%.3f", 2*PI*i, PI*elevado);
    printf("\n");
    printf("\n");
    printf("Perimetro: \n%.1f  \n\nArea: \n%.1f", 2*PI*i, PI*elevado);
    printf("\n");
    printf("\n");
    printf("Perimetro: \n%7.2f  \n\nArea: \n%7.2f", 2*PI*i, PI*elevado);
    printf("\n");
    printf("\n");

    /* 4 */

    int j, k;
    printf("Insira o primeiro numero inteiro: \n");
    scanf("%d",&j);
    printf("Insira o segundo numero inteiro: ");
    scanf("%d",&k);
    printf("\n");
    printf("Soma: %d \n", j+k);
    printf("Subtracao: %d \n", j-k);
    printf("Multiplicacao: %d \n", j*k);
    printf("Divisao: %d \n", j/k);
    printf("Resto Divisao Inteira: %d \n", j%k);
    printf("\n");

    /* 5 */

    float l, m;
    printf("Insira o primeiro numero real: \n");
    scanf("%f",&l);
    printf("Insira o segundo numero real: ");
    scanf("%f",&m);
    printf("\n");
    printf("Soma: %f \n", l+m);
    printf("Subtracao: %f \n", l-m);
    printf("Multiplicacao: %f \n", l*m);
    printf("Divisao: %f \n", l/m);
    //printf("Resto Divisao Inteira: %f \n", l%m);
    //Desta maneira não é possivel saber o resto de valores Float.
    printf("\n");

    /* 6 */
    printf("\n");
    float n,o,p,q,r,s,total;
    n=600;
    o=100;

    printf("Salario base de %.2f\n",n);
    printf("Acrescimo de %.2f por cada carro que vende\n",o);
    printf("Acrescimo de 5%s pela empresa\n", e);
    printf("\n");
    printf("Indique o nr. de carros vendidos: \n");
    scanf("%f",&p);
    printf("Indique o montante faturado: \n");
    scanf("%f", &q);
    printf("\n");
    //por carro vendido
    r=o*p;
    //% de vendas
    s=q*0.05;
    total=n+r+s;
    printf("Total Faturado: %.2f",total);
printf("\n");
printf("\n");
}

