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
class TopViewBT
{
public:
	void getTopViewBT(TreeNode* root, vector<int> &topView)
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
			if(mp.find(vertical)==mp.end())
			{
				mp[vertical] = curr->data;
			}
			if(curr->left!=nullptr)
				q.push({curr->left, vertical-1});
			if(curr->right!=nullptr)
				q.push({curr->right, vertical+1});
		}
		for(auto m : mp)
		{
			topView.push_back(m.second);
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
	TopViewBT tObj;
	vector<int> topView;
	tObj.getTopViewBT(root, topView);
	print(topView);
	return 0;
}