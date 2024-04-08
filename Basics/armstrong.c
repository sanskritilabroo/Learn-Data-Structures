#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    scanf("%d",&n);
    int n1=n,arm=0;
    while(n>9)
    {
        int d=n%10;
        n=n/10;
        arm=arm+pow(d,3);
    }
    arm+=pow(n,3);
    if(arm==n1) printf("Armstrong");
    else printf("Not armstrong");
}
