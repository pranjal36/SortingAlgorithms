#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
void BucketSort(float arr[], int n)
{
 
    vector<float> buck[n];

    for (int i = 0; i < n; i++) {
        int x = n * arr[i]; 
        buck[x].push_back(arr[i]);
    }
 
   
    for (int i = 0; i < n; i++)
        sort(buck[i].begin(), b[i].end());
 
    
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < buck[i].size(); j++)
            arr[index++] = buck[i][j];
}
 
int main()
{
   int n;
   cin>>n;
  float arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  
 
   BucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
