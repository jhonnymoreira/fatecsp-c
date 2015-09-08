#include <stdio.h>
#include <conio.h>

int main() {
  int day, month, year, dayMonthSum, birthSum, firstFloor, secondFloor,
      floorSum, baseRatio, yourType;
  
  /**
   * Pegando o input do usuário
   *
   * 1 - Dia
   * 2 - Mês
   * 3 - Ano
   *
   */
  printf("The day you were born: (From 1 to 31)\n");
  scanf("%d", &day); /* 1 */
  
  printf("The month you were born: (From 1 to 12)\n");
  scanf("%d", &month); /* 2 */
  
  printf("The year you were born: (From 1900 to 2015)\n");
  scanf("%d", &year); /* 3 */
  
  /* Transformar o dia e o mês em um número de 4 dígitos */
  dayMonthSum = (day * 100) + month;
  /* Soma dos 4 dígitos (dayMonthSum) com o ano */
  birthSum = dayMonthSum + year;
  
  /* Dois primeiros dígitos de birthSum */
  firstFloor = birthSum / 100;
  /* Dois últimos dígitos de birthSum */
  secondFloor = birthSum % 100;
  /* Soma dos dígitos de firstFloor e secondFloor */
  floorSum = firstFloor + secondFloor;
  
  /* Constante de divisão  */
  baseRatio = 5;
  
  /* Número que define o tipo do usuário */
  yourType = floorSum % baseRatio;
  
  /**
   * Tipos de usuário:
   *
   * 0: Tímido
   * 1: Sonhador
   * 2: Paquerador
   * 3: Atraente
   * 4: Irresistível
   *
   */
  if ( yourType == 1 ) { printf("\nYou are a dreamer person."); } /* 1 */
  else if ( yourType == 2 ) { printf("\nYou are a flirter person."); } /* 2 */
  else if ( yourType == 3 ) { printf("\nYou are a attractive person."); } /* 3 */
  else if ( yourType == 4 ) { printf("\nYou are a irresistible person."); } /* 4 */
  else { printf("\nYou are a shy person."); } /* 0 */
  
  getch();
  return 0;
}
