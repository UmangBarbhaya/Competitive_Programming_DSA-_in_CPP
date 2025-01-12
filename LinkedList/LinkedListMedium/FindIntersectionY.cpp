/*input
10
1 2 3 4 5 6 7 8 9 10
2
3 4
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
class FindIntersectionY
{
public:
	Node* findIntersectionY(Node* head1, Node* head2)
	{
	
		Node* P1=head1;
		Node* P2=head2;
		while(P1!=P2)
		{
			
			if(P1==nullptr)
			{
				P1=head2;
			}
			else
			{
				P1=P1->next;
			}
			if(P2==nullptr)
			{
				P2=head1;
			}
			else
			{
				P2=P2->next;
			}
		}
		return P1;
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
	FindIntersectionY fObj;
	Node* head1 = cObj.convertArrayToLL(arr, n);
	Node* head2 = cObj.convertArrayToLL(arr1, m);
	head2->next->next = head1->next->next;
	Node* answer = fObj.findIntersectionY(head1, head2);
	cout<<answer->data<<endl;
	return 0;
}