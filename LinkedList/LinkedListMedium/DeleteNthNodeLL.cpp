/*input
10
1 2 3 4 5 6 7 8 9 10
5
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
class ConvertArrayToLinkedList
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
class DeleteNthNodeLL
{
public:
	Node* deleteNthNodeLL(Node* head, int N)
	{
		if(N==0)
			return head;
		Node* first = head;
		Node* second = head;
		for(int i=0;i<N;i++)
		{
			first = first->next;
		}
		/* 
		1 2 3 nullptr n = 3
		first = 1
		first = 2
		first = 3
		first = nullptr
		so head needs to be replaced
		*/
		if(first == nullptr)
		{
			Node* temp = head;
			head=head->next;
			delete temp;
			return head;
		}
		/*
		1 2 3 4 5 6 7 8 9 10
		N=5, to delete 6
		first -> 6 
		go till the first points 10 and not nullptr
		*/
		while(first->next!=nullptr)
		{
			first = first->next;
			second = second->next;
		}
		Node* temp = second->next;
		second->next = second->next->next;
		delete temp;
		return head;
	}
};
void printLinkedList(Node *head)
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
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int N;
	cin>>N;
	ConvertArrayToLinkedList cObj;
	DeleteNthNodeLL dObj;
	Node* head = cObj.convertArrayToLL(arr, n);
	head = dObj.deleteNthNodeLL(head, N);
	printLinkedList(head);
	return 0;
}