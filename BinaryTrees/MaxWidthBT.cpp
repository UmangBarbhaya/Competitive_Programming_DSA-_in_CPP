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
class MaxWidthBT
{
	public:
		int getMaxWidhtBT(TreeNode* root)
		{
			int maximumWidth = INT_MIN;
			if(!root)
				return 0;
			queue<pair<TreeNode*, int>> q;
			q.push({root, 0});
			while(!q.empty())
			{
				int sizeq = q.size();
				int minIndex=0,maxIndex=0;
				int mmin = q.front().second;
				for(int i=0;i<sizeq;i++)
				{
					TreeNode* curr = q.front().first;
					int index = q.front().second-mmin;
					q.pop();
					if(i==0)
						minIndex = index;
					if(i==sizeq-1)
						maxIndex = index;
					if(curr->left)
						q.push({curr->left, (2*index+1)});
					if(curr->right)
						q.push({curr->right, (2*index+2)});
				}
				maximumWidth = max(maximumWidth, maxIndex-minIndex+1);
			}

			return maximumWidth;
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
	MaxWidthBT mobj;
	cout<<mobj.getMaxWidhtBT(root)<<endl;
	return 0;
}