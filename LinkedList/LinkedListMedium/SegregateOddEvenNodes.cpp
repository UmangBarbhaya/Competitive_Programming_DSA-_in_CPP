/*input
11
10 20 30 40 50 60 70 80 90 100 110
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
/*

*/
class SegregateOddEvenNodes
{
public:
	Node* segregateOddEvenNodes(Node* head)
	{
		if(head==nullptr || head->next==nullptr)
			return head;
		Node* odd = head;
		Node* even = head->next;
		Node* evenHead = even;
		while(odd->next!=nullptr && even->next!=nullptr)
		{
			odd->next = odd->next->next;
			even->next = even->next->next;
			odd = odd->next;
			even = even->next;
		}
		odd->next = evenHead;
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
	ConvertArrayToLinkedList cObj;
	SegregateOddEvenNodes sObj;
	Node* head = cObj.convertArrayToLL(arr, n);
	head = sObj.segregateOddEvenNodes(head);
	printLinkedList(head);
}