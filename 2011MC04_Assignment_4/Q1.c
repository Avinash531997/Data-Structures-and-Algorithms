//Avinash Singh 2011MC04

#include<stdio.h>
#include<conio.h>
#include<string.h> 

#define max 100

//Defining Stack
struct Stack 
{
    int top;
    int array[max];
} st;
//st is the stack structure created

//Check if stack is full or not
int is_full()
{   
    if(st.top >= max)
        return 1;
    else 
        return 0;
}

//Check if stack is empty or not
int is_empty() 
{
 if(st.top == -1)
     return 1;
 else 
     return 0;
}

//Push element in the stack
void push(int item) 
{
    if (is_full())
        printf("Stack Overflow \n");
    else 
	{
        st.array[st.top + 1] = item;
        st.top++;
    }
}

//Pop element from the stack
int pop() 
{
    if (is_empty())
        printf("Stack Underflow \n");
    else 
	{
        st.top = st.top - 1;
        return st.array[st.top+1];
    }
}

int main() 
{
    char str[100];
    int i, length;
    st.top=-1;
    printf("Enter a string\n");
    gets(str);
    length = strlen(str);
    
    // Push all characters of input String to Stack
    for(i = 0; i < length; i++)
	{
        push(tolower(str[i]));  //Using lowercase() to convert alphabets to lowercase and then compare
    }
    

    for(i = 0; i < length; i++)
	{
        if(pop() != tolower(str[i]))
		 {
            printf("Not  Palindrome \n");
            return 0;
        }
    }

    printf("Palindrome \n");
    return 0;
}
