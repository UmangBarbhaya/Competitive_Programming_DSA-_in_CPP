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
class DiameterBT
{
private:
	int getHeightBT(TreeNode* root, int &maxDiameter)
	{
		if(root==0)
			return 0;
		int lh = getHeightBT(root->left, maxDiameter);
		int rh = getHeightBT(root->right, maxDiameter);
		maxDiameter = max(maxDiameter, lh+rh);
		return max(lh,rh);
	}
	public:
		int getDiameterBT(TreeNode* root)
		{
			
			int maxDiameter=0;
			return getHeightBT(root, maxDiameter);
			//return maxDiameter;
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
	DiameterBT dobj;
	cout<<dobj.getDiameterBT(root)<<endl;
	return 0;
}