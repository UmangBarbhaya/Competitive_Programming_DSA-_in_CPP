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
				for(int j=0;j<n-i-1;j++)
				{
					cout<<" ";
				}
				char ch='A';
				for(int j=0;j<=i;j++)
				{
					char tmp = ch+j;
					cout<<tmp;
				}
				ch = 'A';
				for(int j=i-1;j>=0;j--)
				{
					char tmp = ch+j;
					cout<<tmp;
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