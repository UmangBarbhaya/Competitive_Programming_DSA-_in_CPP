/*input
5
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void printTriangle(int n)
	{
		int val=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				cout<<val<<" ";
				val=(val+1)%2;
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
	obj.printTriangle(n);
	return 0;
}
