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
class BottomViewBT
{
public:
	void getBottomViewBT(TreeNode* root, vector<int> &bottomView)
	{
		/* Do a vertical order traversal i.e:level order
		*/
		if(root == nullptr)
			return;
		map<int, int> mp;
		queue<pair<TreeNode*, int>> q;
		q.push({root,0});
		while(!q.empty())
		{
			TreeNode* curr = q.front().first;
			int vertical = q.front().second;
			q.pop();
			mp[vertical] = curr->data;
			if(curr->left)
				q.push({curr->left, vertical-1});
			if(curr->right)
				q.push({curr->right, vertical+1});

		}
		for(auto m: mp)
		{
			bottomView.push_back(m.second);
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
	//root->left->left->right->right = new TreeNode(6);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);
	BottomViewBT bObj;
	vector<int> bottomView;
	bObj.getBottomViewBT(root, bottomView);
	print(bottomView);
	return 0;
}