/*input
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int data1)
	{
		data = data1;
		next = nullptr;
	}
};
class Queue
{
	Node* front;
	Node* back;
	int currSize;
public:
	Queue()
	{
		front=nullptr;
		back=nullptr;
		currSize = 0;
	}
	/*1(front)->2-3(back)->null*/
	void push(int x)
	{
		Node* temp = new Node(x);
		if(currSize==0)
		{
			front = temp;
			back = temp;
		}
		else
		{
			back->next = temp;
			back = temp;
		}
		currSize++;
	}
	int pop()
	{
		if(currSize==0)
		{
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		else
		{
			Node* temp = front;
			front = front->next;
			int x = temp->data;
			delete temp;
			currSize--;
			return x;
		}
	}
	int top()
	{
		if(currSize==0)
		{
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		return front->data;
	}
	int size()
	{
		return currSize;
	}
	bool isEmpty()
	{
		if(currSize==0)
			return true;
		return	false;
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