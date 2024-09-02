#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

void alocarVetor(double ** vetor, int n) {

  * vetor = (double *)realloc(*vetor, n * sizeof(double));

  if (vetor == NULL) {
    printf("Erro ao alocar memoria");
  }
}

void lerVetor(double *vetor, int n) {

  int i = n - 1;

  printf("Digite o %do valor: ", n);
  scanf("%lf", &vetor[i]);
}

double calcularMedia(double *vetor, int n) {

  double soma = 0;

  for (int i = 0; i < n; i++) {

    soma += vetor[i];
  }

  return soma / n;
}

void mostrarMedia(double media) { printf("A media eh: %lf\n\n", media); }

int main(int argc, char **argv) {

  double *vetor = NULL;
  int opcao;
  int n = 0;
  double media;

  do {

    printf("\n\n");

    printf("Calculadora de media\n\n");

    printf("1 - Digitar um numero\n");
    printf("2 - Calcular media\n");
    printf("3 - Excluir valores\n");
    printf("0 - Sair\n\n");
    printf("Digite uma opcao: ");
    scanf("%d", &opcao);
    printf("\n\n");

    switch (opcao) {

    case 1:

      n++;

      alocarVetor(&vetor, n);
      lerVetor(vetor, n);

      break;

    case 2:

      if (n == 0) {
        
        printf("Nao ha numeros para calcular a media\n");
        
      } else {
        
        media = calcularMedia(vetor, n);
        mostrarMedia(media);
      }
      
      break;

    case 3:

      if (n == 0) {

        printf("Nao ha numeros para serem excluidos\n");

      } else {

        n = 0;
        printf("Valores excluidos\n");
        
      }

    break;

    case 0:

      printf("Saindo...\n");
      free(vetor);

      break;

    default:

      printf("Opcao invalida!\n");
    }

  } while (opcao != 0);

  return SUCESSO;
}
