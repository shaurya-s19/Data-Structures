// Calculate area of different shapes using switch case

#include <stdio.h>
#define triangle(b,h) (0.5*b*h)
#define rectangle(l,b) (l*b)
#define square(s) (s*s)
#define circle(r) (3.14*r*r)

int main(){
	int shape;
	printf("\n1: Triangle\n2: Rectangle\n3: Square\n4: Circle\nWhat's your choice? :");
	scanf("%d" , &shape);
	switch(shape){
		case 1:
			int base , height;
			printf("Enter Base and Height of triangle : ");
			scanf("%d %d" , &base , &height);
			printf("Area : %0.2f" , triangle(base,height));
			break;
		case 2:
			int length , breadth;
			printf("Enter length and breadth of rectangle : ");
			scanf("%d %d" , &length , &breadth);
			printf("Area : %d" , rectangle(length,breadth));
			break;
		case 3:
			int side;
			printf("Enter side of square : ");
			scanf("%d" , &side);
			printf("Area : %d" , square(side));
			break;
		case 4:
			int radius;
			printf("Enter radius of circle : ");
			scanf("%d" , &radius);
			printf("Area : %0.2f" , circle(radius));
			break;
		default:
			printf("Invalid!");
	}
}
