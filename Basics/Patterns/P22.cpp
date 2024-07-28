/*input
4
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void printSquare(int n)
	{
		for(int i=0;i<2*n-1;i++)
		{
			for(int j=0;j<2*n-1;j++)
			{
				int left=j;
				int right=(2*n-2)-j;
				int top=i;
				int down=(2*n-2)-i;
				cout<<n-min(min(left,right),min(top,down))<<" ";
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
	obj.printSquare(n);
	return 0;
}