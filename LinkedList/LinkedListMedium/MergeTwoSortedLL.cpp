/*input
5 
10 30 50 100 150
6 
20 25 55 105 115 160
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
class MergeTwoSortedLL
{
public:
	Node* mergeTwoSortedLL(Node* head1, Node* head2)
	{
		Node* answer = new Node(-1);
		Node* temp = answer;

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
			temp=temp->next;

		}
		while(head1!=nullptr)
		{
			temp->next=head1;
			head1=head1->next;
			temp=temp->next;
		}
		while(head2!=nullptr)
		{
			temp->next=head2;
			head2=head2->next;
			temp=temp->next;
		}
		return answer->next;
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
	int n, m;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	vector<int> arr1(m);
	for(int i=0;i<m;i++)
	{
		cin>>arr1[i];
	}
	ConvertArrayToLinkedList cObj;
	MergeTwoSortedLL mObj;
	Node* head1 = cObj.convertArrayToLL(arr, n);
	Node* head2 = cObj.convertArrayToLL(arr1, m);
	Node* answer = mObj.mergeTwoSortedLL(head1, head2);
	printLinkedList(answer);
	return 0;
}
