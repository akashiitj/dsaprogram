#include <iostream>

using namespace std;

void print(int *sets, int k)
{
    for(int i=0; i<k; i++)
        cout << sets[i] << "\t";
    cout << "\n";
}

void subsets(int A[], int n, int k, int *sets, int index, int indexA)
{
    if(index == k)
    {
        print(sets, k);
        return;
    }

    if(indexA >= n || n-indexA < k-index)
        return;

    sets[index] = A[indexA];
    subsets(A, n, k, sets, index+1, indexA+1);
    subsets(A, n, k, sets, index, indexA+1);
}

int main()
{
    int A[] = {5,4,3,2,1};

    int n=5, k=1;

    int *sets = new int[k];

    subsets(A, n, k, sets, 0 , 0);

    delete[] sets;

    return 0;
}
