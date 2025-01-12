/*input
*/
#include<bits/stdc++.h>
using namespace std;
class Stack
{
	/*
	2*val - prevmin = new val

	10 < 12
	val < prevmin
	val-prevmin<0
	val+val-prevmin<val
	2*val-prevmin<val
	*/
	stack <int> st;
	int min=INT_MAX;
	public:
	void Push(int x)
	{
		if(st.empty())
		{
			st.push(x);
			min = x;
		}
		else
		{
			if(x>min)
			{
				st.push(x);
			}
			else
			{
				st.push(2*x-min);
				min = x;
			}
		}
	}
	void Pop()
	{
		if(st.empty())
		{
			cout<<"Stack is empty"<<endl;
			return;
		}
		int temp = st.top();
		st.pop();
		if(temp<min)
		{
			min = 2*min-temp;
		}

	}
	int Top()
	{
		if(st.empty())
		{
			cout<<"Stack is empty"<<endl;
			return 0;
		}
		int temp = st.top();
		if(temp<min)
			return min;
		return temp;
		
	}
	int getMin()
	{
		return min;
	}

};
int main()
{
	Stack st;
	st.Push(13);
	cout<<st.Top()<<endl;
	st.Push(12);
	cout<<st.Top()<<endl;
	st.Pop();
	cout<<st.getMin()<<endl;
	st.Push(11);
	cout<<st.Top()<<endl;
	st.Push(10);
	cout<<st.getMin()<<endl;
	st.Pop();
	cout<<st.getMin()<<endl;
	return 0;
}