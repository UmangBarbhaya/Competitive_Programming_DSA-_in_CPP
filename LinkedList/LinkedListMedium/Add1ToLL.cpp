/*input
0
9 9 9 9
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
class Add1ToLL
{
private:
	int carryFinder(Node* head)
	{
		if(head==nullptr)
		{
			return 1;
		}
		int carry = carryFinder(head->next);
		if(carry==1)
		{
			int sum = carry+head->data;
			if(sum==10)
			{
				head->data = 0;
				return 1;

			}
			head->data = sum;
		}
		return 0;

	}
public:
	Node* add1ToLL(Node* head)
	{
		if(head==nullptr)
		{
			return new Node(1);
		}
		int carry = carryFinder(head);
		if(carry == 1)
		{
			Node* temp = new Node(1);
			temp->next = head;
			head = temp;
			return head;
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
	ConvertArrayToLinkedList cObj;
	Add1ToLL aObj;
	Node* head = cObj.convertArrayToLL(arr, n);
	head = aObj.add1ToLL(head);
	printLinkedList(head);
}