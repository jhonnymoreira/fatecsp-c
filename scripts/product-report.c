#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  /**
   * Define os votos de "sim" (yes) e "não" (no) para 0 como base para votação.
   */
  float yes = 0, no = 0;
  int i = 1, j; /* Define as variáveis para começar o loop */

  char vote;

  /**
   * Gera um seed para que a funcão "rand()" não fique retornando os mesmos
   * valores em cada execução do programa, além de só pode ser chamada uma vez
   * na aplicação.
   *
   * Referências:
   * http://stackoverflow.com/a/822368
   * http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c#comment631807_822368
   * 
   */
  srand(time(NULL));

  while ( i == 1 ) {
    system("cls");

    printf("Did you like the product? (Vote using 's' or 'n')\n");
    /**
     * 1 - Obtém o voto do usuário
     * 2 - Transforma o voto do usuário em uma letra minúscula
     */
    scanf("%c", &vote); /* 1 */
    vote = tolower(vote); /* 2 */

    /* Filtra o voto do usuário */
    switch ( vote ) {
      case 's':
        yes++; /* Adiciona 1 ao número de "Sim" (yes) */
        /* Exibe uma mensagem de sucesso para o usuário. */
        printf("We are glad that you like.");
        getch();

        i = 0; /* Encerra o loop */
        break;
      case 'n':
        no++; /* Adiciona 1 ao número de "Não" (no) */
        /* Exibe uma mensagem de sucesso para o usuário. */
        printf("We are sorry to disappoint you.");
        getch();

        i = 0; /* Encerra o loop */
        break;
      default:
        /* Exibe uma mensagem de erro para o usuário */
        printf("Invalid option! Try again.");
        getch();
    }
  }

  /**
   * Obtém 49 resultados de 50, entre 0 e 1. O quinquagésimo resultado é a
   * entrada do usuário. No qual:
   *
   * 1 - Gera 49 resultados
   * 2 - Filtra e adiciona o resultado específico a sua variável ("yes" ou
   *    "no"), no qual 0 é equivalente a "n" e 1 é equivalente a "s".
   */
  /* 1 */
  for ( j = 0; j < 49; j++ ) {
    /* 2 */
    if ( (rand() % 2) == 1 ) {
      yes++;
    } else {
      no++;
    }
  }

  /* Define as porcentagens */
  float yesPercentage = (yes * 100) / (yes + no);
  float noPercentage = (no * 100) / (yes + no);

  /* Limpa a tela */
  system("cls");

  /* Exibe os resultados */
  printf("In a group of 50 people interviewed:\n\n");
  /* Porcentagem dos que gostaram */
  printf("%.2f%% likes our product.\n", yesPercentage);
  /* Porcentagem dos que não gostaram */
  printf("%.2f%% didn't like our product.", noPercentage);

  getch();
  return 0;
}
