/*input
7
40 25 19 12 9 6 2
*/
#include<bits/stdc++.h>
using namespace std;
class CountReversePairs
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
	long long reversePairs(vector<int> arr, int low, int mid, int high)
	{	
		int cnt=0;
		long long j = mid+1;
		for(int i=low;i<=mid;i++)
		{
			while(j<=high)
			{
				if(arr[i]>2*arr[j])
				{
					j++;
				}
				else
					break;
			}
			cnt+=(j-(mid+1));       //for every pointer we are adding from start(0 or mid+1) till j index
		}
		return cnt;
	}
	long long mergeSort(vector<int> &arr, int low, int high)
	{
		long long cnt=0;
		if(low>=high)
			return cnt;
		int mid = (low+high)/2;
		cnt+=mergeSort(arr,low,mid);
		cnt+=mergeSort(arr,mid+1,high);
		cnt+=reversePairs(arr,low,mid,high);
		merge(arr,low,mid,high);
		return cnt;

	}
public:
	long long countReversePairs(vector<int> arr)
	{
		return mergeSort(arr, 0, arr.size()-1);
	}
};
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	CountReversePairs crpObj;
	cout<<crpObj.countReversePairs(arr)<<endl;
	return 0;
}