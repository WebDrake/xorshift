#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint32_t xor32()
{
	static uint32_t y = 2463534242UL;
	y^=(y<<13); y=(y>>17); return (y^=(y<<5));
}

uint32_t xor64()
{
	static uint32_t x = 123456789, y = 362436069;
	uint32_t t = (x^(x<<10)); x = y; return y = (y^(y>>10))^(t^(t>>13));
}

int main(void)
{
	size_t i;

	printf("Xorshift32:");
	for(i=0; i<10; ++i)
	{
		printf("  %"PRIu32, xor32());
	}
	printf("\n\n");

	printf("Xorshift64:");
	for(i=0; i<10; ++i)
	{
		printf("  %"PRIu32, xor64());
	}
	printf("\n");

	return 0;
}
