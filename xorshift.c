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

uint32_t xor96()
{
	static uint32_t x = 123456789, y = 362436069, z = 521288629;
	uint32_t t = (x^(x<<10)); x = y; y = z; return z = (z^(z>>26))^(t^(t>>5));
}

uint32_t xor128()
{
	static uint32_t x = 123456789, y = 362436069, z = 521288629,
	                w = 88675123;
	uint32_t t = (x^(x<<11)); x = y; y = z; z = w; return w = (w^(w>>19))^(t^(t>>8));
}

uint32_t xor160()
{
	static uint32_t x = 123456789, y = 362436069, z = 521288629,
	                w = 88675123, v = 5783321;
	uint32_t t = (x^(x>>2)); x = y; y = z; z = w; w = v; return v = (v^(v>>4))^(t^(t>>1));
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
	printf("\n\n");

	printf("Xorshift96:");
	for(i=0; i<10; ++i)
	{
		printf("  %"PRIu32, xor96());
	}
	printf("\n\n");

	printf("Xorshift128:");
	for(i=0; i<10; ++i)
	{
		printf("  %"PRIu32, xor128());
	}
	printf("\n\n");

	printf("Xorshift160:");
	for(i=0; i<10; ++i)
	{
		printf("  %"PRIu32, xor160());
	}
	printf("\n");

	return 0;
}
