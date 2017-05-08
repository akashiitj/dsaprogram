#include<stdio.h>

main()
{
    unsigned int x;
    int c=0;
    scanf("%d",&x);
    while(x>0)
    {
        int a=x&1;
        if(a==1)c++;
        x=x>>1;
    }
    printf("%d\n",c);
}
