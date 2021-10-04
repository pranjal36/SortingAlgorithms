#include<bits/stdc++.h>
using namespace std;
 
int getGap(int gap)
{
   
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}
 

void combSort(int a[], int n)
{
 
    int gap = n;
    bool swapped = true;
 
    
    while (gap != 1 || swapped == true)
    {
        gap = getGap(gap);
 
      
        swapped = false;
 
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
 
    combSort(arr, n);
 
    printf("Sorted array: \n");
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
 
    return 0;
}
