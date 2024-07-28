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
		char ch = 'A'+n-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				char tmp = ch-j;
				cout<<tmp<<" ";
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