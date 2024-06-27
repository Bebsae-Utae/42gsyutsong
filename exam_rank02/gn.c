#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


#define BUFFER_SIZE 4096

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(str);
	i = -1;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = 0;
	return (dup);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	rtn[7000000];
	int		n;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	n = read(fd, &buffer, 1);
	while (n > 0)
	{
		rtn[i++] = buffer;
		if (buffer == '\n')
			break ;
		n = read(fd, &buffer, 1);
	}
	rtn[i] = 0;
	if (n <= 0 && i == 0)
		return (0);
	return (ft_strdup(rtn));
}



int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line = get_next_line(fd);
    while (line) {
        printf("%s", line);
        free(line);  // Remember to free the allocated memory
        line = get_next_line(fd);
    }

    close(fd);
    return 0;
}