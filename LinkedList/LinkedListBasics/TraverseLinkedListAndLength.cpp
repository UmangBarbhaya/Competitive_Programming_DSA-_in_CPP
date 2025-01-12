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
	Node(int data1, Node* next1)
	{
		data = data1;
		next = next1;
	}	
};
class TraverseLinkedListAndLength
{
public:
	int getLinkedListLength(Node *head)
	{
		int counter=0;
		while(head!=nullptr)
		{
			counter++;
			head=head->next;
		}
		return counter;
	}
	void traverseAndPrintLL(Node* head)
	{
		while(head!=nullptr)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
		cout<<endl;
	}
};
class ConvertArrayToLL
{
public:
	Node* convertArrayToLL(vector<int> arr, int n)
	{
		if(n==0)
			return nullptr;
		Node *head = new Node(arr[0]);
		Node *mover = head;
		for(int i=1;i<n;i++)
		{
			Node* temp = new Node(arr[i]);
			mover->next = temp;
			mover=mover->next;
		}
		return head;
	}
};
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
	TraverseLinkedListAndLength tnObj;
	cout<<"Length: "<<tnObj.getLinkedListLength(head)<<endl;
	tnObj.traverseAndPrintLL(head);
	return 0;
}