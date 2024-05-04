#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high)
{
  int pivot=arr[high];
  int i=(low-1);
  
  for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

           
void quickSort(int arr[],int low,int high)
{
 
  if(low<high)
  {
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
             
 
int main() {
  int arr[] = {45, 21, 76, 39, 52, 18, 83, 65, 32, 49,
  11, 67, 27, 91, 54, 14, 78, 35, 73, 29,
  86, 42, 19, 63, 25, 97, 58, 12, 87, 46,
  31, 79, 17, 68, 24, 93, 57, 10, 85, 38 };
  int n=sizeof(arr)/sizeof(arr[0]);

   cout << "Given array is \n";
    printArray(arr, n);


  quickSort(arr,0,n-1);
 
  cout<<"Sorted Array\n";
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

