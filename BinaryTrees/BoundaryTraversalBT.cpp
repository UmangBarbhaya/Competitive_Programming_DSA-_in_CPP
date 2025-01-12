/*input
*/
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
class BoundaryTraversal
{
private:
	bool isLeaf(TreeNode* node)
	{
		if(node->left == nullptr && node->right==nullptr)
			return true;
		return false;
	}
	void getLeftBoundary(TreeNode* root, vector<int> &bt)
	{
		if(root==nullptr || isLeaf(root))
			return;
		bt.push_back(root->data);
		if(root->left)
			getLeftBoundary(root->left, bt);
		else
			getLeftBoundary(root->right, bt);
	}
	void getLeafBoundary(TreeNode* root, vector<int> &bt)
	{
		if(root==nullptr)
			return;
		if(isLeaf(root))
		{
			bt.push_back(root->data);
			return;
		}
		getLeafBoundary(root->left, bt);
		getLeafBoundary(root->right, bt);	

	}
	void getRightReverseBoundary(TreeNode* root, vector<int> &bt)
	{
		if(root==nullptr || isLeaf(root))
			return;
		
		if(root->left)
			getLeftBoundary(root->right, bt);
		else
			getLeftBoundary(root->left, bt);
		bt.push_back(root->data);
	}
public:
	vector<int> getBoundaryTraversal(TreeNode* root)
	{
		vector<int> bt;
		getLeftBoundary(root, bt);
		getLeafBoundary(root, bt);
		getRightReverseBoundary(root, bt);
		return bt;

	}
};
void print(vector<int> bt)
{
	for(int j=0;j<bt.size();j++)
	{
		cout<<bt[j]<<" ";
	}
	cout<<endl;
}
int main()
{
	// TreeNode* root = new TreeNode(1);
	// root->left = new TreeNode(2);
	// root->left->left = new TreeNode(4);
	// root->left->right = new TreeNode(10);
	// root->left->left->right = new TreeNode(5);
	// root->left->left->right->right = new TreeNode(6);
	// root->right = new TreeNode(3);
	// root->right->left = new TreeNode(9);
	// root->right->right = new TreeNode(11);

	TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
	
	
	BoundaryTraversal bObj;
	vector<int> bt = bObj.getBoundaryTraversal(root);
	print(bt);
	return 0;
}