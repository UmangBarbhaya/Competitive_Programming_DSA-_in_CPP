/*input
10 3
1 2 3 1 2 3 1 2 3 4
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
class ReverseKParts
{
/*
prev = null
1 	   2 	3  	x	1 	2 	3 	4
head 	   kth    next 
temp

3 	2 	1 	x 	1 	2 	3 	4
Kth     temp   next
        head

head	prev    temp

3   2   1   x   1    2    3        x    4
head    prev    temp      KthNode       next

3   2   1   x   3    2    1        x    4
head    prev    kth      temp         next

3   2   1   ->   3    2    1        x    4
head    prev    kth      temp         next

3   2   1   ->   3    2    1        x    4
head            kth      prev           temp


Now temp will return false for the KthNode
ifprev!=null just join prev->temp return


*/
private:
	Node* reverseLL(Node* head)
	{
		if(head == nullptr || head->next == nullptr)
			return head;
		Node* temp = head;
		Node* prev = nullptr;
		while(temp!=nullptr)
		{
			Node* front = temp->next;
			temp->next = prev;
			prev = temp;
			temp = front;

		}
		return prev;
	}
public:
	Node* reverseLLKParts(Node* head, int K)
	{
		if(head==nullptr)
			return head;
		Node* temp = head;

		Node* prev = nullptr; 
		while(temp!=nullptr)
		{
			int count=1;
			Node* KthNode = temp;
			while(count<K && KthNode!=nullptr)
			{
				KthNode = KthNode->next;
				count+=1;
			}
			if(KthNode==nullptr)
			{
				if(prev!=nullptr)
					prev->next = temp;
				break;
			}
			Node* nextNode = KthNode->next;
			KthNode->next = nullptr;
			reverseLL(temp);
			
			if(head==temp)
				head = KthNode;
			else
				prev->next = KthNode;
			prev = temp;
			temp=nextNode;
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
	int K;
	cin>>K;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ConvertArrayToLinkedList cObj;
	ReverseKParts rObj;
	Node* head = cObj.convertArrayToLL(arr, n);
	printLinkedList(head);
	head = rObj.reverseLLKParts(head, K);
	printLinkedList(head);
	return 0;
}