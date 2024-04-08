#include <stdio.h>
#include <stdbool.h>

bool palin(char a[],int i,int n)
{
	bool flag = true;
	if (a[i] == a[n])
		return palin(a,i+1,n-1);
	else
		flag = false;
	return flag;


}
void main()
{
	int i=0; 
	int pos,n; 
	char *a[30];
	printf("Enter word:"); 
	while (a[i]!='\0')
	{
			scanf("%c",&a);
			n++;
	}
}