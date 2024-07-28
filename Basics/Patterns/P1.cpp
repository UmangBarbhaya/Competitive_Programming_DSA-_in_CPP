/*input
5
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void printSquare(int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<< "* ";
			}
			cout<<"\n";
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