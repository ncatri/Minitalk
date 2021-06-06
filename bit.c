#include <stdio.h>

void	print_bits(char c);

int main(void)
{
	char c;

	c = 0;
	printf("c = 0: ");
	print_bits(c);

	char d = 0x80;
	printf("0x80: ");
	print_bits(d);

	c |= 1;
	printf("c |= 1 : ");
	print_bits(c);
	c <<= 1;
	printf("c <<= 1 : ");
	print_bits(c);
}

void	print_bits(char c)
{
	int i;

	i = -1;
	while (++i < 8)
		printf("%d ", !!((c << i) & 0x80));

	printf("\n");
}
