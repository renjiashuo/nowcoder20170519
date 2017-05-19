#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int left, int right);
void quickSort(vector<int> &arr, int left, int right);
void swap(vector<int> &arr, int left, int right);


int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int N = 3 * n;
		vector<int> num;
		for (int i = 0; i < N; ++i)
		{
			int temp = 0;
			cin >> temp;
			num.push_back(temp);
		}
		long long max = 0;
		//for (int i = 0; i < N - 1; i++)
		//{
		//	for (int j = i + 1; j < N; j++)
		//	{
		//		if (num[i] > num[j])
		//		{
		//			int temp = num[i];
		//			num[i] = num[j];
		//			num[j] = temp;
		//		}
		//	}
		//}
		quickSort(num, 0, N - 1);
		for (int i = N - 2; i >= n; i -= 2)
		{
			max += num[i];
		}
		cout << max;
	}

	return 0;
}

int partition(vector<int> &arr, int left, int right)
{
	int pivotKet = arr[left];
	int pivotPointer = left;
	while (left < right)
	{
		while (left < right && arr[right] >= pivotKet)
			right--;
		while (left < right && arr[left] <= pivotKet)
			left++;
		swap(arr, left, right);
	}
	swap(arr, pivotPointer, left);
	return left;
}

void quickSort(vector<int> &arr, int left, int right)
{
	if (left >= right)
		return;
	int pivotPos = partition(arr, left, right);
	quickSort(arr, left, pivotPos - 1);
	quickSort(arr, pivotPos + 1, right);
}

void swap(vector<int> &arr, int left, int right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}


// 5 2 8 5 1 5
// 1 2 5 5 5 8