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
class DeletionLinkedList
{
public:
	void deleteFirstNode(Node*& head)
	{
		if(head == nullptr)
			return;
		Node *temp = head;
		head = head->next;
		delete temp;
		
	}
	Node* deleteLastNode(Node* head)
	{
		Node* temp = head;
		if(head == nullptr)
			return head;
		if(head->next == nullptr)
		{
			free(head);
			return nullptr;
		}
		while(temp->next->next!=nullptr)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=nullptr;
		return head;
	}
	Node* deleteKthNode(Node* head, int k)
	{
		if(head==nullptr)
			return head;
		if(k==1)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return head;
		}
		int cnt=0;
		Node* temp=head;
		Node* prev = nullptr;
		while(temp!=nullptr)
		{
			cnt++;
			if(cnt==k)
			{
				prev->next=prev->next->next;
				delete temp;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		return head;
	}
	void deleteGivenNode(Node* node)
	{
		if(node->next==nullptr)
		{
			delete node;
			node = nullptr;
			return;
		}
		Node* temp = node->next;
		node->data =node->next->data;
		node->next = node->next->next;
		delete temp;
	}
	Node* deleteElement(Node* head, int element)
	{
		if(head==nullptr)
			return head;
		if(head->data==element)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return head;
		}
		Node* temp=head;
		Node* prev = nullptr;
		while(temp!=nullptr)
		{
			if(temp->data == element)
			{
				prev->next=prev->next->next;
				delete temp;
				break;
			}
			prev = temp;
			temp = temp->next;
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
	Node* head = calObj.convertArrayToLL(arr, n);
	DeletionLinkedList dObj;
	dObj.deleteFirstNode(head);
	printLinkedList(head);

	head = calObj.convertArrayToLL(arr, n);
	head = dObj.deleteLastNode(head);
	printLinkedList(head);

	head = calObj.convertArrayToLL(arr, n);
	head = dObj.deleteKthNode(head, 3);
	printLinkedList(head);

	head = calObj.convertArrayToLL(arr, n);
	dObj.deleteGivenNode(head->next);
	printLinkedList(head);

	head = calObj.convertArrayToLL(arr, n);
	head = dObj.deleteElement(head, 1);
	printLinkedList(head);
	return 0;
}