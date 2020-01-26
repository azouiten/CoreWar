#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int	fd = open("blobfile.cor", O_CREAT | O_RDWR);
	char	c = 'k';
	unsigned long long magic = 0xea83f3;

	write(fd, &magic, 4);
	write(fd, &c, 1);
}
