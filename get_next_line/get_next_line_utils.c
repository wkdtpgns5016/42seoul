#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != 0)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < src_len && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*arr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (arr == 0)
		return (0);
	ft_strlcpy(arr, s1, s1_len + 1);
	ft_strlcpy(arr + s1_len, s2, s2_len + 1);
	arr[s1_len + s2_len] = '\0';
	return (arr);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*arr;

	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	ft_strlcpy(arr, s, len + 1);
	return (arr);
}