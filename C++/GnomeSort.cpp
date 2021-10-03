#include <iostream>
using namespace std;

void gnomeSort(int arr[], int n)
{
    int i = 0;

    while (i < n)
    {
        if (i == 0)
            i++;

        if (arr[i] >= arr[i - 1])
            i++;
        else
        {
            swap(arr[i], arr[i - 1]);
            i--;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    gnomeSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << "\n";

    return (0);
}