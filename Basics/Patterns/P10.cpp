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
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				cout<<"* ";
			}
			cout<<endl;
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
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
	obj.printTriangle(n);
	return 0;
}