#include<iostream>
using namespace std;
struct is//information stored
{   is *ptc;//pointer to chef
    int h;
    int dishscore;
};
is* pood(is a[],int dn)//return present owner of dish,pass dish number
{
    is* dp=a[dn-1].ptc;
    while(dp!=NULL)
    {
        dp=dp->ptc;
    }
}
main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        is a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i].dishscore;
            a[i].h=0;
            a[i].ptc=NULL;
        }
        int noq;//no of queries
        cin>>noq;
        while(noq>0)
        {
            int wq;//which query
            cin>>wq;
            if(wq==0)
            {
                int x,y;
                cin>>x;
                cin>>y;
                is *x1=pood( a, x);
                is *y1=pood(a,y);
             //   cout<<x<<" "<<y<<endl;
                 // if( pood(a,x)== pood(a,y))
                if(a[x-1].chefno==a[y-1].chefno)
                    cout<<"Invalid query!"<<endl;
                else if(a[x-1].dishscore==a[y-1].dishscore){}
                else if(x1.dishscore>y1.dishscore)
                        {
                            a[y-1].chefno=a[x-1].chefno;
                        }
                else
                      a[x-1].chefno=a[y-1].chefno;
            }
            else
            {
                int x;
                cin>>x;
                x=pood(a,x);
                cout<<a[x-1].chefno<<endl;
            }
            noq--;
        }
        t--;
    }

}

