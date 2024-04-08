#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void tower(int n,char A, char B, char C)
{
	if (n==0)
		return;
	tower(n-1,A,C,B);
	printf("We need move %d disks from %c to %c is:", n, A, C);
	tower(n-1,A,B,C);
}

void main()
{
	int n;
	printf("Enter no. of disks:"); 	
	scanf("%d",&n);
	printf("No. of steps required to move disks is:");
	tower(n,'A','B','C');
}