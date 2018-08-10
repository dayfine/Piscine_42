#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "test_tree_utils.c"
#include "./ex00/ft_btree.h"
#include "./ex01/btree_apply_prefix.c"
#include "./ex02/btree_apply_infix.c"
#include "./ex03/btree_apply_suffix.c"


void	ft_putstr(void *str)
{
	printf("%s - ", str);
}


int main(void)
{
	t_btree *tree_test;

	printf("====== Preorder print ========\n");
	{
		tree_test = create_dummy_tree();
		btree_apply_prefix(tree_test, ft_putstr);
		printf("\n");
		free_tree(tree_test);
	}

	printf("====== Inorder print ========\n");
	{
		tree_test = create_dummy_tree();
		btree_apply_infix(tree_test, ft_putstr);
		printf("\n");
		free_tree(tree_test);
	}

	printf("====== Postorder print ========\n");
	{
		tree_test = create_dummy_tree();
		btree_apply_suffix(tree_test, ft_putstr);
		printf("\n");
		free_tree(tree_test);
	}
  	return 0;
}
