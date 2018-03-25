#include "ft_utils.h"

int		ft_printf(const char* format, ...)
{
	int i;
	int args;
	char **args_type;
	va_list aptr;

	i = 0;
	args = ft_argsnumber((char *)format);
	
	args_type = (char **)malloc(sizeof(char **) + args + 1);
	args_type = ft_argstype((char *)format); //seg fault
	
	va_start(aptr, format);
	while (i < args)
	{
		if (args_type[i][0] == 's')
			format = ft_strrep((char *)format, va_arg(aptr, char*), "%s");
		else if (args_type[i][0] == 'c')
			format = ft_strrep((char *)format, ft_ctos(va_arg(aptr, int)), "%c");
		else if (args_type[i][0] == 'i')
			format = ft_strrep((char *)format, ft_itoa(va_arg(aptr, int)), "%i");
		else if (args_type[i][0] == 'd')
			format = ft_strrep((char *)format, ft_itoa(va_arg(aptr, int)), "%d");
		i++;
	}
	va_end(aptr);
	ft_putstr((char *)format);

	return (ft_printf_ret((char *)format));
}

int		ft_printf_ret(char *format)
{
	int i;

	i = 0;
	while (format[i])
		i++;

	return(i);
}
