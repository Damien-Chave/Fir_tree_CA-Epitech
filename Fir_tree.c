// Include libraries that could be in a header <file.h> with prototypes.
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Printf restriction: show on screen character(s).
void my_putchar(char c)
{
  write(1, &c, 1);
}
void my_putstr(char *str)
{
  int i = 0;
  while(str[i] != '\0')
    {
      my_putchar(str[i++]);
    }
}


int	get_spines_base(int input_size)
{
  int coef = 6;
  int	max_spines = 1;
  int	i;

  i = 0;
  while (i < input_size)
    {
      if (i != 0 && (i % 2 == 0))
        coef = coef +2;

      max_spines = max_spines + coef;
      i++;
    }
  return (max_spines);
}


void	my_print_line(int spines_base, int nb_star, char c)
{
  int	nb_space;
  int i;

  nb_space = ((spines_base - 1) / 2) - (nb_star / 2);

  i = 0;
  while (i < nb_space)
    {
      my_putchar(' ');
      i++;
    }

  i = 0;
  while (i < nb_star)
    {
      my_putchar(c);
      i++;
    }
  my_putchar('\n');
}


void	print_leaves(int lines_stage_desc, int spines_base)
{
  int	nb_star;
  int	to_show;
  int	count;
  int	space;
  int i;

  nb_star = 1;
  to_show = 4;
  count = to_show;
  space = 2;

  i = 0;
  while (i < lines_stage_desc)
    {
      if (i == to_show)
    	{
    	  if (count != 4 && (count % 2 == 0))
    	    space = space +2;

    	  to_show = to_show + count +1;
    	  nb_star = nb_star - space -2;
    	  count++;
    	}
      my_print_line(spines_base, nb_star, '*');
      nb_star = nb_star +2;
      i++;
    }
}


void	print_trunk(int spines_base, int input_size)
{
  int	nb_trunc;
  int	i;

  nb_trunc = input_size;

  i = 0;
  if (input_size % 2 == 0)
    nb_trunc++;

  while (i < input_size)
    {
      my_print_line(spines_base, nb_trunc, '|');
      i++;
    }
}


void	tree(int input_size)
{
  int	lines_stage_desc;
  int	spines_base;
  int	count;

  lines_stage_desc = 0;

  count = input_size;
  while (count > 0)
	{
	  lines_stage_desc = lines_stage_desc + count +3;
	  count = count - 1;
	}
  spines_base = get_spines_base(input_size);
  print_leaves(lines_stage_desc, spines_base);
  print_trunk(spines_base, input_size);
}


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    my_putstr("\nChoose a size of tree in CLI argument.\n\n");
    return (-1);
  }

  int input_size; 
  input_size = atoi(argv[1]);    // Convert argument to number: atoi('string') = 0

  if (input_size < 1)
  {
    my_putstr("\nChoose a positive integer argument like 1 or more.\n\n");
    return (-1);
  }

  if (input_size > 0 && input_size < 9)
  {
    tree(input_size);
    my_putstr("\nYou can do a bigger tree if you want...\n\n");
    return (0);
  }

  if (input_size == 9)
  {
    tree(input_size);
    my_putstr("\nWhat a huge fir you just did !\n\n");
    return (0);
  }

  if (input_size > 9)
  {
    my_putstr("\n9 is big enough, think that you would climb the ladder to decorate it.\n\n");
    return (-1);
  }

  else
    my_putstr("\nError: try with a positive integer argument.\n\n");
  return (-1);
}
