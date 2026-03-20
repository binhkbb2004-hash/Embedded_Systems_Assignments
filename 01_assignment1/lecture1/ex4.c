#include <stdio.h>
int main(){
	int c;
	int last_c = 0;
puts("Nhap van ban:");
while((c=getchar()) !=EOF){
	if((c!=' ')||(last_c!=' ')){
		putchar(c);}
	last_c = c;
}
printf("\n");
return 0;
}
