/*input
10 50
1 2 3 4 5 6 7 8 9 10
*/
#include<bits/stdc++.h>
using namespace std;
class Searching
{
public:
	bool linearSearch(vector <int> arr, int k)
	{
		for(int i=0;i<arr.size();i++)
		{
			if(arr[i] == k)
			{
				return true;
			}
		}
		return false;
	}
	//only on sorted array
	bool binarySearch(vector <int> arr, int k)
	{
		int start = 0;
		int end = arr.size()-1;
		while(end>=start)
		{
			int mid = (end-start)/2+start;
			if(arr[mid] == k)
			{
				return true;
			}
			else if(arr[mid]<k)
			{
				start = mid+1;
			}
			else
				end = mid-1;

		}
		return false;
	}
	//only on sorted array
	bool binarySearchResursive(vector <int> arr, int k, int start, int end)
	{
		if(end<start)
			return false;
		int mid = (end-start)/2+start;
		if(arr[mid]==k)
			return true;
		if(arr[mid]<=k)
			return binarySearchResursive(arr,k,mid+1,end);
		return binarySearchResursive(arr,k,start,mid-1);
	}	
};
int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Searching s_obj;
	cout<<"Linear Search: "<< s_obj.linearSearch(arr, k)<<endl;
	cout<<"Binary Search Iterative: "<< s_obj.binarySearch(arr, k)<<endl;
	cout<<"Binary Search Recursive: "<< s_obj.binarySearchResursive(arr, k, 0, n-1)<<endl;
}






