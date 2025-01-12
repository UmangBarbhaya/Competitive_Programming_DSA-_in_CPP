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
class LoopInLL
{
public:
	bool findLoopInLLMap(Node *head)
	{
		unordered_map <Node*,int> mpp;
		Node* temp = head;
		while(temp!=nullptr)
		{
			if(mpp.find(temp)!=mpp.end())
				return true;
			mpp[temp] = 1;
			temp=temp->next;
		}
		return false;
	}
	bool findLoopInLLPointer(Node *head)
	{
		Node* slow = head;
		Node* fast = head;
		while(fast!=nullptr && fast->next!=nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
			{
				return true;
			}

		}
		return false;
	}
	Node* findStartingLoopNodeInLLPointer(Node *head)
	{
		Node* slow = head;
		Node* fast = head;
		while(fast!=nullptr && fast->next!=nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
			{
				slow = head;
				while(slow != fast)
				{
					slow=slow->next;
					fast=fast->next;
				}
				return slow;
			}

		}
		return nullptr;
	}
	int findLoopLengthInLLPointer(Node* head)
	{
		Node* slow = head;
		Node* fast = head;
		while(fast!=nullptr && fast->next!=nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
			{
				int cnt=0;
				slow = slow->next;
				while(slow!=fast)
				{
					cnt++;
					slow=slow->next;
				}
				return cnt+1;
			}
		}
		return 0;
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
	LoopInLL lObj;
	Node* head = cObj.convertArrayToLinkedList(arr, n);
	Node* temp = head;
	cout<<lObj.findLoopInLLMap(head)<<endl;
	cout<<lObj.findLoopInLLPointer(head)<<endl;
	while(temp->next !=nullptr)
	{
		temp = temp->next;
	}
	temp->next = head->next->next;
	
	cout<<lObj.findLoopInLLMap(head)<<endl;
	cout<<lObj.findLoopInLLPointer(head)<<endl;
	cout<<lObj.findStartingLoopNodeInLLPointer(head)->data<<endl;
	cout<<lObj.findLoopLengthInLLPointer(head)<<endl;
	return 0;
}
