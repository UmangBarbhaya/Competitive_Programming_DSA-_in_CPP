/*input
2
6
9 -3 3 -1 6 -5
5
2 0 0 0 5
*/
#include<bits/stdc++.h>
using namespace std;
class LongestSubarrayWithSum0
{
	public:
	int bruteForceLSWS0(vector<int> arr)
	{
		int maxLength = INT_MIN;
		int n = arr.size();
		for(int i=0;i<n;i++)
		{
			int sum=0;
			for(int j=i;j<n;j++)
			{
				sum+=arr[j];
				if(sum==0)
				{
					maxLength = max(maxLength, j-i+1);
				}
			}
		}
		return maxLength;
	}
	int optimalLSWS0(vector<int> arr)
	{
		int n = arr.size();
		int maxLength=0;
		map <int,int> mpp;
		
		int presum=0;
		for(int i=0;i<n;i++)
		{
			presum+=arr[i];
			if(presum==0)
			{
				maxLength = max(maxLength, i+1);
			}
			if(mpp.find(presum)!=mpp.end())
			{
				maxLength = max(maxLength, i-mpp[presum]);
			}
			else	
				mpp[presum] = i;
		}
		return maxLength;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cout<<"Test case"<<endl;
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		LongestSubarrayWithSum0 lsObj;
		cout<<"BruteForce Approach"<<endl;
		int x = lsObj.bruteForceLSWS0(arr);
		cout<<x<<endl;
		cout<<"Optimal Approach"<<endl;
		cout<<lsObj.optimalLSWS0(arr)<<endl;
	}
	return 0;
}