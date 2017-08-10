#include "eval.h"

int	ft_check(char av, char *ope)
{
	int i ;

	i = 0;
	while (ope[i])
	{
		if (ope[i] == av)
			return (1);
		i++;
	}
	return (0);
}

int	ft_arulast(char *av, int j)
{
	j++;
	while ((av[j] >= '0' && av[j] <= '9' || av[j] == '-'))
		j++;
	if (av[j] == '\0')
		return (1);
	return (0);
}

char *ft_strcpylast(char *tmp, char *av, int j, int k)
{
	j++;
	while(av[j])
	{
		tmp[k] = av[j];
		k++;
		j++;
	}
	tmp[k] = '\0';
	return (tmp);
}

int	eval_expr(char *av, int i, int j)
{
	int (*calcul[4])(int, int)
	= {ft_addition, ft_multiplication, ft_modulo, ft_division};
	char ope[] = "+*%/";
	char tmp[10];
	int k;
	int z;

	z = j;
	while (av[z] && i == 0)
	{
		if (av[z] == '+' && ft_arulast(av, z) == 1)
		{
			ft_strcpylast(tmp, av, z, 0);
			printf("LAST = %s\n", tmp);
			av[z] = '\0';
			printf("AFTER LAST = %s | ope = %c\n", av, ope[i]);
			return ((*calcul[0])(ft_atoi(tmp),eval_expr(av, i, 0)));
		}
		z++;
	}
	while (ope[i])
	{
		printf("--- BOUCLE de {%c}---\n", ope[i]);
		k = 0;
		while (av[j])
		{
			tmp[k] = av[j];
			//printf("tmp[k] = %c\n", tmp[k]);
			if (ft_check(tmp[k], ope) == 1)
			{
				tmp[k] = '\0';
				printf("tmp erased = %s\n", tmp, ope[i]);
				k = 0;
			}
			else
				k++;
			j++;
			if (av[j] == ope[i])
			{
				tmp[k] = '\0';
				printf("tmp in return = %s | ope = %c\n", tmp, ope[i]);
				return ((*calcul[i])(ft_atoi(tmp),eval_expr(av, i, j)));
			}
		}
		j = 0;
		i++;
	}
	tmp[k] = '\0';
	printf("final tmp = %s\n", tmp);
	return (ft_atoi(tmp));
}
