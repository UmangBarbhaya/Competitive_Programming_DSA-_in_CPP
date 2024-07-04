/*input
4
4 6
6 2 3 1
5 3
2 0 0 0 3
5 3
3 0 0 0 2
5 10
2 3 5 1 9
*/
#include<bits/stdc++.h>
using namespace std;
class LongestSubarrayWithGivenSumK
{
public:
	int bruteForceSolution(vector<int> arr, int k)
	{
		int n = arr.size();
		int maxanswer = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				int sum = 0;
				for(int k=i;k<=j;k++)
				{
					sum+=arr[k];
					
				}
				if(sum==k)
					{
						maxanswer = max(maxanswer,j-i+1);
					}
			}
		}
		return maxanswer;
	}
	int bruteForceSolutionBetter(vector<int> arr, int k)
	{
		int maxanswer = 0;
		for(int i=0;i<arr.size();i++)
		{
			int sum = 0;
			for(int j=i;j<arr.size();j++)
			{
				sum = sum + arr[j];
				if(sum==k)
				{
					maxanswer = max(maxanswer,j-i+1);
				}
			}	
		}
		return maxanswer;
	}
	int prefixSumHashing(vector <int> arr, long long k)
	{
		int maxanswer = 0;
		map<long long, int> prefixSumMap;
		long long sum=0;
		for(int i=0;i<arr.size();i++)
		{
			sum+=arr[i];
			if(sum==k)
			{
				maxanswer = max(maxanswer, i+1);
			}
			long long rem = sum - k;
			if(prefixSumMap.find(rem)!=prefixSumMap.end())
			{
				maxanswer = max(maxanswer,i-prefixSumMap[rem]);
			}
			//edgecase handling
			if(prefixSumMap.find(sum)==prefixSumMap.end())
			{
				prefixSumMap[sum] = i;
			}
		}
		return maxanswer;
	}
	int twoPointerOptimalApproach(vector<int> arr, long long k )
	{
		int maxanswer = 0;
		int j=0;
		int sum = 0;
		for(int i=0;i<arr.size();i++)
		{
			sum+=arr[i];
			while(sum > k && j<=i)
			{
				sum-=arr[j];
				j++;
			}
			if(sum == k)
			{
				maxanswer = max(maxanswer, i-j+1);
			}
			
		}
		return maxanswer;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t-- > 0)
	{
		cout<<"NEW TEST CASE"<<endl;
		int n,k;
		cin>>n;
		cin>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		LongestSubarrayWithGivenSumK ls_obj;
		cout<<"Brute Force Solution: "<<ls_obj.bruteForceSolution(arr,k)<<endl;
		cout<<"Better Brute Force Solution: "<<ls_obj.bruteForceSolutionBetter(arr,k)<<endl;
		cout<<"Prefix Sum Solution Hashing: "<<ls_obj.prefixSumHashing(arr,k)<<endl;
		cout<<"Optimal Approach using two pointer: "<<ls_obj.twoPointerOptimalApproach(arr,k)<<endl;

	}
	return 0;


}