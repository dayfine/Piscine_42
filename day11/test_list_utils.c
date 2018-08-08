#include <stdio.h>
#include <stdlib.h>
#include "./ex00/ft_list.h"
#include "./ex00/ft_create_elem.c"

void print_list(t_list *node)
{
	t_list *curr;

	curr = node;
	while (curr)
	{
		printf("%s -> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}

int test_list(t_list *node, char **words)
{
	t_list *curr;

	curr = node;
	while (curr)
	{
		if (curr->data != *words++)
			return (0);
		curr = curr->next;
	}
	return !*words;
}

t_list * create_dummy_list()
{
	t_list *n1;
  	t_list *n2;
  	t_list *n3;
  	t_list *n4;

  	n1 = ft_create_elem("5");
  	n2 = ft_create_elem("4");
	n3 = ft_create_elem("3");
  	n4 = ft_create_elem("2");

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	return (n1);
}

void	free_list(t_list *head)
{
	if (head == NULL)
		return ;
	free_list(head->next);
	free(head);
}
