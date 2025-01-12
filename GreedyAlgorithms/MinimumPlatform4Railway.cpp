/*input
6
0900 0940 0950 1100 1500 1800 
0910 1200 1120 1130 1900 2000
*/
#include<bits/stdc++.h>
using namespace std;
class MinimumPlatform4Railway
{
public:
	/*
	Brute force O(n^2)
	0900A, 0910D, 0940A, 0950A, 1100A, 1120D, 1130D, 1200D, 1500A, 1800A, 1900D, 2000D
	    1      0      1     2        3     2       1     0      1      2      0      0  

	    arrival++
	    departure--
	    Max(Count) = 3

	    3 platform needed
		O(2(nlogn + n))
		sorting twice.
		n+n for looping over both arrival and departure
	*/
	int countPlatformNum(int n, vector<int> arr, vector<int> dep)
	{
		if(n==0)
			return 0;
		int count = 0;
		int maxCount = 0;
		int p1 = 0;
		int p2 = 0;
		sort(arr.begin(), arr.end());
		sort(dep.begin(), dep.end());
		while(p1<n && p2<n)
		{
			if(arr[p1]<=dep[p2]) //same arr dep increment count
			{
				count++;
				p1++;
			}
			else
			{
				count--;
				p2++;
			}
			maxCount = max(count, maxCount);
		}
		return maxCount;
	}
};
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<int> dep(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>dep[i];
	}
	MinimumPlatform4Railway mObj;
	cout<<mObj.countPlatformNum(n, arr, dep)<<endl;

	return 0;
}