/******************************************************************************/
/*                                                                            */
/*                                                       :::      ::::::::    */
/*     ft_print_comb.c                                  :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*     By: dfan                                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*     Created: 2018/07/25 by dfan.                    #+#    #+#             */
/*                                                    ###   ########.us       */
/*                                                                            */
/******************************************************************************/


int ft_putchar(char c);


void ft_print_comb_result(char result[]) {
  ft_putchar(result[0]);
  ft_putchar(result[1]);
  ft_putchar(result[2]);
  ft_putchar(',');
  ft_putchar(' ');
}


void ft_print_comb_rec(int digit, char partial[]) {
  if (digit == 4) {

  }
}


void ft_print_comb(void) {
  int i = 1;
  int j = 1;
  int k = 1;

  while (i <= 9) {
    while (j <= 9) {
      if (i == j) continue;

      while (k <= 9) {
        if (i == k) continue;
        if (j == k) continue;


      }
    }
  }
}


int main() {
  ft_print_comb();
  return 0;
}
