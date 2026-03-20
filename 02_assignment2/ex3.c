#include <stdio.h>
void expand(char s1[], char s2[]){
	char c;
	int i = 0;
	int j = 0;
//Doc tung ki tu cua s1 cho toi khi gap \0
	while ((c=s1[i++]) != '\0'){
//Kiem tra xem ki tu tiep theo co phai dau - khong va ki tu sau dau - co > ki tu truoc dau - khong
		if(s1[i] == '-' && s1[i+1] >= c) {
			i++;
//In ra cac ki tu viet tat
		while (c<s1[i]){
			s2[j++] = c;
			c++;
		}
		} else{
			s2[j++] = c;
		}
	}
	s2[j] = c;
}
int main (){
	char s1[] = "-a-z 0-9 a-b-c a-z0-9 z-a-";
	char s2[200];
	printf("Chuoi goc: %s\n",s1);
	expand(s1, s2);
	printf("Chuoi mo rong: %s\n", s2);
	return 0;
}
