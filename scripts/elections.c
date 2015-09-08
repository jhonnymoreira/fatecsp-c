#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
  int i, j, k, tmpVote;
  char *tmpName;

  /**
   * Define o voterChoice para poder encerrar o programa quando 0 for a
   * escolha.
   */
  int voterChoice = -1;

  /* Define os votos de todos os candidatos para a base da votação */
  int dilma = 0, chalita = 0, soninha = 0, alckmin = 0;

  /* Encerra o programa quando o voterChoice for equivalente a 0 */
  while ( voterChoice != 0 ) {
    /* Mesma função do "clrscr()", porém vindo da <stdlib.h> */
    system("cls");

    /* Exibe o número e o nome do candidato */
    printf("Party Candidates:\n\n");
    printf("13: Dilma\n");
    printf("15: Chalita\n");
    printf("43: Soninha\n");
    printf("45: Alckmin\n\n");

    /* Pede para o usuário fazer seu voto */
    printf("What is your vote?\n");
    scanf("%d", &voterChoice);

    /* Filtra o voterChoice para atribuir o voto ao candidato selecionado */
    switch ( voterChoice ) {
      case 13:
        dilma++;
        /* Alerta de voto registrado com sucesso */
        printf("Vote registered successfully!");
        getch();
        break;
      case 15:
        chalita++;
        /* Alerta de voto registrado com sucesso */
        printf("Vote registered successfully!");
        getch();
        break;
      case 43:
        soninha++;
        /* Alerta de voto registrado com sucesso */
        printf("Vote registered successfully!");
        getch();
        break;
      case 45:
        alckmin++;
        /* Alerta de voto registrado com sucesso */
        printf("Vote registered successfully!");
        getch();
        break;
      case 0:
        /* Define o caso para não pegar a mensagem default */
        printf("Finishing the elections.");
        getch();
        break;
      default:
        /* Alerta o usuário que o voto foi inválido e não registrado */
        printf("Invalid vote! The vote wasn't registered.");
        getch();
    }
  }

  /**
   * Define um array para aplicar o BubbleSort e tornar possível a exibição dos
   * resultados em ordem crescente, onde:
   *
   * 1 - São os votos dos candidatos
   * 2 - São os nomes dos candidatos
   *
   * Referência: http://c.learncodethehardway.org/book/ex10.html
   */
  /* 1 */
  int candidatesVotes[] = { dilma, chalita, soninha, alckmin };
  /* 2 */
  char *candidatesNames[] = { "Dilma", "Chalita", "Soninha", "Alckmin" };

  /**
   * Filtra os resultados e os coloca em ordem crescente através de BubbleSort
   */
  for ( i = 0; i < 4; i++ ) {
    for ( j = 0; j < 4 - i; j++ ) {
      if ( candidatesVotes[j] > candidatesVotes[j+1] ) {
        /* Guarda os valores iniciais */
        tmpVote = candidatesVotes[j];
        tmpName = candidatesNames[j];

        /* Coloca o número maior na posição do número menor */ 
        candidatesVotes[j] = candidatesVotes[j+1];
        /* Atualiza a referência em nomes */
        candidatesNames[j] = candidatesNames[j+1];

        /* Coloca o número menor na posição anterior do número maior */
        candidatesVotes[j+1] = tmpVote;
        /* Atualiza a referência em nomes */
        candidatesNames[j+1] = tmpName;

        /**
         *Caso haja números iguais, BubbleSort continua ordenando corretamente
         */
        j--;
      }
    }
  }

  /**
   * Exibe o resultado das eleições, no qual:
   *
   * 1 - Limpa a tela
   * 2 - Chamada
   * 3 - Nome dos candidatos e número de votos
   */
  /* 1 */
  system("cls");

  /* 2 */
  printf("Elections' Results:\n\n");
  /* 3 */
  for ( k = 0; k < 4; k++ ) {
    printf("%s: %d\n", candidatesNames[k], candidatesVotes[k]);
  }

  getch();
  return 0;
}
