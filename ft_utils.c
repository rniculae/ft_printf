#include "ft_utils.h"

/**********************
* BASIC / LIBFT FUNCS *
**********************/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;

	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	else
		return 0;
}

void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}
char	*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*str;

	tmpn = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
/************
* FT_PRINTF *
************/

char	*ft_ctos(char c)
{
	char *ret;
	ret = (char *)malloc(2);
	ret[0] = c;
	ret[1] = '\0';
	return ret;
}

int		ft_argsnumber(char *str)
{
	int args;
	int i;

	i = 0;
	args = 0;
	while (str[i])
	{
		if (str[i - 1] == '%' && ft_isalpha(str[i]))
			args++;
		i++;
	}

	return (args);
}

char	**ft_argstype(char *str)
{
	char **type;
	int args;
	int i;

	i = 0;
	args = 0;
	type = (char **)malloc(sizeof(char**) + ft_argsnumber(str));
	while (str[i])
	{
		if (str[i - 1] == '%' && ft_isalpha(str[i]))
		{
			type[args] = (char *)malloc(sizeof(char *) + 1);
			type[args][0] = str[i];
			type[args][1] = '\0';
			printf("[%d] -> %s\n", args, type[args]);
			args++;
		}
		i++;
	}
	printf("out args = %d\n", args);
	type[args] = NULL;
	printf("zero: (%s)\n",type[0]);
	return(type);
}

#define SPACE_REQ ft_strlen(base) - 2 + ft_strlen(sub)
char	*ft_strrep(char *base, char *sub, char *find)
{
	int i;
	int k;
	int j;
	char *mod;

	i = -1;
	j = 0;
	k = 0;
	mod = (char *)malloc(sizeof(char *) + SPACE_REQ);
	while (i++ <= SPACE_REQ)
	{
		if (base[i] == find[0] && base[i + 1] == find[1] && k == 0)
		{
			while (k < ft_strlen(sub))
				mod[i++] = sub[k++];
			j += 2;
			i--;
		}
		else
		{
			if (base[j])
				mod[i] = base[j];
			else
				break;
			j++;
		}
	}
	mod[i] = '\0';
	return (mod);
}