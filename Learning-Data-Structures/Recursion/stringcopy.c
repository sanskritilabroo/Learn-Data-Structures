#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void copy(char *str1, char *str2)
{
	if (*str1 != '\0')
	{
		*str2 = *str1;
		copy(str1+1,str2+1);
	}
}
int main(){
	
	char str1[30], str2[30];
	printf("Enter word:"); 
	gets(str1);
	printf("Copy of the string is:");
	copy(str1,str2);
	puts(str2);
	return 0;
}