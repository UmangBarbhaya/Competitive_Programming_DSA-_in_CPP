/*input
10
7 2 5 1 6 8 22 55 1 -45
*/
#include<bits/stdc++.h>
using namespace std;
class MergeSort
{

private:
	void merge(vector<int> &arr, int low, int mid, int high)
	{
		vector<int> temp;
		int left=low;
		int right=mid+1;
		while(left<=mid && right<=high)
		{
			if(arr[left]<=arr[right])
			{
				temp.push_back(arr[left]);
				left++;
			}
			else
			{
				temp.push_back(arr[right]);
				right++;
			}
		}
		while(left<=mid)
		{
			temp.push_back(arr[left]);
			left++;
		}	
		while(right<=high)
		{
			temp.push_back(arr[right]);
			right++;
		}
		for(int i=low;i<=high;i++)
		{
			arr[i] = temp[i-low];
		}
	}
public:
	void mergeSort(vector<int> &arr, int low, int high)
	{
		if(low>=high)
			return;
		int mid = (high+low)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
		return;
	}
};
void print(vector<int> arr)
{
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MergeSort msObj;
	msObj.mergeSort(arr, 0, n-1);
	print(arr);
	return 0;
}