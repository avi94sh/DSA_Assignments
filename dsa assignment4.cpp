/* Generating an alphanumeric string */
#include<stdio.h> //including header files
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int higher_base(char*);//declaring the function to calculate highest base

int higher_base(char *c)
{
	int max=0; // initializing max as 0
	while(*c!='\0')// making loop
	{
		char chr=c[0];
	if(isdigit(chr))//will check if character is digit or alphabet
	{
		int ans=chr-'0';
		if(ans>max)
		max=ans;
	}
	else if(isalpha(chr))
	{
		int ans=chr-'A'+10;
		if(ans>max)
		max=ans;
	}
	c++;
}
	return max+1; //adding 1 to the maximum digit in a string to find base
}



void generate_string(char*,int); //declare a void return type function

void generate_string(char str[],int num){ //defining the function and taking a string amd number as arguments
	bool toss;        //using the code from previous assignment with for loop 
	
	for(int i=0;i<num;i++)
	{
		toss= rand()%2;
	    if(toss==true)
	     str[i]= rand() % (70-65+1) + 65;
	    else
	     str[i]= rand() % (57-48+1) + 48;
    }
    str[num]=0; //returning a string taking initial value as 0
}	

int main(void)
{
    srand(time(NULL));// use the seed in our main function
    char characters[11];//declare the main string
    int n;
    for(int i=0;i<50;i++)//for loop for iterate this process 50 times
	{
      n=rand()%((10-3)+1)+3;
      generate_string(characters, n);//calling our function
      int base_of_str=higher_base(characters);//calling function
      printf("the highest base of %s is %d \n", characters, base_of_str);//printing the base
     }
     
    return 0;
}
