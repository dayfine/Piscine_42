#include <stdio.h>
#include <assert.h>

#include "./ft_putchar.c"
#include "./ex00/sastantua.c"


int main(void) {
	printf("Checking get_max_width\n");
	assert(get_max_width(0)==0);
	assert(get_max_width(1)==7);
	assert(get_max_width(2)==19);
	assert(get_max_width(3)==33);
	assert(get_max_width(4)==51);
	assert(get_max_width(5)==71);
	assert(get_max_width(6)==95);
	assert(get_max_width(7)==121);
	assert(get_max_width(8)==151);
	printf("Finished checking get_max_width\n");
	printf("=====================\n");
	sastantua(0);
	printf("=====================\n");
	sastantua(1);
	printf("=====================\n");
	sastantua(2);
	printf("=====================\n");
	sastantua(3);
	printf("=====================\n");
	sastantua(4);
	printf("=====================\n");
	sastantua(5);
	printf("=====================\n");
	sastantua(6);
	printf("=====================\n");
	sastantua(7);
	return 0;
}
