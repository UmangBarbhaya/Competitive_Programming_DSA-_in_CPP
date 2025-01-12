/*input
*/
#include<bits/stdc++.h>
using namespace std;
class Queue
{
	stack<int> s1,s2;
public:
	void Push(int x)
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	int Pop()
	{
		if(s1.empty())
		{
			cout<<"Stack is Empty"<<endl;
			exit(0);
		}
		int x = s1.top();
		s1.pop();
		return x;
	}
	int Top()
	{
		if(s1.empty())
		{
			cout<<"Stack is Empty"<<endl;
			exit(0);
		}
		return s1.top();
	}
	int Size()
	{
		return s1.size();
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