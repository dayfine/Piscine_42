#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "test_list_utils.c"
#include "./ex00/ft_list.h"
// #include "./ex00/ft_create_elem.c"
#include "./ex01/ft_list_push_back.c"
#include "./ex02/ft_list_push_front.c"
#include "./ex03/ft_list_size.c"


int main(void)
{
	t_list *list_test;

	printf("====== 00 Basic Warmup Test ========\n");
	{
		list_test = create_dummy_list();
		print_list(list_test);

		char *expected[5] = {"5", "4", "3", "2", 0};
		assert(test_list(list_test, expected)==1);

		free_list(list_test);
	}

	printf("====== 01 Append Test ========\n");
	{
		printf("\tnormal list\n");
		{
			list_test = create_dummy_list();

			char *expected[6] = {"5", "4", "3", "2", "end", 0};
			ft_list_push_back(&list_test, "end");
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}

		printf("\tnull list\n");
		{
			list_test = NULL;

			char *expected[2] = {"end", 0};
			ft_list_push_back(&list_test, "end");
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}
	}

	printf("====== 02 Prepend Test ========\n");
	{
		printf("\tnormal list\n");
		{
			list_test = create_dummy_list();

			char *expected[6] = {"beg", "5", "4", "3", "2", 0};
			ft_list_push_front(&list_test, "beg");
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}

		printf("\tnull list\n");
		{
			list_test = NULL;

			char *expected[2] = {"beg", 0};
			ft_list_push_front(&list_test, "beg");
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}
	}

	printf("====== 02 Prepend Test ========\n");
	{
		printf("\tnormal list\n");
		{
			list_test = create_dummy_list();

			assert(ft_list_size(list_test)==4);
			ft_list_push_front(&list_test, "beg");
			assert(ft_list_size(list_test)==5);

			free_list(list_test);
		}

		printf("\tnull list\n");
		{
			list_test = NULL;
			assert(ft_list_size(list_test)==0);
			free_list(list_test);
		}
	}
  	return 0;
}
