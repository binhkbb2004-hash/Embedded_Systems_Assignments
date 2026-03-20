#include <stdio.h>
#include <limits.h>
int main (){
	puts("GIOI HAN KIEU DU LIEU");
//char
	printf("Signed char	: %d - %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned char	: 0 - %u\n\n", UCHAR_MAX);
//short
	printf("Signed short	: %d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned short	: 0 - %u\n\n", USHRT_MAX);
//int
	printf("Signed int	: %d - %d\n", INT_MIN, INT_MAX);
	printf("Unsigned int	: 0 - %u\n\n", UINT_MAX);
//long
	printf("Signed long	: %ld - %ld\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long	: 0 - %lu\n\n", ULONG_MAX);

	return 0;
}
