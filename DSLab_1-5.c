//Calculate simple ineterest using call by reference 

#include <stdio.h>
int simpleinterest(int *p , int *r , int *t);
int main(){
	int p , r , t;
	printf("Enter Principle Amount , Rate and Time : ");
	scanf("%d %d %d" , &p , &r , &t);
	
	printf("\nSimple Interest : %d" , simpleinterest(&p , &r , &t));
	return 0;
}

int simpleinterest(int *p , int *r , int *t){
	int si;
	si = ((*p) * (*r) * (*t)) / 100;
	return si;
}

