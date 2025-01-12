/*input
5 2
1 2 3 4 5
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
		data=data1;
		next=nullptr;
	}
};
class ConvertArrayToLL
{
public:
	Node* convertArrayToLL(vector<int> arr, int n)
	{
		if(n==0)
			return nullptr;
		Node* head = new Node(arr[0]);
		Node* mover = head;
		for(int i=1;i<n;i++)
		{
			Node* temp = new Node(arr[i]);
			mover->next = temp;
			mover = mover->next;
		}
		return head;

	}
};
class RotateLL
{
	/*
	1 2 3 4 5
	4 5 1 2 3
	k = 2
	length = 5
	K=length-K
	K=3
	k-->0
	*/
public:
	Node* rotateLL(Node* head, int k)
	{
		int length=1;
		Node* temp = head;
		while(temp->next!=nullptr)
		{
			
			length++;
			temp=temp->next;
		}
		temp->next = head;
		temp = head;
		k = length-k;
		while(--k>0)
		{
			temp = temp->next;
		}
		head = temp->next;
		temp->next = nullptr;
		return head;
	}
};
void printLinkedList(Node* head)
{
	Node* temp = head;
	while(temp!=nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ConvertArrayToLL cObj;
	Node* head = cObj.convertArrayToLL(arr,n);
	RotateLL rObj;
	head = rObj.rotateLL(head, k);
	printLinkedList(head);
	return 0;
}
