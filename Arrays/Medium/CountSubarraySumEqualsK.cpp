/*input
10 3
1 2 3 -3 1 1 1 4 2 -3
*/
#include<bits/stdc++.h>
using namespace std;
class CountSubarraySumEqualsK
{
public:
	int getSubarraySumEqualSK(vector <int> arr, int k)
	{
		int preSum=0, answerCount=0;
		map<int,int> mpp;
		mpp[0] = 1;
		for(int i=0;i<arr.size();i++)
		{
			preSum+=arr[i];
			int rem = preSum-k;
			answerCount+=mpp[rem];
			mpp[preSum]+=1;
		}
		return answerCount;
	}
};
int main()
{
	int n, k;
	cin>>n;
	cin>>k;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	} 
	CountSubarraySumEqualsK cssekObj;
	cout<<cssekObj.getSubarraySumEqualSK(arr, k)<<endl;
	return 0;
}