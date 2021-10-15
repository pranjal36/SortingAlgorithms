#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

//-----------------------------------------------------------------------------------------------------------------------

template <typename T>
void selection_sort(T arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }

        // swap i and min_ind
        swap<T>(&arr[i], &arr[min_ind]);
    }
}

//-----------------------------------------------------------------------------------------------------------------------

template <typename T>
void insertion_sort(T arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        T new_ele = arr[i];
        for (int j = i - 1; j >= 0 && arr[j] > new_ele; j--)
        {
            arr[j + 1] = arr[j];
            arr[j] = new_ele;
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------

template <typename T>
void bubble_sort(T arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap<T>(&arr[j], &arr[j + 1]);
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------

template <typename T>
void shell_sort(T arr[], int n)
{
    int gap = 1;
    while ((gap * 3 + 1) < n)
    {
        gap = gap * 3 + 1;
    }
    for (; gap > 0; gap = (gap - 1) / 3)
    {

        for (int i = gap; i < n; i++)
        {

            T temp = arr[i];
            for (int j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------

template <typename T>
void merge(T arr[], int l, int r, int m)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 || j < n2)
    {
        if (j == n2 || (i < n1 && L[i] < R[j]))
        {
            arr[k] = L[i];
            i++;
        }

        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
}

template <typename T>
void merge_sort(T arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        merge_sort<T>(arr, l, m);
        merge_sort<T>(arr, m + 1, r);

        merge<T>(arr, l, r, m);
    }
}

//-----------------------------------------------------------------------------------------------------------------------

// insertion sort in a section of array used in quick sort
template <typename T>
void insertion_sort(T arr[], int l, int r)
{
    for (int i = l + 1; i < r + 1; i++)
    {
        T new_ele = arr[i];
        for (int j = i - 1; j >= l && arr[j] > new_ele; j--)
        {
            arr[j + 1] = arr[j];
            arr[j] = new_ele;
        }
    }
}

template <typename T>
const T &median(T arr[], int l, int r)
{

    int mid = (l + r) / 2;

    if (arr[mid] < arr[l])
    {
        swap<T>(&arr[l], &arr[mid]);
    }

    if (arr[r] < arr[l])
    {
        swap<T>(&arr[l], &arr[r]);
    }

    if (arr[r] < arr[mid])
    {
        swap<T>(&arr[r], &arr[mid]);
    }
    swap<T>(&arr[mid], &arr[r - 1]);
    return arr[r - 1];
}

template <typename T>
void quick_sort(T arr[], int l, int r)
{

    if (l + 10 <= r)
    {
        T pivot = median<T>(arr, l, r);

        int i = l, j = r - 1;
        for (;;)
        {
            while (arr[++i] < pivot)
            {
            }
            while (arr[--j] > pivot)
            {
            }

            if (i < j)
            {
                swap<T>(&arr[i], &arr[j]);
            }
            else
            {
                break;
            }
        }

        swap<T>(&arr[i], &arr[r - 1]);

        quick_sort<T>(arr, l, i - 1);
        quick_sort<T>(arr, i + 1, r);
    }
    else
    {
        insertion_sort<T>(arr, l, r);
    }
}

//-----------------------------------------------------------------------------------------------------------------------

template <typename T>
void perc_down(T arr[], int i, int n)
{
    T prev;
    int child;
    auto left_child = [](int i)

    { return i * 2 + 1; };

    for (prev = arr[i]; left_child(i) < n; i = child)
    {
        child = left_child(i);

        if (child != n - 1 && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (prev < arr[child])
        {
            arr[i] = arr[child];
        }

        else
        {
            break;
        }
    }

    arr[i] = prev;
}

template <typename T>
void heap_sort(T arr[], int n)
{

    for (int i = n / 2; i >= 0; i--)
    {
        perc_down(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap<T>(&arr[0], &arr[i]);
        perc_down(arr, 0, i);
    }
}

//-----------------------------------------------------------------------------------------------------------------------