#include <stdio.h>
int main (){
	puts("GIOI HAN KIEU DU LIEU");
	unsigned char uchar_max = (unsigned char)~0;
	signed char schar_max = uchar_max / 2;
	signed char schar_min = -schar_max - 1;
	printf("Signed char	: %d - %d\n", schar_min, schar_max);
	printf("Unsigned char	: 0 - %u\n\n", uchar_max);
	unsigned short ushort_max = (unsigned short)~0;
	signed short short_max = ushort_max / 2;
	signed short short_min = -short_max - 1;
	printf("Signed short	: %d - %d\n", short_min, short_max);
	printf("Unsigned short	: 0 - %u\n\n", ushort_max);
	unsigned int uint_max = (unsigned int)~0;
	signed int sint_max = uint_max / 2;
	signed int sint_min = -sint_max - 1;
	printf("Signed int	: %d - %d\n", sint_min, sint_max);
	printf("Unsigned int	: 0 - %u\n\n", uint_max);
	unsigned long ulong_max = (unsigned long)~0;
	signed long slong_max = ulong_max / 2;
	signed long slong_min = -slong_max - 1;
	printf("Signed long	: %ld - %ld\n", slong_min, slong_max);
	printf("Unsigned long	: 0 - %lu\n\n", ulong_max);
	return 0;
}
