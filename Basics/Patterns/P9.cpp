/*input
5
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void printDiamond(int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				cout<<" ";
			}
			for(int j=0;j<=i;j++)
			{
				cout<<"* ";
			}
			cout<<endl;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				cout<<" ";
			}
			for(int j=0;j<n-i;j++)
			{
				cout<<"* ";
			}
			cout<<endl;
		}
	}
};
int main()
{
	int n;
	cin>>n;
	Solution obj;
	obj.printDiamond(n);
	return 0;
}