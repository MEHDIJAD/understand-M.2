#include <stdio.h>
#include <unistd.h>

int	ft_getbytecount(unsigned char *subj)
{
	if (subj[0] <= 0x7F) // 0-127 (1 byte)
		return (1);
	else if (subj[0] >= 0xC0 && subj[0] <= 0xDF) // 192-223 (2 bytes)
		return (2);
	else if (subj[0] >= 0xE0 && subj[0] <= 0xEF)
		return (3);
	else if (subj[0] >= 0xF0 && subj[0] <= 0xF7)
		return (4);
	return (-1);
}
void	ft_sendmessage(char *argv)
{
	int i = 0;
	while (argv[i])
	{
		// For each character, calculate the number of bytes based on the first byte
		int byte_count = ft_getbytecount((unsigned char*)&argv[i]);
		if (byte_count == -1)
			break; // Invalid byte, break
		// Print the number of bytes for the current character
		printf("%d\n", byte_count);
		// Move to the next character by the number of bytes we just found
		i += byte_count;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_sendmessage(av[1]);
	}
	return 0;
}
