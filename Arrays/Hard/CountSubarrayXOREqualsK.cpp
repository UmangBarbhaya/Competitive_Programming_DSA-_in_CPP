/*input
2
5 6
4 2 2 6 4
5 5
5 6 7 8 9
*/
#include<bits/stdc++.h>
using namespace std;
class CountSubarrayXOREqualsK
{
	public:
		int bruteforceFindCSXEK(vector<int> arr,int K)
		{
			int n = arr.size();
			int count=0;
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					int xorvalue=0;
					for(int l=i;l<=j;l++)
					{
						xorvalue^=arr[l];

					}
					if(xorvalue==K)
					{
						count++;
					}
				}
			}
			return count;
		}
		int betterFindCSXEK(vector<int> arr,int K)
		{
			int n = arr.size();
			int count=0;
			for(int i=0;i<n;i++)
			{
				int xorvalue=0;
				for(int j=i;j<n;j++)
				{
					xorvalue^=arr[j];
					if(xorvalue==K)
					{
						count++;
					}
				}
			}
			return count;
		}
		int optimalFindCSXEK(vector<int> arr,int K)
		{
			int n = arr.size();
			int count=0;
			map<int,int> mpp;
			mpp[0]=1;
			int preXOR=0;
			for(int i=0;i<n;i++)
			{
				preXOR^=arr[i];
				int remXOR = preXOR^K;
				count+=mpp[remXOR];
				mpp[preXOR]++;
			}
			return count;
		}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cout<<"Test Case"<<endl;
		int n,k;
		cin>>n;
		cin>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		CountSubarrayXOREqualsK cskObj;
		cout<<"Brute Force Approach:"<<endl;
		cout<<cskObj.bruteforceFindCSXEK(arr,k)<<endl;
		cout<<"Better Approach:"<<endl;
		cout<<cskObj.betterFindCSXEK(arr,k)<<endl;
		cout<<"Optimal Approach:"<<endl;
		cout<<cskObj.optimalFindCSXEK(arr,k)<<endl;
	}
	return 0;
}