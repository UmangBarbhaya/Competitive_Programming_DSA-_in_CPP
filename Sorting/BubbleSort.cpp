/*input
10
4 6634 -323 12 6 23 100 -22 -1 0
*/
#include<bits/stdc++.h>
using namespace std;
class BubbleSort
{
public:
	void bubbleSort(vector<int> &arr)
	{
		int n = arr.size();
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[j]>arr[j+1])
					swap(arr[j],arr[j+1]);
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
	BubbleSort bsObj;
	bsObj.bubbleSort(arr);
	print(arr);
	return 0;
}