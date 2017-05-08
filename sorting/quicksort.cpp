#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int kthsmallest(int arr[], int left, int right,int k) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }

      /* recursion */
      cout<<left<<" "<<right<<" "<<j<<" "<<i<<" "<<pivot<<"\n";
      if (i>=k && j<=k)
        return pivot;
      else if (k <= j && j > left)
          return kthsmallest(arr, left, j,k);
      else if (i < right)
           return kthsmallest(arr, i, right,k);
}

main()
{   int o;
    cout<< "enter no of elemaent in array";
    cin>>o;
    int a[o];
    for(int i=0; i<o; i++)cin>>a[i];
    cout<<kthsmallest(a,0,o-1,2)<<"\n";
    for(int i=0; i<o; i++)cout<<a[i]<<" ";

}
