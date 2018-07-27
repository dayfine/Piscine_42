/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:09:37 by dfan              #+#    #+#             */
/*   Updated: 2018/07/25 17:11:41 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void printUtil(int arr[], int target_length)
{
    int i;
    i = 0;

    while (i < target_length)
    {
        printf("%d", arr[i]);
        i += 1;
    }
    printf(", \n");
}

void combinationUtil(int partial[], int start, int end, int index, int target_length)
{
    int i;

    i = start;
    if (index == target_length) printUtil(partial, target_length);

    while (i <= end && target_length - i <= end - i + 1)
    {
        partial[index] = i;
        combinationUtil(partial, i + 1, end, index + 1, target_length);
        i += 1;
    }
}

void printCombination(int target_length)
{
    int partial[target_length];
    combinationUtil(partial, 0, 9, 0, target_length);
}

int main()
{
    printCombination(1);
    printCombination(2);
}

