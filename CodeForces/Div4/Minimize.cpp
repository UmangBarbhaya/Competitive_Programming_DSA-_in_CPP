/*input
3
1 2
3 10
5 5
*/
#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a;
		cin>>b;
		cout<<b-a<<endl;
	}
	return 0;
}