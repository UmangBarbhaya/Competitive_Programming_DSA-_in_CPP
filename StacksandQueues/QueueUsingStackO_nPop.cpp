/*
*/
#include<bits/stdc++.h>
using namespace std;
class Queue
{
stack<int> s1,s2;
public:
/*
s1 4 
s2 7 6 5
push 5
push 6
push 7
top()

*/
	void Push(int x)
	{
		s1.push(x);
	}
	int Pop()
	{
		if(s2.empty())
		{
			if(s1.empty())
			{
				cout<<"Empty stack"<<endl;
				exit(0);
			}
			while(s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
			int x = s2.top();
			s2.pop();
			return x;
	}
	int Top()
	{
		if(s2.empty())
		{
			if(s1.empty())
			{
				cout<<"Empty stack"<<endl;
				exit(0);
			}
			while(s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
			return s2.top();
	}
	int Size()
	{
		return s1.size()+s2.size();
	}
};
int main()
{
	Queue q;
	q.Push(10);
	q.Push(11);
	q.Push(12);
	cout<<q.Pop()<<endl;
	cout<<q.Top()<<endl;
	cout<<q.Size()<<endl;
	return 0;
}