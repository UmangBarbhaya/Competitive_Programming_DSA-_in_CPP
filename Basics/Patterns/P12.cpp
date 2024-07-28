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
				cout<<j+1<<" ";
			}
			for(int j=0;j<n-i-1;j++)
			{
				cout<<"    ";
			}
			for(int j=i;j>=0;j--)
			{
				cout<<j+1<<" ";
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