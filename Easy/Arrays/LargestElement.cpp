/*input
5
10 20 30 40 90
*/
#include<bits/stdc++.h>
using namespace std;

class FindElements
{
	public:
		int largestElement(vector<int> &arr, int n)
		{
			if(n==0)
				return 0;
			int answer = INT_MIN;
			for(int i=0;i<n;i++)
			{
				if(arr[i]>answer)
					answer = arr[i];
			}
			return answer;
		}
};
int main()
{
	int n;
	cin>> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	FindElements fe_o;
	cout<<fe_o.largestElement(arr,n);
	return 0;
}