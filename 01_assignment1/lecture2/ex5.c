#include <stdio.h>
#include <math.h>
#include <string.h>

int htoi(char s[]){
	int val	=0;
	int t	=0;
	int l	= strlen(s);
	int val2=0;
	int i;
	
	if(l >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	t = 2;

	for (i = t; i < l; i++){
		if(s[i] >= '0' && s[i]<= '9')
			val2 = s[i] -'0';
		else if(s[i] >= 'a' && s[i] <= 'f')
			val2 = s[i] - 'a' + 10;
		else if(s[i] >= 'A' && s[i] <= 'F')
			val2 = s[i] - 'A' + 10;
		else
			break;
	val += val2 * pow(16, l - 1 - i);
	}
	return val;
}
int main(){
	printf("%d\n", htoi("0x1FFF"));
	return 0;
}
	 	
