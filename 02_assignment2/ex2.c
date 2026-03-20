#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Ham de viet lai chuoi sau khi tach xong cac chu so
void reverse(char s[]){
	int i, j;
	char t;
	for(i=0,j= strlen(s)-1; i<j; i++, j--){
		t =s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
void itoa(int n, char s[]){
	int i, sign;
//Luu lai so ban dau
	sign = n;
	i = 0;
//Tach tung chu so tu cuoi len dau
	do {
		s[i++] = abs(n%10) + '0';
	} while ((n/=10)!=0);
//Neu so ban dau <0 thi them dau tru
	if(sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';
//Dao nguoc lai de duoc ket qua
	reverse(s);
}
int main(){
	char buffer[50];
//Test 1:
	int num1 = 4361;
	itoa(num1, buffer);
	printf("Test1: %s\n", buffer);
//Test 2:
	int num2 = -214748368;
	itoa(num2, buffer);
	printf("Test 2: %s\n", buffer);
	return 0;
}
