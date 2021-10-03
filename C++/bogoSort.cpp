#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}
void bogosort(int a[], int n) {
    // Shuffle the array if it is not sorted.
    while (isSorted(a, n) == false) {
        random_shuffle(a, a + n);
    }
}

int main() {
    int a[] = {3, 7, 5, 2, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);

    bogosort(a, n);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    return 0;
}