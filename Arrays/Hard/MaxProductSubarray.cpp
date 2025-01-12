/*input
9
-2 3 4 -1 0 -2 3 1 4
*/
#include<bits/stdc++.h>
using namespace std;
class MaxProductSubarray
{
	public:
		int getMaxProductSubarray(vector<int>arr)
		{
			double pre = 1, suff = 1;
        double ans = LONG_MIN;
        for (int i = 0; i <  arr.size(); i++) {
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
            pre *= arr[i];
            suff *= arr[ arr.size() - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return (int)ans;
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
	MaxProductSubarray mpsObj;
	cout<<mpsObj.getMaxProductSubarray(arr)<<endl;
	return 0;
}