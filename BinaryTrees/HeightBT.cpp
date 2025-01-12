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
class HeightBT
{
	public:
		int getHeightBT(TreeNode* root)
		{
			if(root==nullptr)
				return 0;
			return max(1+getHeightBT(root->left), 1+getHeightBT(root->right));
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
	HeightBT hobj;
	cout<<hobj.getHeightBT(root)<<endl;
	return 0;
}