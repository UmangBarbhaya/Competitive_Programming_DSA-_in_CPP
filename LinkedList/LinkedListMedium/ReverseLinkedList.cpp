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
	Node* convertArrayToLinkedList(vector <int> arr, int n)
	{
		if(n==0)
			return nullptr;
		Node* head = new Node(arr[0]);
		Node* mover=head;
		for(int i=1;i<n;i++)
		{
			Node* newNode = new Node(arr[i]);
			mover->next = newNode;
			mover = mover->next;
		}
		return head;
	}
};
class LinkedListReversal
{
public:
	Node* reverseStack(Node* head)
	{
		stack<int> s;
		Node* temp = head;
		while(temp!=nullptr)
		{
			s.push(temp->data);
			temp=temp->next;
		}
		temp = head;
		while(temp!=nullptr)
		{
			temp->data = s.top();
			s.pop();
			temp=temp->next;
		}
		return head;
	}
	/*DryRun
		1->3->2->5->x
		divide into smaller subproblems
		1->3->2->5->x    x<-1<-3<-2<-5
	       3->2->5->x    x<-3<-2
		      2->5->x    x<-2<-5
		         5->x   // base condition
        
          final LL 1->3->2->5->x   x            head 5
		  final LL 1->3->2->5->x   5->x         head 2	front = 5
		  final LL 1->3->2->x   5->2->x         head 3 	front = 2
		  final LL 1->3->x   5->2->3->x         head 1  front = 3
		  final LL 1->x   5->2->3->1->x         head nullptr
	*/
	Node* reverseRecursion(Node* head)
	{
		if(head==nullptr || head->next ==nullptr)
			return head;
		Node* newNode = reverseRecursion(head->next);
		Node* front = head->next;
		front->next = head;
		head->next = nullptr;
		return newNode;
	}
	Node* reversePointer(Node* head)
	{
		if(head==nullptr)
			return head;
		Node* prev = nullptr;
		Node* temp = head;
		while(temp!=nullptr)
		{
			Node* front = temp->next;
			temp->next=prev;
			prev = temp;
			temp = front;
			
		}
		return prev;
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
	LinkedListReversal rObj;
	Node* head = cObj.convertArrayToLinkedList(arr, n);
	head = rObj.reverseStack(head);
	printLinkedList(head);

	head = cObj.convertArrayToLinkedList(arr, n);
	head = rObj.reverseRecursion(head);
	printLinkedList(head);

	head = cObj.convertArrayToLinkedList(arr, n);
	head = rObj.reversePointer(head);
	printLinkedList(head);

	return 0;
}