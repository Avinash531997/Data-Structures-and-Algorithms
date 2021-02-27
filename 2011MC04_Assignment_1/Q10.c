//Avinash Singh 2011MC04 
#include<stdio.h>
int main()
{
	int choice,a,b;
	printf("\n Enter two numbers");
	scanf("%d %d",&a,&b);
	printf("1.Addition \n");
	printf("2.Subtraction\n");
	printf("3.Multiplication\n");
	printf("4.Division \n");
	printf("Enter your choice \n");
	scanf("%d",&choice);
	switch(choice)    //Switch to the specific Case 
	{
	
	case 1:
		printf("%d + %d = %d ",a,b,a+b);  //Find Sum
		break;
	case 2:
		printf("%d - %d = %d ",a,b,a-b); //Find Difference
		break;
	case 3:
		printf("%d * %d = %d ",a,b,a*b); //Find Product
		break;
	case 4:
		printf("%d / %d = %d ",a,b,(float)a/b); //Find Quotient
		break;
	defaut:
		printf("Invalid Choice");
	}
return 0;
}

