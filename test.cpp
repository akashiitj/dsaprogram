#include<stdio.h>
int main()
{
    int i = -5;
    while (i <= 5)
    {  // printf("GeeksQuiz1");
        if (i >= 0)
            break;
        else
        {
            i++;

            continue;
            printf("GeeksQuiz1");
        }
        printf("GeeksQuiz");
    }
    return 0;
}
