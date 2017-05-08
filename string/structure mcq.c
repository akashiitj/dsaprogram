#include<stdio.h>

int main()
{
    int a = 12;
    char *ptr = &a;
    printf("%u", *ptr);
    getchar();
    return 0;
}
