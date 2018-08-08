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
#include "./ex05/ft_list_push_params.c"
#include "./ex06/ft_list_clear.c"
#include "./ex07/ft_list_at.c"
#include "./ex08/ft_list_reverse.c"
#include "./ex09/ft_list_foreach.c"
#include "./ex10/ft_list_foreach_if.c"
#include "./ex11/ft_list_find.c"
#include "./ex12/ft_list_remove_if.c"
#include "./ex13/ft_list_merge.c"
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

			assert(strcmp(ft_list_last(list_test)->data, "2")==0);
			ft_list_push_back(&list_test, "end");
			assert(strcmp(ft_list_last(list_test)->data, "end")==0);

			free_list(list_test);
		}

		printf("\tnull list\n");
		{
			list_test = NULL;
			assert(ft_list_last(list_test)==NULL);
			free_list(list_test);
		}
	}

	printf("====== 05 To List ========\n");
	{
		printf("\tnormal list\n");
		{
			char *args[4] = {"5", "4", "3", "2"};
			char *expected[5] = {"2", "3", "4", "5", 0};
			assert(test_list(ft_list_push_params(4, args), expected)==1);
		}

		printf("\tnull list\n");
		{
			char *args[0] = {};
			assert(ft_list_push_params(0, args)==NULL);
		}
	}

	printf("====== 06 Free List ========\n");
	{
		printf("\tnormal list\n");
		{
			list_test = create_dummy_list();

			t_list **ptr = &list_test;
			ft_list_clear(ptr);
			assert(*ptr==NULL);
		}

		printf("\tnull list\n");
		{
			list_test = NULL;

			t_list **ptr = &list_test;
			ft_list_clear(ptr);
			assert(*ptr==NULL);
		}
	}

	printf("====== 07 Get List Nth ========\n");
	{
		printf("\tnormal get\n");
		{
			list_test = create_dummy_list();

			assert(strcmp(ft_list_at(list_test, 0)->data, "5")==0);
			assert(strcmp(ft_list_at(list_test, 2)->data, "3")==0);
			free_list(list_test);
		}

		printf("\tinvalid get\n");
		{
			list_test = create_dummy_list();

			assert(ft_list_at(list_test, -1)==NULL);
			assert(ft_list_at(list_test, 5)==NULL);
			free_list(list_test);

			assert(ft_list_at(NULL, 0)==NULL);
		}
	}

	printf("====== 08 Reverse List ========\n");
	{
		printf("\tnormal list\n");
		{
			list_test = create_dummy_list();

			char *expected[6] = {"2", "3", "4", "5", 0};
			ft_list_reverse(&list_test);
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}

		printf("\tnull list\n");
		{
			list_test = NULL;

			ft_list_reverse(&list_test);
			assert(list_test==NULL);

			free_list(list_test);
		}
	}

	printf("====== 09 List For Each ========\n");
	{
		printf("\t>> No Tests - Passed <<\n");
	}

	printf("====== 10 List For Each If ========\n");
	{
		printf("\t>> No Tests - Passed <<\n");
	}

	printf("====== 11 Find in List ========\n");
	{
		printf("\tnormal result\n");
		{
			list_test = create_dummy_list();

			char *expected[6] = {"3", "2", 0};
			assert(test_list(ft_list_find(list_test, "3", strcmp), expected)==1);
			assert(ft_list_find(list_test, "x", strcmp)==NULL);

			free_list(list_test);
		}

		printf("\tnull result\n");
		{
			list_test = NULL;

			assert(ft_list_find(list_test, "3", strcmp)==NULL);
			assert(ft_list_find(list_test, "x", strcmp)==NULL);

			free_list(list_test);
		}
	}

	printf("====== 12 Remove From List ========\n");
	{
		printf("\tnormal result1\n");
		{
			list_test = create_dummy_list();

			char *expected[4] = {"5", "4", "2", 0};
			ft_list_remove_if(&list_test, "3", strcmp);
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}

		printf("\tnormal result2\n");
		{
			list_test = ft_create_elem("x");

			t_list **ptr = &list_test;
			ft_list_remove_if(ptr, "x", strcmp);
			assert(*ptr==NULL);
			free_list(list_test);
		}


		printf("\tNothing to remove\n");
		{
			list_test = create_dummy_list();

			char *expected[5] = {"5", "4", "3", "2", 0};
			ft_list_remove_if(&list_test, "x", strcmp);
			assert(test_list(list_test, expected)==1);
			free_list(list_test);
		}
	}

	printf("====== 13 Merge List ========\n");
	{
		printf("\tnormal merges\n");
		{
			list_test = create_dummy_list();
			t_list *list_test2 = ft_create_elem("x");

			char *expected[6] = {"5", "4", "3", "2", "x", 0};
			ft_list_merge(&list_test, list_test2);
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}

		printf("\tmerge null 1\n");
		{
			list_test = NULL;
			t_list *list_test2 = create_dummy_list();

			char *expected[5] = {"5", "4", "3", "2", 0};
			ft_list_merge(&list_test, list_test2);
			assert(test_list(list_test, expected)==1);

			free_list(list_test);
		}

		printf("\tmerge null 2\n");
		{
			list_test = NULL;
			t_list *list_test2 = create_dummy_list();

			char *expected[5] = {"5", "4", "3", "2", 0};
			ft_list_merge(&list_test2, list_test);
			assert(test_list(list_test2, expected)==1);

			free_list(list_test2);
		}
	}

	printf("====== 14 Sort List ========\n");
	{
		printf("\t>> No Tests - Passed <<\n");
	}

	printf("====== 15 Reverse List Run ========\n");
	{
		printf("\t>> No Tests - Passed <<\n");
	}

	printf("====== 16 Insert Sorted List ========\n");
	{
		printf("\t>> No Tests - Passed <<\n");
	}

	printf("====== 17 Merge Sorted Lists ========\n");
	{
		printf("\t>> No Tests - Passed <<\n");
	}
  	return 0;
}
