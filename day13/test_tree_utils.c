#include <stdio.h>
#include <stdlib.h>
#include "./ex00/ft_btree.h"
#include "./ex00/btree_create_node.c"

t_btree *create_dummy_tree()
{
	t_btree *n0;
	t_btree *n1;
  	t_btree *n2;
  	t_btree *n3;
  	t_btree *n4;

  	n0 = btree_create_node("0");
  	n1 = btree_create_node("1");
  	n2 = btree_create_node("2");
	n3 = btree_create_node("3");
  	n4 = btree_create_node("4");

	n1->left = n0;
	n1->right = n3;
	n3->left = n2;
	n3->right = n4;

	return (n1);
}

void	free_tree(t_btree *root)
{
	if (root == NULL)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}
