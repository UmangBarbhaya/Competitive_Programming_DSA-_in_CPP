/*input
*/
#include<bits/stdc++.h>
using namespace std;
class LinkedListBasic
{

};
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
	Node(int data1, Node* next1)
	{
		data = data1;
		next = next1;
	}
};
int main()
{
	//pointer Basics x = *y, &x = y
	int x = 2;
	int *y = &x;
	cout<<x<<endl;
	cout<<*y<<endl;
	cout<<&x<<endl;
	cout<<y<<endl;
	cout<<&y<<endl;
	int *z = y;
	cout<<z;
	//Linked List Pointer Basic
	cout<<"LinkedListBasic"<<endl;
	vector<int> arr = {2,3,4,5};
	Node head =  Node(arr[0]);
	cout<<head.data<<endl;
	cout<<head.next<<endl;

	Node *ListPointer = new Node(arr[0]);
	cout<<ListPointer->data<<endl;//ListPointer.data will fail
	cout<<ListPointer->next<<endl;
	cout<<(*ListPointer).data<<endl;
	return 0;
}
