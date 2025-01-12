/*input
10
10 1243 12 354 23 6666 22 -345 0 87
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
							10 1243 12 354 23 6666 22 -345 0 87 -null

				10 1243 12 354 23 null 				 		6666 22 -345 0 87 null

			10 1243 12 null		354 23 null

		10 1243 null 	12 null 		354 null	23 null

	10 null     1243 null
*/
class SortLL
{
public:
	Node* sortLL(Node* head)
	{
		if(head==nullptr || head->next==nullptr)
			return head;
		Node* middle = findMiddle(head);
		Node* left = head;
		Node* right = middle->next;
		middle->next = nullptr;
		left = sortLL(left);
		right = sortLL(right);
		return mergeTwoSortedLL(left,right);
	}
private:
	Node* findMiddle(Node* head)
	{
		if(head==nullptr || head->next==nullptr)
			return head;
		Node* slow=head;
		/* This is an edge case, since for merge sort algorithm take first middle and not second middle in even length linked list
			2->3->4->5->x
			The middle element is 3 for merge sort and not 4
		*/
		Node* fast=head->next;
		while(fast!=nullptr && fast->next!=nullptr)
		{
			fast =fast->next->next;
			slow = slow->next;		
		}
		return slow;
	}
	Node* mergeTwoSortedLL(Node* head1, Node* head2)
	{
		Node* mergedLL = new Node(-1);
		Node* temp = mergedLL;

		while(head1!=nullptr && head2!=nullptr)
		{
			if(head1->data<=head2->data)
			{
				temp->next=head1;
				head1=head1->next;
			}
			else
			{
				temp->next=head2;
				head2=head2->next;
			}
			temp = temp->next;
		}
		while(head1!=nullptr)
		{
			temp->next=head1;
			head1=head1->next;
			temp = temp->next;
		}
		while(head2!=nullptr)
		{
			temp->next=head2;
			head2=head2->next;
			temp = temp->next;
		}
		return mergedLL->next;
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
	SortLL sObj;
	Node* head = cObj.convertArrayToLL(arr, n);
	head = sObj.sortLL(head);
	printLinkedList(head);
	return 0;
}