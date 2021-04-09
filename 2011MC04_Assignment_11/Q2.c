/*
Avinash Singh
2011MC04
*/

/*
Given Test Case:
abcabc
winner->Shyam

also Try 

wbab
winner->Ram

*/



#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100000

//Creating an array of 123 elements from index 0-122. Idea is that it will basically cover elements a-z with ASCII(97-122) and A-Z with ASCII(65-90)
int map[123]={0};

//Function to predict the Winner
char *Winner(char *str,int left,int right,char *P1)
{
//Second Player
char *P2;

//Extracting ASCII Value of left most letter
int left_letter =(int)(str[left]);            // Type casting the character using (int) to ge its equivalent ASCII Value.
//Extracting ASCII Value of right most letter
int right_letter=(int)(str[right]);

//If P1 is Ram then P2 will be Shyam and vice versa.
if(strcmp(P1,"Ram"))
{
P2="Ram";
}
else
{
P2="Shyam";
}

//If left and right pointer pointing to same index
if(left==right)
{
if(map[left_letter])  //checking if the specific character was already observed earlier by looking its status in the array map[].
return P1;
else
return "Tie";         //No elements were repeated .
}

//If any one of the left or right letter is already observed. Immediately the current player will pick the already observed letter and be declaered as the winner.
if(map[left_letter] || map[right_letter])
{
return P1;
}

//If any one of the second or second last letter is already observed. Immediately the next player will pick the already observed letter and be declaered as the winner.
if(map[(int)(str[left+1])] || map[(int)(str[right-1])])
{
return P2;
}

//if 2 successive elements in left are similar. We will not pick either of them and instead pick the rightmost element.
 if(str[left+1]==str[left])
 {
  //Rightmost letter status changed to Observed in the map[] by assigning 1.
  map[right_letter]=1;
  return Winner(str,left,right-1,P2);
 }

//if 2 successive elements in right are similar. We will not pick either of them and instead pick the leftmost element.
 else if(str[right-1]==str[right])
 {
 	
  //Leftmost letter status changed to Observed in the map[] by assigning 1.
  map[left_letter]=1;
  return Winner(str,left+1,right,P2);
 }

 if(map[(int)(str[left+1])] || strcmp(P1,"Shyam") && !map[(int)(str[right-1])])
 {
  map[right_letter]=1;
  return Winner(str,left,right-1,P2);
 }
 else
 {
  map[left_letter]=1;
  return Winner(str,left+1,right,P2);
 }

}
//main()

int main()
{
int length;
printf("\nEnter a String :  \n");
char str[max];
gets(str);
length=strlen(str);

//Given: Player 1 is Ram
char *P1="Ram";

//Calling the function Winner()
printf("Winner is : %s",Winner(str,0,length-1,P1));
}
