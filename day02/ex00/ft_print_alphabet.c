/******************************************************************************/
/*                                                                            */
/*                                                       :::      ::::::::    */
/*     ft_print_alphabet.c                              :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*     By: dfan                                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*     Created: 2018/07/25 by dfan.                    #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


int ft_putchar(char c);


void ft_print_alphabet(void) {
	char ch;
	ch = 'a';

	while (ch <= 'z') {
		ft_putchar(ch);
		ch++;
	}

	ft_putchar('\n');
}


int main() {
	ft_print_alphabet();
	return 0;
}
