#include "eval.h"

int main( int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%d", eval_expr(no_whitespace(argv[1]), 0, 0));
		//ft_putstr(no_whitespace(argv[1]));
		//printf("%d", ft_atoi(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}
