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
class VerticalOrderTraversal
{
public:
	void verticalOT(TreeNode* root, vector<vector<int>> &vt, int level)
	{
		if(root==nullptr)
			return;
		queue<pair<TreeNode*, pair<int,int>>> q;
		map<int, map<int, multiset<int>>> mp;
		q.push({root,{0,0}});
		while(!q.empty())
		{
			TreeNode* curr = q.front().first;
			int vertical = q.front().second.first;
			int level = q.front().second.second; 
			mp[vertical][level].insert(curr->data);
			q.pop();
			if(curr->left)
				q.push({curr->left,{vertical-1,level+1}});
			if(curr->right)
				q.push({curr->right,{vertical+1,level+1}});
		}
		for(auto g: mp)
		{
			vector<int> col;
			for(auto h: g.second)
			{
				multiset<int> temp = h.second;
				for(auto val: temp)
				{
					col.push_back(val);
				}
			}
			vt.push_back(col);
		}

	}
};
void print(vector<vector<int>> vt)
{
	for(int i=0;i<vt.size();i++)
	{
		for(int j=0;j<vt[i].size();j++)
		{
			cout<<vt[i][j]<<" ";
		}
		cout<<endl;
	}
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
	
	
	VerticalOrderTraversal vObj;
	vector<vector<int>> vt;
	vObj.verticalOT(root,vt, 0);
	print(vt);
	return 0;
}