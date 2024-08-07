#include <stdio.h>
#include <stdlib.h>

struct Student{
	int data_number;
	int stu_roll;
	char stu_name[25];
	float mark1;
	float mark2;
	float mark3;
	float total_marks;
};

void print(struct Student *stu , int index){
	printf("\n Data Number :  %d" , stu[index].data_number);
	printf("\n Roll Number :  %d" , stu[index].stu_roll);
	printf("\n Name :  %s" , stu[index].stu_name);
	printf("\n Marks Subject 1 :  %0.1f" , stu[index].mark1);
	printf("\n Marks Subject 2 :  %0.1f" , stu[index].mark2);
	printf("\n Marks Subject 3 : %0.1f" , stu[index].mark3);
	printf("\n Total Marks :  %0.1f\n" , stu[index].total_marks);
}

int main(){
	int count;
	printf("Enter no. of inputs : ");
	scanf("%d" , &count);
	
	struct Student *s;
	s = (struct Student *)malloc(count * sizeof(struct Student));
	for(int i = 0 ; i < count ; i++){
		s[i].data_number = i+1;
		printf("\n Enter Student Roll number : ");
		scanf("%d" ,&(s+i)->stu_roll);
		
		printf("\n Enter Student Name : ");
		getchar();
		scanf("%[^\n]s" , (s+i)->stu_name);
		
		printf("\n Enter Marks in subject 1 : ");
		scanf("%f",&(s+i)->mark1);
		
		printf("\n Enter Marks in subject 2 : ");
		scanf("%f" ,&(s+i)->mark2);
		
		printf("\n Enter Marks in subject 3 : ");
		scanf("%f" ,&(s+i)->mark3);
		
		float total_marks;
		total_marks = (s+i)->mark1 + (s+i)->mark2 + (s+i)->mark3;
		s[i].total_marks = total_marks;
		
		printf("------------Record Added--------------");
		print(s , i);
	}
	
	return 0;
}

