/*input
10
4 6634 -323 12 6 23 100 -22 -1 0
*/
#include<bits/stdc++.h>
using namespace std;
class InsertionSort
{
public:
	void insertionSort(vector<int> &arr)
	{
		int n = arr.size();
		for(int i=0;i<n-1;i++) //sorted part of the array
		{
			for(int j=i;j>=0;j--)
			{
				if(arr[j+1]<arr[j]) //j+1 is new element, insert it in proper place at sorted part
					swap(arr[j+1], arr[j]);
			}
		}
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
	InsertionSort isObj;
	isObj.insertionSort(arr);
	print(arr);
	return 0;
}