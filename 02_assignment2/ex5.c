#include <stdio.h>
#define MAX 100 //Do sau max cua stack
int sp = 0; // stack pointer
double val[MAX];
//Ham push
void push(double f){
	if(sp<MAX)
		val[sp++] = f;
	else
		printf("Stack da day, k the push\n");
}
//In phan tu tren cung
void print_top(void){
	if(sp>0){
		printf("Phan tu tren cung: %g\n", val[sp-1]);
	} else {
		printf("Ngan xep rong\n");
	}
}
//Nhan ban phan tu tren cung
void duplicate_top(void){
	if(sp>0){
		if(sp<MAX){
			double t = val[sp-1];
			val[sp++] = t;
		} else {
			printf("Ngan xep da day\n");
	}
		} else {
		printf("Ngan xep rong\n");
	}
}
//Hoan doi 2 phan tu tren cung
void swap_top(void){
	if(sp>1){
		double t = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = t;
	} else {
		printf("Khong du phan tu de hoan doi\n");
	}
}
//Clear Stack
void clear_stack(void){
	sp = 0;
}
int main(){
	push(10.5);
	push(20.0);
	print_top(); // in ra phan tu tren cung
	duplicate_top();
	print_top;
	push(23.5);
	push(21.5);
	swap_top();
	print_top();
	clear_stack();
	print_top();
	return 0;
}
