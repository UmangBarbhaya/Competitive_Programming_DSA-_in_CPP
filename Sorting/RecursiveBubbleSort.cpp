/*input
10
4 6634 -323 12 6 23 100 -22 -1 0
*/
#include<bits/stdc++.h>
using namespace std;
class RecursiveBubbleSort
{
public:
	void recursiveBubbleSort(vector<int> &arr, int n)
	{
		if(n<=0)
			return;
		
		for(int j=0;j<n;j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
		recursiveBubbleSort(arr,n-1);
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
	RecursiveBubbleSort rbsObj;
	rbsObj.recursiveBubbleSort(arr, n-1);
	print(arr);
	return 0;
}