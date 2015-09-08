#include <stdio.h>
#include <conio.h>

int main() {
  /* Preço do produto a ser digitado */
  float productPrice;
  /* Define o totalPrice igual a 0 para poder adicionar o productPrice */
  float totalPrice = 0;

  /* Chamada para digitar os produtos, no qual 0 encerra o programa */
  printf("Type all the products prices: (0 exits)\n");

  /* O loop irá parar quando a variável loop for diferente de 1 */
  int loop = 1;
  /* Loop para pegar os preços digitados pelo usuário */
  while( loop == 1 ) {
    /* Recebe o preço que o usuário digitou */
    scanf("\n%f", &productPrice);

    /**
     * Filtro para o preço digitado, no qual:
     *
     * 1 - Menor que 0: Exibe um erro ao usuário
     * 2 - Igual a 0: Exibe uma mensagem que está finalizando a compra,
     *     define a variável loop igual a 0 para interrompor o while
     * 3 - Em outros casos: Adiciona o preço digitado ao preço total
     */
    if ( productPrice < 0 ) {
      /* 1 */
      printf("\"%.2f\" Isn't a valid price! (Wasn't added)!\n", productPrice);
    } else if ( productPrice == 0 ) {
      /* 2 */
      printf("Finishing the order...");
      loop = 0;
    } else {
      /* 3 */
      totalPrice += productPrice;
    }
  }

  /**
   * Define os descontos em um array para que possa exibir o total de desconto
   * no final. Os descontos são definidos como:
   *
   * 1 - Desconto de 5% em compras abaixo de R$50,00
   * 2 - Desconto de 10% em compras de até R$100,00
   * 3 - Desconto de 15% em compras abaixo de R$200,00
   * 4 - Desconto de 20% em compras acima de R$200,00
   *
   * Estrutura: { limite, desconto }
   * Exemplo:
   * discount[0] => { 50, 5 }
   * discount[0][0] => 50 (Valor)
   * discount[0][1] => 5 (Desconto)
   *
   * Em cada caso, é mostrado na tela do usuário o valor total da compra e o
   * desconto adquirido.
   */
  float discounts[4][2] = {
          { 50, 5 },
          { 100, 10 },
          { 200, 15 },
          { 200, 20 }
        };

  if ( totalPrice < discounts[0][0] ) {
    totalPrice *= 1 - (discounts[0][1] / 100);
    /* 1 */
    printf("\n\nTotal price:\nR$%.2f (Discount of %.0f%%)",
           totalPrice, discounts[0][1]);
  } else if ( totalPrice >= discounts[0][0] &&
              totalPrice < discounts[1][0] ) {
    /* 2 */
    totalPrice *= 1 - (discounts[1][1] / 100);
    printf("\n\nTotal price:\nR$%.2f (Discount of %.0f%%)",
           totalPrice, discounts[1][1]);
  } else if ( totalPrice >= discounts[1][0] &&
              totalPrice < discounts[2][0] ) {
    /* 3 */
    totalPrice *= 1 - (discounts[2][1] / 100);
    printf("\n\nTotal price:\nR$%.2f (Discount of %.0f%%)",
           totalPrice, discounts[2][1]);
  } else {
    /* 4 */
    totalPrice *= 1 - (discounts[3][1] / 100);
    printf("\n\nTotal price:\nR$%.2f (Discount of %.0f%%)",
           totalPrice, discounts[3][1]);
  }

  getch();
  return 0;
}
