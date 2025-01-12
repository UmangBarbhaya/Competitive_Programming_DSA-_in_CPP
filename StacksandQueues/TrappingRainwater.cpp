/*input
12
0 1 0 2 1 0 1 3 2 1 2 1
*/
#include<bits/stdc++.h>
using namespace std;
class TrappingRainWater
{
	/* Brute Force
		find the prefix max arr and suffix max arr
		then apply below formula
		leftmax = prefixmax[i]
		rightmax = suffixmax[i]
		total = total + min(leftmax, rightmax) - arr[i]
	 * 
	 * */
public:
	long long findTotalWaterArea(vector<int> arr)
	{
		int l = 0;
		int r = arr.size()-1;
		int leftMax = 0;
		int rightMax = 0;
		long long total =0;
		while(l<r)
		{
			if(arr[l]<=arr[r])
			{
				if(arr[l]<leftMax)
				{
					total+=leftMax-arr[l];
				}
				else
				{
					leftMax=arr[l];
				}
				l++;
			}
			else if(arr[l]>arr[r])
			{
				if(arr[r]<rightMax)
				{
					total+=rightMax-arr[r];
				}
				else
				{
					rightMax = arr[r];
				}
				r--;
			}
		}
		return total;
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
	TrappingRainWater tObj;
	cout<<tObj.findTotalWaterArea(arr)<<endl;
	return 0;
}