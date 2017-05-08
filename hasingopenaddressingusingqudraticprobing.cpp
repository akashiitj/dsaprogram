#include<iostream>
using namespace std;
class hashing
{
public:
    int a[11]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int m=11;
    int hashfunction(int data,int i)
    {
        return (data+i+(3*i*i))%m;//return ((data%m)+(((i*i)+i)/2)%m);
    }
    void insert1(int x)
    {
        int j=0;
        int key;
        while(true)
        {
            key=hashfunction(x,j);
            if(a[key]==-1||a[key]==-2)
            {
                a[key]=x;
                goto endinsert;
            }
            j++;
        }
        if((j-1)==m)cout<<"table is full";
endinsert:
        ;
    }
    void show()
    {
        for(int i=0; i<m; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    int search1(int nts)
    {
        int j=0;
        int key1=hashfunction(nts,0);
        while(a[key1]!=nts&&j<=8)
        {
            j++;
            key1=hashfunction(nts,j);

        }
        if(a[key1]==nts)return key1;
        else return -5;
    }
    void delete1(int ntd)
    {
        int placeno;
        placeno= search1(ntd);
        if(placeno==-5)cout<<"no not found"<<endl;
        a[placeno]=-2;
    }
};
main()
{
    hashing ho;
    string str;

    while(true)
    {
        cin>>str;
        if(str[0]=='i')
        {
            int x1;
            cin>>x1;
            ho.insert1(x1);
        }
        if(str[0]=='d')
        {
            int x1;                               //Fortunately, it is possible to get good results from quadratic probing at low cost.
                                                // The right combination of probe function and table size will visit many slots in the table.
                                                // In particular, if the hash table size is a prime number and the probe function is p(K, i) = i2,
                                                //then at least half the slots in the table will be visited.
                                                //Thus, if the table is less than half full, we can be certain that a free slot will be found.
                                                //Alternatively, if the hash table size is a power of two and the probe function is p(K, i) = (i2 + i)/2,
                                                // then every slot in the table will be visited by the probe function.
            cin>>x1;
            ho.delete1(x1);
        }
        if(str[0]=='s')
        {
            int x3;
            cin>>x3;
            int x4=ho.search1(x3);
            if(x4==-5)cout<<"element not found";
            else cout<<x4<<endl;
        }

        ho.show();
    }


}

