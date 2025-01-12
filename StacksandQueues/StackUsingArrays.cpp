/*input
*/
#include<bits/stdc++.h>
using namespace std;
class Stack
{
private:
	int arr[100];
	int topp=0;
public:
	void push(int x)
	{
		topp++;
		arr[topp] = x;
	}
	int pop()
	{
		int x = arr[topp];
		topp--;
		return x;
	}
	int size()
	{
		return topp+1;
	}
	int top()
	{
		return arr[topp];
	}
	bool isEmpty()
	{
		if(topp==0)
			return true;
		return false;
	}
};
int main()
{
	Stack s;
	s.push(10);
	s.push(11);
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
	return 0;
}