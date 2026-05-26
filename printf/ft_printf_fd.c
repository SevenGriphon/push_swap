#include "ft_printf.h"

static int	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_strstring_fd(int fd, char *s)
{
	int	i;

	if (!s)
		return (ft_strstring_fd(fd, "(null)"));
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(fd, s[i]);
		i++;
	}
	return (i);
}

static int	ft_putnbr_fd(int fd, int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_fd(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

static int	ft_putunsigned_fd(int fd, unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned_fd(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

static int	ft_puthex_fd(int fd, unsigned long nb, char *base)
{
	int	i;

	i = 0;
	if (nb < 16)
		i += ft_putchar_fd(fd, base[nb]);
	else
	{
		i += ft_puthex_fd(fd, nb / 16, base);
		i += ft_puthex_fd(fd, nb % 16, base);
	}
	return (i);
}

static int	ft_putptr_fd(int fd, void *ptr)
{
	if (!ptr)
		return (write(fd, "(nil)", 5));
	ft_putchar_fd(fd, '0');
	ft_putchar_fd(fd, 'x');
	return (ft_puthex_fd(fd, (unsigned long)ptr, "0123456789abcdef") + 2);
}

static int	ft_handle_format_fd(int fd, char spec, va_list *args)
{
	char	c;

	if (spec == 'c')
	{
		c = (char)va_arg(*args, int);
		write(fd, &c, 1);
		return (1);
	}
	else if (spec == 's')
		return (ft_strstring_fd(fd, va_arg(*args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr_fd(fd, va_arg(*args, int)));
	else if (spec == 'u')
		return (ft_putunsigned_fd(fd, va_arg(*args, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex_fd(fd, va_arg(*args, unsigned int),
				"0123456789abcdef"));
	else if (spec == 'X')
		return (ft_puthex_fd(fd, va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	else if (spec == 'p')
		return (ft_putptr_fd(fd, va_arg(*args, void *)));
	else if (spec == '%')
		return (write(fd, "%", 1));
	ft_putchar_fd(fd, '%');
	return (ft_putchar_fd(fd, spec) + 1);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += ft_handle_format_fd(fd, format[i + 1], &args);
			i++;
		}
		else
			count += ft_putchar_fd(fd, format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
