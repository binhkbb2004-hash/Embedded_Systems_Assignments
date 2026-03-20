#include <stdio.h>
int main(){
	int c;
puts("Nhap van ban:");
while((c=getchar()) !=EOF){
	if(c=='\t')
		printf("\\t");
	else if(c=='\b')
		printf("\\b");
	else if(c=='\\')
		printf("\\\\");
	else
		putchar(c);
}
printf("\n");
return 0;
}
