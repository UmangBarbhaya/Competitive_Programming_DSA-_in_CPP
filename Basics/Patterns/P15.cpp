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
			char ch = 'A';
			for(int j=0;j<n-i;j++)
			{
				cout<<ch;
				ch++;
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