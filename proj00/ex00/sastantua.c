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

void put_door_on_line(int lv, int sec, char line[], int max_width)
{
	int door_dim;
	int side_fill;
	int i;
	int is_knob;

	door_dim = sec % 2 == 0 ? sec + 1: sec;
	if (lv > get_num_lvs(sec) - 1 - door_dim)
	{
		side_fill = (max_width - door_dim) / 2;
		i = side_fill;
		while (i < side_fill + door_dim)
		{
			is_knob = (sec >= 4
						&& lv == get_num_lvs(sec) - 1 - door_dim / 2
						&& i == side_fill + door_dim - 2);

			line[i++] = is_knob ? '$' : '|';
		}
	}
}

void build_normal_level(int lv, int sec, int max_width, int build_door)
{
	int side_fill;
	int i;
	char line[max_width];

	i = 0;
	side_fill = (max_width - get_sec_level_width(sec, lv)) / 2;
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
	if (build_door)
	{
		put_door_on_line(lv, sec, line, max_width);
	}
	ft_put_line(line, max_width);
}

void sastantua(int size)
{
	int max_width;
	int sec;
	int levels;
	int lv;

	sec = 0;
	max_width = get_max_width(size);
	while (sec < size)
	{
		levels = get_num_lvs(sec);
		lv = 0;
		while (lv < levels)
		{
			build_normal_level(lv++, sec, max_width, sec == size - 1);
		}
		sec++;
	}
}
