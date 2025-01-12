/*input
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int key;
	int value;
	int freqCnt;
	Node *next;
	Node *prev;
	Node(int key1, int value1)
	{
		key = key1;
		value = value1;
		next = nullptr;
		prev = nullptr;
		freqCnt = 1;
	}
};
class List
{
public:
	int size;
	Node *head;
	Node* tail;
	List()
	{
		head = new Node(0,0);
		tail = new Node(0,0);
		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
	}
	void addNodeFront(Node* newNode)
	{
		Node* temp = head->next;
		head->next = newNode;
		newNode->prev = head;
		newNode->next = temp;
		temp->prev = newNode;
		size++;
	}
	void deleteNodeBack(Node* delNode)
	{
		Node* delPrev = delNode->prev;
		Node* delNext = delNode->next;
		delPrev->next = delNext;
		delNext->prev = delPrev;
		delete delNode;
		delNode=nullptr;
		size--;
	}
};
class LFUCache
{
	int minFreq;
	int currSize;
	int maxCacheSize;
	unordered_map<int, Node*> keyNode;
	unordered_map<int , List*> freqListMap;
	void updateFreqListMap(Node* node)
	{
		keyNode.erase(node->key);
		freqListMap[node->freqCnt]->deleteNodeBack(node);
		if(node->freqCnt == minFreq && freqListMap[node->freqCnt]->size==0)
			minFreq--;
		List* nextHigherFreqList = new List();
		if(freqListMap.find(node->freqCnt+1)!=freqListMap.end())
		{
			nextHigherFreqList = freqListMap[node->freqCnt+1];
		}
		node->freqCnt+=1;
		nextHigherFreqList->addNodeFront(node);
		keyNode[node->key]  = node;
		freqListMap[node->freqCnt] = nextHigherFreqList;

	}
public:
	LFUCache(int capacity)
	{
		maxCacheSize = capacity;
		minFreq = 0;
		currSize = 0;
	}
	int get(int key)
	{
		if(keyNode.find(key)!=keyNode.end())
		{
			Node* reqdNode = keyNode[key];
			int value = reqdNode->value;
			updateFreqListMap(reqdNode);
			return value;
		}
		return -1;
	}
	void put(int key, int value)
	{
		if(maxCacheSize == 0)
			return;
		if(keyNode.find(key)!=keyNode.end())
		{
			Node* node = keyNode[key];
			node->value = value;
			updateFreqListMap(node);
		}
		else
		{
			if(currSize==maxCacheSize)
			{
				List* list = freqListMap[minFreq];
				keyNode.erase(list->tail->prev->key);
				freqListMap[minFreq]->deleteNodeBack(list->tail->prev);
				currSize--;
			}
		
			currSize++;
			minFreq = 1;
			List* listFreq = new List();
			if(freqListMap.find(minFreq)!=freqListMap.end())
			{
				listFreq = freqListMap[minFreq];
			}
			Node* node = new Node(key, value);
			listFreq->addNodeFront(node);
			keyNode[key]=node;
			freqListMap[minFreq] = listFreq;
		}
	}
};
int main()
{
	return 0;
}