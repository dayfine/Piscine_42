#include <stdio.h>
#include <assert.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

void ft_put_line(char line[], int length)
{
	int idx;

	idx = 0;
	while (idx < length)
	{
		ft_putchar(line[idx]);
		idx++;
	}
	ft_putchar('\n');
}

int get_max_width(int size)
{
	int i;
	int w;

	i = 0;
	w = 0;

	while (i < size)
	{
		if (i == 0) {
			w += 7;
		} else {
			w += (i + 5) * 2 + (i - 1) / 2 * 2;
		}
		i++;
	}
	return w;
}

int get_num_lvs(int section)
{
	return (section + 3);
}

int get_sec_level_width(int sec, int level)
{
	return get_max_width(sec + 1) - (get_num_lvs(sec) - level - 1) * 2;
}

void build_normal_level(int level, int section, char line[], int max_width)
{
	int side_fill;
	int i;

	i = 0;
	side_fill = (max_width - get_sec_level_width(section, level)) / 2;
	while (i < side_fill)
	{
		line[i++] = ' ';
	}
	line[i++] = '/';
	while (i < max_width - side_fill - 1)
	{
		line[i++] = '*';
	}
	line[i++] = '\\';
	while (i < max_width)
	{
		line[i++] = ' ';
	}
	ft_put_line(line, max_width);
}

void build_section_with_door(int sec, int num_levels, int max_width)
{
	int door_dim;

	door_dim = sec % 2 == 0 ? sec + 1: sec;

}

void sastantua(int size)
{
	int max_width;
	int section;
	int levels;
	int level;
	char line[get_max_width(size)];

	section = 0;
	max_width = get_max_width(size);
	printf("max_width: %d\n", max_width);
	while (section < size)
	{
		levels = get_num_lvs(section);
		level = 0;
		while (level < levels)
		{
			build_normal_level(level++, section, line, max_width);
		}
		section++;
	}
	// build_section_with_door(section, get_num_lvs(section), max_width);
}

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
	printf("Checking get_level_width\n");
	assert(get_sec_level_width(0, 0)==3);
	assert(get_sec_level_width(0, 1)==5);
	assert(get_sec_level_width(0, 2)==7);
	assert(get_sec_level_width(1, 0)==13);
	assert(get_sec_level_width(1, 1)==15);
	assert(get_sec_level_width(1, 2)==17);
	assert(get_sec_level_width(1, 3)==19);
	assert(get_sec_level_width(6, 8)==121);
	assert(get_sec_level_width(7, 9)==151);
	printf("Finished checking get_max_width\n");
	printf("=====================\n");
	sastantua(0);
	printf("=====================\n");
	sastantua(1);
	printf("=====================\n");
	sastantua(2);
	// printf("=====================\n");
	// sastantua(3);
	// printf("=====================\n");
	// sastantua(4);
	// printf("=====================\n");
	// sastantua(5);
	return 0;
}
