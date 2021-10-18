// C implementation of Sleep Sort

#include <stdio.h>
#include <windows.h>
#include <process.h>

void routine(void *a)
{
	int n = *(int *) a; 
	Sleep(n);
	printf("%d ", n);    // After the sleep, print the number
}

void sleepSort(int arr[], int n)
{
	HANDLE threads[n];
	for (int i = 0; i < n; i++)
		threads[i] = (HANDLE)_beginthread(&routine, 0, &arr[i]);

	WaitForMultipleObjects(n, threads, TRUE, INFINITE);
	return;
}

int main()
{
	int arr[] = {555, 32, 7, 888,37,2,52};
	int n = sizeof(arr) / sizeof(arr[0]);
	sleepSort (arr, n);
	return(0);
}
