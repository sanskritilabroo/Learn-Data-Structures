#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palin(char a[],int i,int n)
{
	bool flag=true;
	if (a[i]=='\0')
		return flag;
	if (a[i] == a[n])
		return palin(a,i+1,n-1);
	else
		flag=false;
}
void main()	 
{
	int j=0; int ct=0;
	char a[30];
	printf("Enter word:"); 
	gets(a);
	while(a[j]!='\0'){
		j++;
		ct++;
	}
	int i=0;
	if (palin(a,i,ct-1) == true)
		printf("Palindrome");
	else
		printf("Not a palindrome");
}