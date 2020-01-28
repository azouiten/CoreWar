#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int	fd = open("blobfile.cor", O_CREAT | O_RDWR);
	int	c = 0;
	unsigned long long magic = 0xea83f3;

	write(fd, &magic, 4);
	write(fd, &c, 4);
}
