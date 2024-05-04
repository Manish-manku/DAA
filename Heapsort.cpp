#include <iostream>
using namespace std;


void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

  
    if (l < N && arr[l] > arr[largest])
        largest = l;

   
    if (r < N && arr[r] > arr[largest])
        largest = r;

   
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {62, 34, 77, 19, 93, 56, 23, 85, 40, 11,
    72, 29, 61, 15, 88, 48, 36, 78, 16, 94,
    45, 83, 25, 59, 37, 79, 13, 67, 30, 87,
    50, 24, 96, 6, 71, 33, 68, 17, 92, 52 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, N);

    heapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
}
