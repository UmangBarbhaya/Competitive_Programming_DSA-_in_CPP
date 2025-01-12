/*input
4
3 1 2 4
*/
#include<bits/stdc++.h>
using namespace std;
class SumofSubarrayMinimum
{
	vector<int> PSE(vector<int> arr, int n)
		{
			stack<int> st;
			vector<int> pse(n);
			for(int i=0;i<arr.size();i++)
			{
				while(!st.empty() && arr[st.top()]>arr[i])
				{
					st.pop();
				}
				if(st.empty())
				{
					pse[i] = -1;
				}
				else
				{
					pse[i] = st.top();
				}
				st.push(i);
			}
			return pse;
		}
		vector<int> NSE(vector<int> arr, int n)
		{
			vector<int> nse(n);
			stack <int> st;
			for(int i=n-1;i>=0;i--)
			{
				while(!st.empty() && arr[st.top()]>=arr[i])
				{
					st.pop();
				}
				if(st.empty())
				{
					nse[i]=n;
				}
				else
				{
					nse[i] = st.top();
				}
				st.push(i);
			}
			return nse;
		}
	public:
	long long getSumSubarrayMin(vector<int> arr)
	{
		int n =arr.size();
		vector<int> nse= NSE(arr,n);
		vector<int> pse = PSE(arr,n);
		long long total = 0;
		int mod = (int)(1e9+7);
		for(int i=0;i<n;i++)
		{
			int left = i-pse[i];
			int right = nse[i]-i;
			total = (total + (left*right*1LL*arr[i])%mod)%mod;
		}
		return total;
	}
};
int main()
{
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	SumofSubarrayMinimum sObj;
	cout<<sObj.getSumSubarrayMin(arr)<<endl;
	return 0;
}