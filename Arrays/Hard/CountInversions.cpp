/*input
5
5 3 2 1 4
*/
#include<bits/stdc++.h>
using namespace std;
class CountInversions
{
	private:
		int merge(vector<int> &arr, int low, int mid, int high)
		{
			int cnt=0;
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
					cnt+=mid-left+1;
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
			return cnt;
		}
		int mergeSort(vector<int> &arr,int low, int high)
		{
			int cnt=0;
			if(low>=high)
				return cnt;
			int mid = (low+high)/2;
			cnt+=mergeSort(arr,low,mid);
			cnt+=mergeSort(arr,mid+1,high);
			cnt+=merge(arr,low,mid,high);
			return cnt;
		}
	public:
		int countInversions(vector <int> arr)
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
	CountInversions ciObj;
	cout<<ciObj.countInversions(arr);
	return 0;
}