#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_eval
{
	char ope;
}							t_eval;

void 	ft_putchar(char c);
void 	ft_putstr(char *str);
int		ft_strlen(char *str);
char 	*no_whitespace(char *str);
int		ft_addition(int a, int b);
int		ft_soustraction(int a, int b);
int		ft_multiplication(int a, int b);
int		ft_division(int a, int b);
int		ft_modulo(int a, int b);
int		eval_expr(char *av, int j, int i);
int		ft_atoi(char *str);
void 	ft_putnbr(int nb);

#endif
