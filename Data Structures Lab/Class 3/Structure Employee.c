#include <stdio.h>

struct Employee{
	int data_number;
	int emp_id;
	char emp_name[25];
	float basic_salary;
	long int ph_no;
	float gross_salary;
};

void print(struct Employee *emp , int index){
	printf("\n Data Number :  %d" , emp[index].data_number);
	printf("\n ID :  %d" , emp[index].emp_id);
	printf("\n Name :  %s" , emp[index].emp_name);
	printf("\n Basic Salary :  %0.2f" , emp[index].basic_salary);
	printf("\n Phone Number :  %ld" , emp[index].ph_no);
	printf("\n Gross Salary :  %0.2f\n" , emp[index].gross_salary);
}

int main(){
	int count;
	printf("Enter no. of inputs");
	scanf("%d" , &count);
	
	struct Employee e[count];
	for(int i = 0 ; i < count ; i++){
		e[i].data_number = i+1;
		printf("\n Enter Employee ID : ");
		scanf("%d" ,&e[i].emp_id);
		
		printf("\n Enter Employee Name : ");
		getchar();
		scanf("%[^\n]s" , e[i].emp_name);
		
		printf("\n Enter Basic Salary : ");
		scanf("%f",&e[i].basic_salary);
		
		printf("\n Enter Employee's phone number : ");
		scanf("%ld" ,&e[i].ph_no);
		
		float gross_salary;
		int b_sal = e[i].basic_salary;
		gross_salary = b_sal + (0.2 * b_sal) + (0.1 * b_sal);
		e[i].gross_salary = gross_salary;
		
		printf("------------Record Added--------------");
		print(e , i);
	}
	
	return 0;
}

