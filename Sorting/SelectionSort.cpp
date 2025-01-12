/*input
10
4 6634 -323 12 6 23 100 -22 -1 0
*/
#include<bits/stdc++.h>
using namespace std;
class SelectionSort
{
public:
	void selectionSort(vector<int> &arr)
	{
		int n = arr.size();
		for(int i=0; i<n-1;i++)
		{
			int min=i;
			for(int j=i+1;j<n;j++)
			{
				if(arr[min]>arr[j])
					min=j;
			}
			swap(arr[i],arr[min]);
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
	SelectionSort ssObj;
	ssObj.selectionSort(arr);
	print(arr);
	return 0;
}
