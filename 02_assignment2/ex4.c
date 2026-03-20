#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Ham dao nguoc sau khi tach tung chu so
void reverse(char s[]){
	int i, j;
	char t;
	for (i=0, j =strlen(s) - 1; i<j; i++, j--){
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
//Ham chuyen doi n sang co so b, luu vao chuoi s
void itob(int n, char s[], int b){
	int i, sign;
	int digit;
	sign = n;
	i = 0;
	do{
		digit = abs(n%b);
		if(digit <= 9){
			s[i++] = digit + '0';
		} else {
			s[i++] = digit - 10 + 'a';
		}
	} while ((n/=b) != 0);
	s[i] = '\0';
	reverse(s);
}
int main() {
	char buffer[100];
	int num = 255;
//Chuyen sang co so 2
	itob(num, buffer, 2);
	printf("%s\n", buffer);
//Chuyen sang co so 8
	itob(num, buffer, 8);
	printf("%s\n", buffer);
//Chuyen sang co so 16
	itob(num, buffer, 16);
	printf("%s\n", buffer);
	return 0;
}
