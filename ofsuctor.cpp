#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;
struct node
{
    int data;
    node* next;
}  *ptr[10];
void usinglinklist(int *x,int *y)
{
    int p;
    p=*x;
    *x=*y;
    *y=p;
}

node* traverse(node *q)
{   //cout<<"traverse";
    while (q->next != NULL)
    q = q->next;
    return q;
}
void print(node *q)
{    //cout<<"print";
     while (q ->next!= NULL)
        {cout<<q->next->data<<"    ";q=q->next;}
}
void insert1(int x)
{   //cout<<"insert";
    node *p;
  //  p = new node;
    p = traverse(ptr[x%10]);
    node *n;
    n=new node;
    n->data=x;
    n->next=NULL;
    p->next=n;
}
int returnlink()
{
    return false;
}
int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}

// The main function that returns maximum product obtainable
// from a rope of length n
int maxProd(int n)
{
    // Base cases
    if (n == 0 || n == 1) return 0;

    // Make a cut at different places and take the maximum of all
    int max_val = 0;
    for (int i = 1; i < n; i++)
      max_val = max(max_val, i*(n-i), maxProd(n-i)*i);

    // Return the maximum of all values
    return max_val;
}
int main ()
{   for(int i=0;i<10;i++){
    ptr[i] = new node;
    ptr[i]->data=0;
    ptr[i]->next = NULL;}
    int x;
   // insert1(5);
   // insert1(15);insert1(25);
   // print(ptr[5]);

   while(returnlink())
    {

     insert1(x);
    }
    vector <int> llll;
    long llllllllllllll, qqqqqqqqq;


      cin >> qqqqqqqqq;
      while ( qqqqqqqqq >= 1 )
        {
           llllllllllllll = qqqqqqqqq % 2;
           qqqqqqqqq /= 2;
           llll.push_back(llllllllllllll);
        }
      cout << endl << endl << endl;

      for ( int i = (int) llll.size() - 1; i >= 0; i-- )
           cout << llll[i] << "";
    getch();
    return 0;
}
