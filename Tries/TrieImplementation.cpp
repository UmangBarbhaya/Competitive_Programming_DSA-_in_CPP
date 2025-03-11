#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
private:
	TrieNode* link[26];
	bool endFlag = false;
public:

	bool contains(char c)
	{
		if(link[c-'a']!=nullptr)
		{
			return true;
		}
		return false;
	}
	void put(char c, TrieNode *newTN)
	{
		link[c-'a'] = newTN;
	}
	TrieNode* get(char c)
	{
		return link[c-'a'];
	}
	void setEnd()
	{
		endFlag=true;
	}
	bool isEnd()
	{
		return endFlag;
	}
};
class Trie
{
public:
	TrieNode *root;
	Trie()
	{
		root = new TrieNode();
	}
	void insert(string word)
	{
		TrieNode* curr = root;
		for(int i=0;i<word.length();i++)
		{
			if(!curr->contains(word[i]))
			{
				curr->put(word[i], new TrieNode());
			}
			curr = curr->get(word[i]);

		}
		curr->setEnd();
	}
	bool search(string word)
	{
		TrieNode *curr=root;
		for(int i=0;i<word.length();i++)
		{
			if(!curr->contains(word[i]))
				return false;
			curr=curr->get(word[i]);

		}
		if(curr->isEnd())
		{
			return true;
		}
		return false;
	}
	bool startsWith(string word)
	{
		TrieNode *curr=root;
		for(int i=0;i<word.length();i++)
		{
			if(!curr->contains(word[i]))
				return false;
			curr=curr->get(word[i]);

		}
		return true;
	}
};
int main()
{
	Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    
    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    
    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;
    
    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;

    return 0;
}