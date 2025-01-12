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
class ZigZagTraversal
{
public:
	vector<vector<int>> getZigZagTraversal(TreeNode* root)
	{

		vector<vector<int>> answer;
		if(!root)
			return answer;
		queue<TreeNode*> q;
		q.push(root);
		bool flag = false;
		while(!q.empty())
		{
			int sizeq = q.size();
			vector<int> col(sizeq);
			for(int i=0;i<sizeq;i++)
			{
				TreeNode* curr = q.front();
				q.pop();	
				int index = i;
				if(flag)
					index=i;
				else
					index = sizeq-i-1;
				col[index] = curr->data;
				if(curr->left)
					q.push(curr->left);
				if(curr->right)
					q.push(curr->right);

			}
			flag = !flag;
			answer.push_back(col);
		}
		return answer;

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
	
	
	ZigZagTraversal zObj;
	vector<vector<int>> zzt = zObj.getZigZagTraversal(root);
	print(zzt);
	return 0;
}