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
class LowestCommonAncestor
{
public:
	TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if(root==nullptr)
			return nullptr;
		if(root == p || root == q)
			return root;
		TreeNode* left = getLCA(root->left, p, q);
		TreeNode* right = getLCA(root->right, p, q);
		if(left==nullptr)
			return right;
		if(right==nullptr)
			return left;
		return root;
	}
};
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

	LowestCommonAncestor lObj;
	cout<<lObj.getLCA(root, root->left->left->right->right, root->left->right)->data<<endl;

	return 0;
}