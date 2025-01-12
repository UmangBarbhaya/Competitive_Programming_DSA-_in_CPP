/*input
10
4 6634 -323 12 6 23 100 -22 -1 0
*/
#include<bits/stdc++.h>
using namespace std;
class QuickSort
{
public:
	int partition(vector<int> &arr, int low, int high)
	{
		int i=low;
		int j=high;
		int pivot = arr[low];
		while(i<j)
		{
			while(arr[i]<=pivot && i<high)
				i++;
			while(arr[j]>pivot && j>low)
				j--;
			
			if(i<j)
				swap(arr[i], arr[j]);
		}
		swap(arr[low], arr[j]);
		return j;
	}
	void quickSort(vector<int> &arr, int low, int high)
	{
		if(low>=high)
			return;
		int pivotIndex = partition(arr, low, high);
		quickSort(arr, low, pivotIndex-1);
		quickSort(arr, pivotIndex+1,high);
	}
};
void print(vector<int> arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	QuickSort qsObj;
	qsObj.quickSort(arr, 0, n-1);
	print(arr);
	return 0;
}