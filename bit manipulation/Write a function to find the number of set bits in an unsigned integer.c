#include<stdio.h>

main()
{
    unsigned int x;
    int c=0;
    scanf("%d",&x);
    char c1=(char)97;
    int a=(int)'a';
    while(x>0)
    {
        int a=x&1;
        if(a==1)c++;
        x=x>>1;
    }
  //  printf("%c\n%d",c1,a);
    char str[10]="qwe rt\0ji";
sprintf(str, "%d", 42);
 printf("%c\n",str[0]);
 char s[] = "450677";
 char s1[]="67";
 char *c11=strstr(s,s1);
//int num = atoi(s);
printf("%c\n",*(++c11));
}
