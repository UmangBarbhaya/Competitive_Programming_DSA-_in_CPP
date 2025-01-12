/*input
1
1 2 3 2 1
*/
#include<bits/stdc++.h>
using namespace std;
class Node{
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
	Node* convertArrayToLinkedList(vector<int> arr, int n)
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
class PalindromeLL
{
private:
	Node* reverseLL(Node* head)
	{
		if(head==nullptr || head->next==nullptr)
			return head;
		Node* newHead = reverseLL(head->next);

		Node* front = head->next;
		front->next = head;
		head->next=nullptr;
		return newHead;
	}
public:
	bool isLLPalindrome(Node *head)
	{
		if(head == nullptr || head->next == nullptr)
			return true;
		//Find middle element
		Node* slow = head;
		Node* fast = head;
		while(fast->next!=nullptr && fast->next->next!=nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		Node* newHead = reverseLL(slow->next);

		Node* first = head;
		Node* second = newHead;
		while(second!=nullptr)
		{
			if(second->data != first->data)
			{
				reverseLL(newHead);
				return false;
			}
			first=first->next;
			second=second->next;
		}
		reverseLL(newHead);
		return true;

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
	PalindromeLL pObj; 
	Node* head = cObj.convertArrayToLinkedList(arr,n);
	cout<<pObj.isLLPalindrome(head)<<endl;
	return 0;
}