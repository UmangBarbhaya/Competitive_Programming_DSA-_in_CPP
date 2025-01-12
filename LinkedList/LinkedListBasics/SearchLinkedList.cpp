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
		data=data1;
		next=nullptr;
	}
};
class SearchLinkedList
{
public:
	bool searchElement(Node* head, int element)
	{
		Node* temp = head;
		while(temp!=nullptr)
		{
			if(element==temp->data)
				return true;
			temp=temp->next;
		}
		return false;
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
	SearchLinkedList sObj;
	cout<<sObj.searchElement(head, 65)<<endl;
	cout<<sObj.searchElement(head, -65)<<endl;
	return 0;
}