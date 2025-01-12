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
		right = nullptr;
		left = nullptr;
	}
};
TreeFromInorderPreorder
{
public:
	TreeNode* createTree(vector<int> inorder, vector<int>preorder)
	{

	}

	/*
									10
					15									6
			3				2				1 						8


			3 15 2 10 1 6 8
			10 15 3 2 6 1 8					

	*/

};
int main()
{
	vector<int> inorder = {3,15,2,10,1,6,8};
	vector<int> postorder = {10, 15, 3, 2, 6, 1, 8};
	return 0;
}