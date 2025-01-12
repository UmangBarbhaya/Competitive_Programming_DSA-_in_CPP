/*input
*/
#include<bits/stdc++.h>
using namespace std;
class Queue
{
	int *arr;
	int front;
	int back;
	int Size;
	int currSize;
public:
	Queue()
	{
		Size = 100;
		arr = new int[Size];
		currSize = 0;
		front =-1 ;
		back = -1;
	}
	void push(int x)
	{
		if(Size==currSize)
		{
			cout<<"Stack Full"<<endl;
			return;
		}
		if(back ==-1)
		{
			front= 0;
			back=0;
		}
		else
		{
			back = (back+1)%Size;
		}
		arr[back]=x;
		currSize++;
	}
	int pop()
	{
		if(currSize==0)
		{
			cout<<"Queue empty"<<endl;
			return 0;
		}
		int temp = arr[front];
		
		currSize--;
		if(currSize==0)
		{
			front = -1;
			back = -1;
		}
		else
		{
			front = (front+1)%Size;
		}
		return temp;
	}
	int top()
	{
		if(currSize==0)
		{
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		return arr[front];
	}
	int size()
	{
		return currSize;
	}
	bool isEmpty()
	{
		if(currSize==0)
			return true;
		return false;
	}
};
int main()
{
	Queue q;
	q.push(10);
	q.push(11);
	q.push(12);
	cout<<q.top()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.size()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.isEmpty()<<endl;
	cout<<q.size()<<endl;
	cout<<q.pop()<<endl;

	return 0;
}