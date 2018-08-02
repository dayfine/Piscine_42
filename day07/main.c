#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



int main(void) {
	char test_str1[] = "hey stack!";
	int test_arr1[] = {3, 4, 5, 6, 7};
	int *rng1;
	int *rng2;

	printf("ft_strdup\n");
	assert(strcmp(test_str1, strdup("hey stack!"))==0);
	assert(strcmp(test_str1, ft_strdup("hey stack!"))==0);
	printf("ft_range\n");
	assert(memcmp(test_arr1, ft_range(3, 8), sizeof(test_arr1))==0);
	assert(ft_range(3, 3)==0);
	printf("ft_ultimate_range\n");
	ft_ultimate_range(&rng1, 3, 8);
	assert(memcmp(test_arr1, rng1, sizeof(test_arr1))==0);
	ft_ultimate_range(&rng2, 3, 3);
	assert(rng2==NULL);
	printf("ft_concat_params\n");
	char *args[] = {
		"hey", "stack!"
	};
	char concated[] = "hey\nstack!";
	assert(strcmp(ft_concat_params(2, args), concated)==0);
	printf("==========\n");
}
