#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "test_list_utils.c"
#include "./ex00/ft_list.h"
// #include "./ex00/ft_create_elem.c"
#include "./ex01/ft_list_push_back.c"
#include "./ex02/ft_list_push_front.c"
#include "./ex03/ft_list_size.c"
#include "./ex04/ft_list_last.c"
// #include "./ex05/ft_list_push_params.c"
// #include "./ex06/ft_list_clear.c"
// #include "./ex07/ft_list_at.c"
// #include "./ex08/ft_list_reverse.c"
// #include "./ex09/ft_list_foreach.c"
// #include "./ex10/ft_list_foreach_if.c"
// #include "./ex11/ft_list_find.c"
// #include "./ex12/ft_list_remove_if.c"
// #include "./ex13/ft_list_merge.c"
// #include "./ex14/ft_list_sort.c"
// #include "./ex15/ft_list_reverse_fun.c"
// #include "./ex16/ft_sorted_list_insert.c"
// #include "./ex17/ft_sorted_list_merge.c"



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

	printf("====== 03 List Size ========\n");
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

	printf("====== 04 List Last ========\n");
	{
		printf("\tnormal list\n");
		{
			list_test = create_dummy_list();

			assert(ft_list_last(list_test)==4);

			ft_list_push_back(&list_test, "beg");
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
