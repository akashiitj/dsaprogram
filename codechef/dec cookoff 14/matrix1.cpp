#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print_string(char str[],char new_str[],int current_len,int n,int len)
{
    /*
    str=orignal set,
    new_str=empty char array,
    current_len=0(Intially)
    n=no of elements to be used
    len=the value of p given*/
    if(current_len==len)//print string when length is equal to p
    {
        printf("%s\n",new_str);
        return;
    }
    else
    {
        int i;
        for(i=0;i<n;i++)
        {
            new_str[current_len]=str[i];
            print_string(str,new_str,current_len+1,n,len);
        }
    }
}
int main()
{
    char set[]={'a','b'};
    char arr[10]="";
    print_string(set,arr,0,2,1);
    return 0;
}
