#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {36, 81, 57, 25, 69, 42, 17, 53, 78, 30,
    92, 63, 18, 45, 71, 29, 86, 11, 65, 24,
    78, 36, 95, 20, 64, 38, 12, 84, 49, 23,
    77, 47, 15, 58, 32, 89, 56, 27, 70, 4 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, N);

    insertionSort(arr, N);
    cout << "Sorted array is \n";
    printArray(arr, N);

    return 0;
}

