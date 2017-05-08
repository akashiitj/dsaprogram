#include<iostream>
using namespace std;
class str
{
public:
    int c=0;
    int now(char *p)
    {
        while(p[0]!=NULL)
        {
            if(p[0]==(' ')||p[0]=='\t'||p[0]=='\n')
                p++;
            else
            {
                c++;
                while(p[0]!=(' ')&&p[0]!='\t'&&p[0]!='\n')
                    p++;
            }
        }
        return c;
    }
};
main()
{
    char str1[] = "dfr";
    str so;
    cout<<so.now(str1);
}
