/*input
6
50 50 30 20 10 50
*/
#include<bits/stdc++.h>
using namespace std;
class FindElements
{
	public:
		int secondLargestElement(vector <int> &arr, int n)
		{
			int max1 = INT_MIN;
			int max2 = INT_MIN;
			if(n==0 || n==1)
				return -1;
			for(int i=0;i<n;i++)
			{
				if(max1<arr[i])
				{
					max2 = max1;
					max1=arr[i];
				}
				else if(max2<arr[i] && max1!=arr[i])
				{
					max2 = arr[i];
				}
			}
			if(max2 == INT_MIN)
				return -1;
			return max2;
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
	FindElements fe_obj;
	cout<<fe_obj.secondLargestElement(arr, n);
}