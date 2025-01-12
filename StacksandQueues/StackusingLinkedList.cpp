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
class Stack
{

	Node* top;
	int Size;
public:
	Stack()
	{
		top=nullptr;
		Size=0;
	}

	void push(int x)
	{
		Node *temp = new Node(x);
		temp->next = top;
		top = temp;
		Size++;
	}
	int pop()
	{
		if(Size<=0)
			return 0;
		int x = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
		Size--;
		return x;
	}
	int topElem()
	{
		return top->data;
	}
	int size()
	{
		return Size+1;
	}
	bool isEmpty()
	{
		if(Size==0)
			return true;
		return false;
	}
};
int main()
{
	Stack s;
	s.push(10);
	s.push(11);
	cout<<s.topElem()<<endl;
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
	return 0;
}