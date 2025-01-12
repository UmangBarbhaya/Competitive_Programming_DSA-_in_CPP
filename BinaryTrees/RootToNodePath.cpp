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
class RootToNodePath
{
public:
	bool getRootToNodePath(TreeNode* root, vector<int> &path, int node)
	{
		if(root==nullptr)
			return false;
		path.push_back(root->data);
		if(root->data == node)
			return true;
		
		bool flag = getRootToNodePath(root->left, path, node) || getRootToNodePath(root->right, path, node);
		if(flag)
			return true;
		else
		{
			path.pop_back();
			return false;
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
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(10);
	root->left->left->right = new TreeNode(5);
	root->left->left->right->right = new TreeNode(6);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);

	RootToNodePath rObj;
	vector<int> path;
	rObj.getRootToNodePath(root, path, 6);
	print(path);
	return 0;
}