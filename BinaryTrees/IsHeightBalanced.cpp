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
class IsHeightBalanced
{
	int heightBT(TreeNode* root, bool &ans)
	{
		if(root==0)
			return 0;
		int lh = heightBT(root->left, ans);
		int rh = heightBT(root->right, ans);
		if(abs(lh-rh)>1)
			ans= ans && false;
		else
			ans = ans && true;
		return 1+max(lh,rh);
	}
public:
	bool isHeightBal(TreeNode* root)
	{
		bool ans=true;
			heightBT(root, ans);
		return ans;
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
	IsHeightBalanced iObj;
	cout<<iObj.isHeightBal(root)<<endl;
	return 0;
}


/*

						10
		5								6

3				4
*/