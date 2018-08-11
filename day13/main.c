#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "test_tree_utils.c"
#include "./ex00/ft_btree.h"
#include "./ex01/btree_apply_prefix.c"
#include "./ex02/btree_apply_infix.c"
#include "./ex03/btree_apply_suffix.c"
#include "./ex04/btree_insert_data.c"
#include "./ex05/btree_search_item.c"
#include "./ex06/btree_level_count.c"
#include "./ex07/btree_apply_by_level.c"


void	ft_putstr(void *str)
{
	printf("%s - ", str);
}

int 	ft_strcmp(void *s1, void *s2)
{
	return (strcmp(s1, s2));
}

void 	ft_print_by_level(void *item, int current_level, int is_first_elem)
{
	printf("lv: %d; is_first: %d; val: '%s'\n", current_level, is_first_elem, item);
}

int main(void)
{
	t_btree *tree_test;
	t_btree *result;

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

	printf("====== Insertion ========\n");
	{
		printf("====== Insertion Ex 1 ========\n");
		{
			tree_test = NULL;

			t_btree **root_ptr = &tree_test;
			btree_insert_data(root_ptr, "3", ft_strcmp);
			btree_insert_data(root_ptr, "2", ft_strcmp);
			btree_insert_data(root_ptr, "4", ft_strcmp);
			btree_apply_infix(*root_ptr, ft_putstr);
			printf("\n");
			free_tree(*root_ptr);
		}

		printf("====== Insertion Ex 2 ========\n");
		{
			tree_test = create_dummy_tree();

			t_btree **root_ptr = &tree_test;
			btree_insert_data(root_ptr, "0", ft_strcmp);
			btree_insert_data(root_ptr, "2", ft_strcmp);
			btree_insert_data(root_ptr, "5", ft_strcmp);
			btree_insert_data(root_ptr, "7", ft_strcmp);
			btree_apply_infix(*root_ptr, ft_putstr);
			printf("\n");
			free_tree(*root_ptr);
		}
	}

	printf("====== Search ========\n");
	{
		printf("====== Search Ex 1 ========\n");
		{
			printf("Testing...\n");
			tree_test = NULL;

			result = btree_search_item(tree_test, "3", ft_strcmp);
			assert(result == NULL);

			tree_test = create_dummy_tree();
			result = btree_search_item(tree_test, "7", ft_strcmp);
			assert(result == NULL);
			free_tree(tree_test);
			printf("Tested\n");
		}

		printf("====== Search Ex 2 ========\n");
		{
			printf("Testing...\n");
			tree_test = create_dummy_tree();
			result = btree_search_item(tree_test, "3", ft_strcmp);
			assert(ft_strcmp(result->item, "3")==0);
			result = btree_search_item(tree_test, "1", ft_strcmp);
			assert(ft_strcmp(result->item, "1")==0);
			result = btree_search_item(tree_test, "0", ft_strcmp);
			assert(ft_strcmp(result->item, "0")==0);
			free_tree(tree_test);
			printf("Tested\n");
		}
	}

	printf("====== Longest ========\n");
	{
		printf("====== Longest Ex 1 ========\n");
		{
			printf("Testing...\n");
			tree_test = NULL;
			assert(btree_level_count(tree_test) == 0);
			tree_test = btree_create_node("1");
			assert(btree_level_count(tree_test) == 1);
			printf("Tested\n");
		}

		printf("====== Longest Ex 2 ========\n");
		{
			printf("Testing...\n");
			tree_test = create_dummy_tree();
			assert(btree_level_count(tree_test) == 3);
			btree_insert_data(&tree_test, "7", ft_strcmp);
			assert(btree_level_count(tree_test) == 4);
			free_tree(tree_test);
			printf("Tested\n");
		}
	}

	printf("====== Level Traversal ========\n");
	{
		printf("Testing...\n");
		tree_test = create_dummy_tree();
		btree_apply_by_level(tree_test, ft_print_by_level);
		printf("Tested\n");
	}
  	return 0;
}
