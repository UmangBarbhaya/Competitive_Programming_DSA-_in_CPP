/*input
*/
#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data1)
	{
		data = data1;
		left = nullptr;
		right = nullptr;
	}
};
class Traversal
{
public:
	void preOrderTraversalMorris(TreeNode *root, vector<int> &preorderTMorris)
	{
		TreeNode *curr = root;
		while(curr!=nullptr)
		{
			if(curr->left == nullptr)
			{
				preorderTMorris.push_back(curr->data);
				curr = curr->right;
			}
			else
			{
				TreeNode* predes = curr->left;
				while(predes->right!=nullptr && predes->right!=curr)
				{
					predes = predes->right;
				}
				if(predes->right==nullptr)
				{
					predes->right = curr;
					preorderTMorris.push_back(curr->data);
					curr = curr->left;
				}
				else
				{
					predes->right = nullptr;
					curr = curr->right;
				}
			}
		}
	}
	void inOrderTraversalMorris(TreeNode *root, vector<int> &inorderTMorris)
	{
		TreeNode* curr = root;
		while(curr!=nullptr)
		{
			//Find the left predecessor
			if(curr->left==nullptr)
			{
				inorderTMorris.push_back(curr->data);
				curr = curr->right;
			}
			else
			{
				TreeNode* predes = curr->left;
				while(predes->right!=nullptr && predes->right != curr)
				{
					predes = predes->right;
				}	
				if(predes->right == nullptr)
				{
					predes->right = curr;
					curr = curr->left;
				}
				else
				{
					predes->right = nullptr;
					inorderTMorris.push_back(curr->data);
					curr = curr->right;
				}
			}
		}
	}
	void inOrderTraversal(TreeNode* root, vector<int> &inorderT)
	{
		if(root==nullptr)
		{
			return;
		}
		inOrderTraversal(root->left,inorderT);
		inorderT.push_back(root->data);
		inOrderTraversal(root->right,inorderT);
	}
	void preOrderTraversal(TreeNode* root, vector<int> &preorderT)
	{
		if(root==nullptr)
		{
			return;
		}
		preorderT.push_back(root->data);
		preOrderTraversal(root->left, preorderT);
		preOrderTraversal(root->right, preorderT);
	}
	void postOrderTraversal(TreeNode* root, vector<int> &postorderT)
	{
		if(root==nullptr)
		{
			return;
		}
		
		postOrderTraversal(root->left, postorderT);
		postOrderTraversal(root->right, postorderT);
		postorderT.push_back(root->data);	
	}
	void levelOrderTraversal(TreeNode* root, vector<int> &levelorderT)
	{
		queue<TreeNode*> q;
		if(root==nullptr)
			return;
		q.push(root);
		int level=1; //added as a separator for levels
		while(!q.empty())
		{
			int sizeQ = q.size();
			levelorderT.push_back(-1*level); //added as a separator for levels
			level++; //added as a separator for levels
			for(int i=0;i<sizeQ;i++)
			{
				TreeNode* curr = q.front();
				q.pop();
				levelorderT.push_back(curr->data);
				if(curr->left!=nullptr)
				{
					q.push(curr->left);
				}
				if(curr->right!=nullptr)
				{
					q.push(curr->right);
				}
				
			}
			
		}
	}
};
void print(vector<int> inorderT)
{
	for(int i=0;i<inorderT.size();i++)
	{
		cout<<inorderT[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->left->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(2);
	root->right->left->left = new TreeNode(2);
	root->right->left->left->left = new TreeNode(1);
	root->right->right = new TreeNode(1);
	Traversal tObj;
	vector<int> inorderT;
	tObj.inOrderTraversal(root, inorderT);
	print(inorderT);
	

	vector<int> preorderT;
	tObj.preOrderTraversal(root, preorderT);
	print(preorderT);

	vector<int> postorderT;
	tObj.postOrderTraversal(root, postorderT);
	print(postorderT);

	vector<int> levelorderT;
	tObj.levelOrderTraversal(root, levelorderT);
	print(levelorderT);

	vector<int> inorderTMorris;
	tObj.inOrderTraversalMorris(root, inorderTMorris);
	print(inorderTMorris);

	vector<int> preorderTMorris;
	tObj.preOrderTraversalMorris(root, preorderTMorris);
	print(preorderTMorris);

	return 0;
}


/*
							10
			5											6

	2				4						2						1
				3					2	
			2				1


2 5 2 3 4 10 1 2 2 6 1
10 5 2 4 3 2 6 2 2 1 1			
*/