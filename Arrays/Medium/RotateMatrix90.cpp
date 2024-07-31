/*input
3 3
1 2 3
4 5 6
7 8 9
*/
#include<bits/stdc++.h>
using namespace std;
class RotateMatrix90
{
public:
	void rotateMat90Clockwise(vector<vector<int>> &mat)
	{
		transpose(mat);
		reverseMatRow(mat);
	}
private:
	void transpose(vector<vector<int>> &mat)
	{
		int n = mat.size();
		int m = mat[0].size();
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<m;j++)
			{
				int temp = mat[i][j];
				mat[i][j]=mat[j][i];
				mat[j][i]=temp;
			}
		}
	}
	void reverseMatRow(vector<vector<int>> &mat)

	{
		int n = mat.size();
		for(int i=0;i<n;i++)
		{
			reverseVector(mat[i]);
		}
	}
	void reverseVector(vector<int> &arr)
	{
		int m = arr.size();
		int start = 0;
		int end = m-1;
		while(start<=end)
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			start++;
			end--;
		}

	}
};
void print(vector<vector<int>> mat)
{
	int n = mat.size();
	int m = mat[0].size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mat[i][j]<< " ";
		}
		cout<<endl;
	}
}
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	vector<vector<int>> mat(n);
	for(int i=0;i<n;i++)
	{
		mat[i] = vector<int>(m);
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	RotateMatrix90 rmObj;
	rmObj.rotateMat90Clockwise(mat);
	print(mat);
	return 0;
}