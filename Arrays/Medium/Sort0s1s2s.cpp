/*input
1
20
0 1 2 2 1 0 0 2 1 2 2 2 1 1 0 0 0 1 1 2
*/
#include<bits/stdc++.h>
using namespace std;
class Sort0s1s2s
{
public:
	void frequencySort(vector<int> &arr, int n)
	{
		int count0 = 0, count1=0, count2 = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				count0++;
			}
			else if(arr[i]==1)
			{
				count1++;
			}
			else
				count2++;
		}
		for(int i=0;i<count0;i++) arr[i]=0;
			for(int i=count0;i<count0+count1;i++) arr[i]=1;
				for(int i=count0+count1;i<n;i++) arr[i]=2;
	}
	void dutchFlag3Pointers(vector<int> &arr, int n)
	{
		int low = 0, mid = 0, high = n-1;
		while(mid<=high)
		{
			if(arr[mid]==0)
			{
				swap(arr, low, mid);
				low++;
				mid++;
			}
			else if(arr[mid]==1)
			{
				mid++;
			}
			else
			{
				swap(arr,mid,high);
				high--;
			}

		}
	}
	void swap(vector<int> &arr, int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
};
void print(vector <int> arr, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		} 
		Sort0s1s2s s_obj;
		vector <int> arr1 = arr;
		s_obj.frequencySort(arr, n);
		print(arr,n);
		s_obj.dutchFlag3Pointers(arr1,n);
		print(arr1,n);
	}
	return 0;
}