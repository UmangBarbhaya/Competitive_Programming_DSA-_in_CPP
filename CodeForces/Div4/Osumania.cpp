/*input
3
4
#...
.#..
..#.
...#
2
.#..
.#..
1
...#

*/
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		stack<int> s;
		while(n--)
		{
			char ch;
			for(int i=1;i<=4;i++)
			{
				cin>>ch;
				if(ch=='#')
				{
					s.push(i);
					continue;
				}
			}
		}
		while(!s.empty())
		{
			cout<<s.top()<<" ";
			s.pop();
		}
		cout<<endl;
	}
}