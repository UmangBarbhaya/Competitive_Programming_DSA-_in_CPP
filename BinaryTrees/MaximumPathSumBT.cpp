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
class MaximumPathSum
{
public:
	int getMaximumPathSum(TreeNode* root, int &maxSum)
	{
		int leftsum=0,rightsum=0;
		if(root==0)
			return 0;
		if(root->left)
			leftsum = max(0, getMaximumPathSum(root->left, maxSum));
		if(root->right)
			rightsum = max(0, getMaximumPathSum(root->right, maxSum));

		int totalsum = leftsum+rightsum+root->data;
		maxSum = max(maxSum, totalsum);
		return max(leftsum,rightsum)+root->data;
	} 
	/*
			Consider below scenario
								10
					15							20
									-30						-45

		The maximum sum is 10+15+20, the right subtree height will return -30 and -45 which will make it a negative sum
		So to avoid this we can return 0 if the sum is negative
	*/
};
int main()
{
	TreeNode* root = new TreeNode(10);
		root->left = new TreeNode(15);
		//root->left->left = new TreeNode(4);
		//root->left->right = new TreeNode(10);
		//root->left->left->right = new TreeNode(5);
		//root->left->left->right->right = new TreeNode(6);
		root->right = new TreeNode(20);
		root->right->left = new TreeNode(-30);
		root->right->right = new TreeNode(-45);
		int maxSum = INT_MIN;
		MaximumPathSum mObj;
		mObj.getMaximumPathSum(root,maxSum);
		cout<<maxSum<<endl;
	return 0;
}


/*
												-10

							5											6
					2					4						3						2

*/