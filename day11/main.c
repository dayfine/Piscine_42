#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "test_list_utils.c"
#include "./ex00/ft_list.h"
// #include "./ex00/ft_create_elem.c"
#include "./ex01/ft_list_push_back.c"


int main(void)
{
	t_list *list_test;

	printf("====== Basic Warmup Test ========\n");
	{
		list_test = create_dummy_list();
		print_list(list_test);

		char *expected1[5] = {"5", "4", "3", "2", 0};
		assert(test_list(list_test, expected1)==1);

		free_list(list_test);
	}

	printf("====== Append Test ========\n");
	{
		printf("\tnormal list\n");
		{
			list_test = create_dummy_list();

			char *expected1[6] = {"5", "4", "3", "2", "end", 0};
			ft_list_push_back(&list_test, "end");
			assert(test_list(list_test, expected1)==1);

			free_list(list_test);
		}

		printf("\tnull list\n");
		{
			list_test = NULL;

			char *expected1[2] = {"end", 0};
			ft_list_push_back(&list_test, "end");
			assert(test_list(list_test, expected1)==1);

			free_list(list_test);
		}
	}

  	return 0;
}
