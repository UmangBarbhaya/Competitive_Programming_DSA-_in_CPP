/*input
4
2 6 7 3
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
		data=data1;
		next=nullptr;
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
class MiddleOfLinkedList
{
public:
	/*dryrun
	Even Nodes;
	6 7
	slow = 6
	fast = 6
	Iteration1:
	slow = 7
	fast = nullptr   (since fast->next->next), check for fast!=nullptr

	5 6 7
	slow 5
	fast 5
	Iteration 1
	slow 6
	fast 7 (now if I do fast->next->next, it will give segmentation fault, check for fast->next!=nullptr)

	*/
	Node* getMiddleElementOfLinkedList(Node* head)
	{
		if(head==nullptr)
			return 0;
		Node* slow = head;
		Node* fast = head;
		while(fast!=nullptr && fast->next!=nullptr) //even and odd
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		return slow;
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
	ConvertArrayToLinkedList cObj;
	Node* head = cObj.convertArrayToLinkedList(arr, n);
	MiddleOfLinkedList mObj;
	cout<<mObj.getMiddleElementOfLinkedList(head)->data<<endl;
	return 0;
}