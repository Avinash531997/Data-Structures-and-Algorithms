//Avinash Singh , 2011MC04
#include<stdio.h>
#include<conio.h>
//Function to check prime
int checkprime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}

int main()
{
  int l=2,r=500,x=0,i;
    for(i=l; i < r; i++)
    {
        if(checkprime(i) && checkprime(i + 2)) //checking if a number N and N+2 both are prime or not
        {            
            printf("(%d, %d) \n",i,i + 2);
            i = i + 1; 
            x+=1;  //increasing count if twinprime pair is found.
        }        
		if(x==20) //Terminate the loop once we find 20 pairs of twinprime.
		break;
		else
		continue;        
    }    
return 0;
}


