/*input
9
1 2 3 4 5 6 7 8 9
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
	/*
	12 13
	12 13 14
	*/
	Node* deleteMiddleNodeLL(Node* head)
	{
		if(head == nullptr || head->next==nullptr)
			return nullptr;
		Node* fast = head->next->next;
		Node* slow=head;
		while(fast!=nullptr && fast->next!=nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		Node* delNode = slow->next;
		slow->next = slow->next->next;
		delete delNode;
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
	DeleteNthNodeLL dObj;
	Node* head = cObj.convertArrayToLL(arr, n);
	head = dObj.deleteMiddleNodeLL(head);
	printLinkedList(head);
	return 0;
}