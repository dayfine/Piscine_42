/******************************************************************************/
/*                                                                            */
/*                                                       :::      ::::::::    */
/*     ft_is_negative.c                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*     By: dfan                                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*     Created: 2018/07/25 by dfan.                    #+#    #+#             */
/*                                                    ###   ########.us       */
/*                                                                            */
/******************************************************************************/


int ft_putchar(char c);


void ft_is_negative(int n) {
  char N = 'N';
  char P = 'P';
  ft_putchar(n < 0 ? N : P);
  ft_putchar('\n');
}


int main() {
  ft_is_negative(5);
  ft_is_negative(0);
  ft_is_negative(-5);
  return 0;
}
