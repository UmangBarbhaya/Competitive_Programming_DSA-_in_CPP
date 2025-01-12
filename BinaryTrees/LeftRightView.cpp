/*input*/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
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
class LeftRightView
{
public:
	/*
	This can be solved by levelorder traversal as well as recursive traversal.
	Recursive method for left view can be left, right
	Recursive method for right view can  be right left
	have a level variable and insert into answer if level== vector.size(), since level starts from 0 and we are entering it for the first time
	*/
	void leftViewBT(TreeNode* root, vector<int> &leftView, int level)
	{
		if(root==nullptr)
			return;
		if(leftView.size()==level)
		{
			leftView.push_back(root->data);
		}
		leftViewBT(root->left, leftView, level+1);
		leftViewBT(root->right, leftView, level+1);
	}
	void rightViewBT(TreeNode* root, vector<int> &rightView, int level)
	{
		if(root == nullptr)
			return;
		if(level==rightView.size())
		{
			rightView.push_back(root->data);
		}
		rightViewBT(root->right, rightView, level+1);
		rightViewBT(root->left, rightView, level+1);
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
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->left->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(2);
	root->right->left->left = new TreeNode(2);
	root->right->left->left->left = new TreeNode(1);
	root->right->right = new TreeNode(1);

	LeftRightView lrObj;
	vector<int> leftView;
	lrObj.leftViewBT(root, leftView, 0);
	print(leftView);

	vector<int> rightView;
	lrObj.rightViewBT(root, rightView, 0);
	print(rightView);
	return 0;
}
/*
															10

						5																			6
		2								4										2										1
								3										2
						2										1								
*/
