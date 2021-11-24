#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	size_t	offset;
	size_t	index;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	offset = len_d;
	index = 0;
	if (dstsize == 0)
		return (len_s);
	if (dstsize < len_d)
		return (dstsize + len_s);
	if (dstsize > 0)
	{
		while ((src[index] != '\0') && (offset < dstsize - 1))
		{
			dst[offset] = src[index];
			offset++;
			index++;
		}
		dst[offset] = '\0';
	}
	return (len_d + len_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	ft_strlcat(str, s2, len + 1);
	free(str);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	//free(str);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (start + i < len_s)
	{
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	//free(str);
	return (str);
}