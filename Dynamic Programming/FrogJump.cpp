/*input
6
30 10 60 10 60 50
*/
#include<bits/stdc++.h>
using namespace std;
class FrogJump
{
/*
													6
							5												4
			4							3
	3 				2
2		1

1	0	0	


*/
private:
	int getMinEnergyReqd(vector<int> height, int n, vector<int> &dp)
	{
		if(n==0)
			return 0;
		if(dp[n]!=-1)
			return dp[n];
		int twoStep = INT_MAX;
		int oneStep = getMinEnergyReqd(height,n-1, dp)+abs(height[n]-height[n-1]);
		if(n>1)
			twoStep = getMinEnergyReqd(height,n-2, dp)+abs(height[n]-height[n-2]);
		dp[n] = min(oneStep, twoStep);
		return dp[n];

	}
public:
	int getMinEnergyReqd(vector<int> height)
	{
		vector<int> dp(height.size()+1, -1);
		int minEnergy=getMinEnergyReqd(height,height.size()-1,dp);

		return minEnergy;
	}
};
int main()
{
	int n ;
	cin>>n;
	vector<int> height(n);
	for(int i=0;i<n;i++)
	{
		cin>>height[i];
	}
	FrogJump fobj;
	cout<<fobj.getMinEnergyReqd(height);
	return 0;
}
