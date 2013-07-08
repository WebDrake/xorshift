#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint32_t xor32()
{
	static uint32_t y = 2463534242UL;
	y^=(y<<13); y=(y>>17); return (y^=(y<<5));
}

int main(void)
{
	size_t i;

	printf("Xorshift32:");
	for(i=0; i<10; ++i)
	{
		printf("  %"PRIu32, xor32());
	}
	printf("\n");

	return 0;
}
