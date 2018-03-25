#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h> /* linux */
/*	libft				*/
int		ft_strlen(char *str);
int		ft_isalpha(char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	itoa_isnegative(int *n, int *negative);
char	*ft_itoa(int n);
/*	semi_ft_printf		*/
char	*ft_ctos(char c);
char	*ft_strrep(char *base, char *sub, char* find);
/*	ft_printf			*/
int		ft_argsnumber(char *str);
char	**ft_argstype(char *str);
int		ft_printf(const char *format, ...);
int		ft_printf_ret(char *format);

typedef struct	s_pecado
{
	char	*flag;
	void	*data;
}				t_pecado;

/*	allowed functions	*/
/*	write				*/
/*	malloc				*/
/*	free				*/
/*	exit				*/
/*	man 3 stdarg		*/
