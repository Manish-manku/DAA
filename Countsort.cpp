#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& inputArray)
{

	int N = inputArray.size();
	int M = 0;

	for (int i = 0; i < N; i++)
		M = max(M, inputArray[i]);

	
	vector<int> countArray(M + 1, 0);


	for (int i = 0; i < N; i++)
		countArray[inputArray[i]]++;

	for (int i = 1; i <= M; i++)
		countArray[i] += countArray[i - 1];

	vector<int> outputArray(N);

	for (int i = N - 1; i >= 0; i--)

	{
		outputArray[countArray[inputArray[i]] - 1]
			= inputArray[i];

		countArray[inputArray[i]]--;
	}

	return outputArray;
}

int main()

{

	vector<int> inputArray = {88, 5, 72, 17, 54, 31, 96, 20, 65, 43,
	12, 78, 29, 60, 38, 84, 16, 75, 50, 27,
	91, 47, 68, 23, 57, 34, 82, 10, 69, 45,
	22, 80, 36, 73, 49, 14, 93, 6, 61, 30 };
    int arr_size = inputArray.size();

    cout<<("Given array:\n");
    for (int i = 0; i < arr_size; i++)
        cout << inputArray[i] << " ";
    cout << endl;

	vector<int> outputArray = countSort(inputArray);

    cout<<("Sorted array:\n");
	for (int i = 0; i < inputArray.size(); i++)
		cout << outputArray[i] << " ";

	return 0;
}
