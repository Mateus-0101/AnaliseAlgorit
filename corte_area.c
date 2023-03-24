#include <stdio.h>
#include <stdlib.h>

double busca_binaria(double vetor_alt[], int qtd_placas, double area, double menor, double maior, double metade)
{
    double corte = 0;

    while(maior >= menor)
    {
        double soma = 0;
        metade = (menor + maior)/2;

        for(int i = 0; i < qtd_placas; i++)
        {
            corte = vetor_alt[i] - metade;

            if(corte < 0)
            {
                corte = 0;
            }

            soma += corte;
        }

        if(soma == area)
        {
            return metade;
        }
        else
        {
            if(soma > area)
            {
                menor = metade;
            }
            else
            {
                maior = metade;
            }
        }
    }

    return metade;
}

int main()
{
    static int loop = 1;

    while(loop != 0)
    {
        int qtd_placa;
        double corte, altura, area = 0, soma = 0;
        double *vetor_alturas;

        scanf("%d %lf", &qtd_placa, &area);

        if(qtd_placa == 0 && area == 0)
        {
            return 0;
        }

        vetor_alturas = (double*)calloc(qtd_placa,sizeof(double));
        double maior = 0;

        for(int i = 0; i < qtd_placa; i++)
        {
            scanf("%lf", &altura);
            vetor_alturas[i] = altura;

            if(vetor_alturas[i] > maior)
            {
                maior = vetor_alturas[i];
            }

            soma += vetor_alturas[i];
        }

        if(soma == area)
        {
            printf(":D\n");
        }
        else if(soma < area)
        {
            printf("-.-\n");
        }
        else
        {
            corte = busca_binaria(vetor_alturas,qtd_placa,area,0,maior,corte);
            printf("%0.4lf\n",corte);
        }
    }
}