/*input
*/
#include<bits/stdc++.h>
using namespace std;
class Stack
{
/*
	front[1][][][]....back
	front[2][1][][]....back
	front[][][][]....back
	front[][][][]....back
*/
	queue<int> q;
public:
	void Push(int x)
	{
		int n = q.size();
		q.push(x);
		for(int i=0;i<n;i++)
		{
			q.push(q.front());
			q.pop();
		}
	}
	int Pop() 
	{
    	int n = q.front();
    	q.pop();
    	return n;
  	}
  	int Top() 
  	{
    	return q.front();
  	}
  	int Size() 
  	{
    	return q.size();
  	}
};
int main()
{
	Stack s;
	s.Push(10);
	s.Push(11);
	s.Push(12);
	cout<<s.Top()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Size()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Size()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Size()<<endl;
	return 0;
}
