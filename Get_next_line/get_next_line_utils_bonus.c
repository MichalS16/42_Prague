#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*memory;
	unsigned char	*memory_first;
	unsigned int	max_int;
	unsigned int	i;

	max_int = 2147483647;
	if (count > max_int && size > max_int)
		return (NULL);
	memory = (unsigned char *) malloc(count * size);
	if (memory == NULL)
		return (NULL);
	memory_first = memory;
	i = 0;
	while (i < (count * size))
	{
		*memory++ = 0;
		i++;
	}
	return ((void *) memory_first);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_first;
	int		str_len;

	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc((str_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str_first = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str_first);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}