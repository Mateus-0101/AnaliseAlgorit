#include <stdio.h>
#include <stdlib.h>

double busca_binaria()
{

}

int main()
{
    int impossivel = 1;

    while(impossivel != 0)
    {
        int qtd_placa;
        double metade = 0, altura, area = 0, soma = 0;
        double *vetor_alturas;

        scanf("%d %lf", &qtd_placa, &area);

        if(qtd_placa == 0 && area == 0)
        {
            return 0;
        }

        vetor_alturas = (double*)calloc(qtd_placa,sizeof(double));

        for(int i = 0; i < qtd_placa; i++)
        {
            scanf("%lf", &altura);
            vetor_alturas[i] = altura;
        }
            
        int repete = 1;
        while(repete != 0)
        {
            double maior = 0;
            for(int i = 0; i < qtd_placa; i++)
            {
                if(vetor_alturas[i] > maior)
                {
                    maior = vetor_alturas[i];
                }
            }

            //printf("maior = %f\n", maior);
            metade = maior/2;
            //printf("metade = %0.4f\n", metade);
            if(metade >= area)
            {
                for(int i = 0; i < qtd_placa; i++)
                {
                    vetor_alturas[i] = vetor_alturas[i] - metade;

                    //printf("%0.4f ", vetor_alturas[i]);
                }

                //soma das sobras(incluindi negativos) == altura ideal do corte
                for(int i = 0; i < qtd_placa; i++)
                {
                    soma += vetor_alturas[i];
                    printf("Soma: %f\n", soma);
                }
            }
            else
            {
                repete = 0;
            }
        }

        if(soma == 0)
        {
            printf(":D\n");
        }
        else if (soma < area)
        {
            printf("-.-\n");
        }
        else
        {
            printf("%0.4f\n", soma);
        }
    }
}