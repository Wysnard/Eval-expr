#include "eval.h"

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

char *no_whitespace(char *str)
{
	int	i;
	int	j;
	char *cp;

	i = 0;
	j = 0;
	cp = malloc(sizeof(char) * (ft_strlen(str) + 5));
	while (str[i])
	{
		if (str[i] == '-' && j > 0)
		{
			cp[j] = '+';
			cp[j + 1] = '-';
			j = j + 2;
			i++;
		}
		if (str[i] != ' ')
		{
			cp[j] = str[i];
			j++;
		}
		i++;
	}
	cp[j] = '\0';
	return (cp);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
