/******************************************************************************/
/*                                                                            */
/*                                                       :::      ::::::::    */
/*     ft_print_numbers.c                               :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*     By: dfan                                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*     Created: 2018/07/25 by dfan.                    #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


int ft_putchar(char c);


void ft_print_numbers(void) {
  char ch;
  ch = '0';

  while (ch <= '9') {
    ft_putchar(ch);
    ch++;
  }

  ft_putchar('\n');
}


int main() {
  ft_print_reverse_alphabet();
  return 0;
}
