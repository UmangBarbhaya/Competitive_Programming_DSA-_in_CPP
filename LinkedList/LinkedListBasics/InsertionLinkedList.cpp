/*input
10
132 12 2 65 1 2 3 56 2 1
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data1)
	{
		data = data1;
		next = nullptr;
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
			Node *temp = new Node(arr[i]);
			mover->next = temp;
			mover=mover->next;
		}
		return head;
	}
};
class InsertionLinkedList
{
public:
	Node* insertHead(Node* head, int element)
	{
		Node* temp = new Node(element);
		temp->next = head;
		return temp;
	}
	Node* insertTail(Node* head, int element)
	{

		Node* newNode = new Node(element);
		if(head==nullptr)
			return newNode;
		Node* temp = head;
		while(temp->next!=nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		return head;
	}
	Node* insertAtKthPosition(Node* head, int element, int k)
	{
		Node* newNode = new Node(element);
		if(head==nullptr)
		{
			if(k==1)
				return newNode;
			return head;
		}
		if(k==1)
		{
			newNode->next = head;
			return newNode;
		}
		int cnt=0;
		Node* temp = head;
		while(temp!=nullptr)
		{
			cnt++;
			if(cnt==k-1)
			{
				newNode->next = temp->next;
				temp->next = newNode;
				break;
			}
			temp = temp->next;
		}
		return head;

	}
	Node* insertBeforeValueX(Node* head, int element, int x)
	{
		Node* newNode = new Node(element);
		if(head==nullptr)
			return nullptr;
		if(head->data == x)
		{
			newNode->next = head;
			return newNode;
		}
		Node* temp = head;
		while(temp->next!=nullptr)
		{
			if(temp->next->data == x)
			{
				newNode->next = temp->next;
				temp->next=newNode;
				break;
			}
			temp=temp->next;
		}
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
	ConvertArrayToLL calObj;
	InsertionLinkedList iObj;

	Node* head = calObj.convertArrayToLL(arr, n);
	head = iObj.insertHead(head,100);
	printLinkedList(head);

	head = calObj.convertArrayToLL(arr, n);
	head = iObj.insertTail(head,100);
	printLinkedList(head);

	head = calObj.convertArrayToLL(arr, n);
	head = iObj.insertAtKthPosition(head,100, 6);
	printLinkedList(head);

	head = calObj.convertArrayToLL(arr, n);
	head = iObj.insertBeforeValueX(head,100, 65);
	printLinkedList(head);
	return 0;
}