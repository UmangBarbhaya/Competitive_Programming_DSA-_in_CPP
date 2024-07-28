/*input
4 4
1 1 1 1
1 0 1 1
1 1 0 1
0 1 1 1
*/
#include<bits/stdc++.h>
using namespace std;
class SetMatrixZero
{
	public:
		vector<vector<int>> setMatrixZeroBetter(vector<vector<int>> mat)
		{
			int n = mat.size();
			int m = mat[0].size();
			vector<int> row(n, 1);
			vector<int> col(m, 1);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(mat[i][j]==0)
					{
						row[i]=0;
						col[j]=0;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(row[i]==0 || col[j]==0)
					{
						mat[i][j]=0;
					}
				}
			}
			return mat;
		}
		vector<vector<int>> setMatrixZeroOptimal(vector<vector<int>>mat)
		{
			int n = mat.size();
			int m = mat[0].size();
			int col0 = 1;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(mat[i][j] == 0)
					{
						mat[i][0] = 0;
						if(j==0)
							col0=0;
						else
							mat[0][j]=0;
					}
				}
			}
			for(int i=1;i<n;i++)
			{
				for(int j=1;j<m;j++)
				{
					if(mat[0][j]==0 || mat[i][0]==0)
					{
						mat[i][j]=0;
					}
				}
			}
			if(mat[0][0]==0)
			{
				for(int j=0;j<m;j++)
				{
					mat[0][j]=0;
				}
			}
			if(col0==0)
			{
				for(int i=0;i<n;i++)
				{
					mat[i][0]=0;
				}
			}
			return mat;
		}
};
void print(vector<vector<int>> mat, int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	vector<vector<int>> matrix(n);
	for(int i=0;i<n;i++)
	{
		matrix[i] = vector<int>(m);
		for(int j=0;j<m;j++)
		{
			cin>>matrix[i][j];
		}
	}
	SetMatrixZero smtObj;
	cout<<"Better Approach:"<<endl;
	vector<vector<int>> ans = smtObj.setMatrixZeroBetter(matrix);
	print(ans, n, m);
	cout<<"Optimal Approach:"<<endl;
	ans = smtObj.setMatrixZeroOptimal(matrix);
	print(ans, n, m);
	return 0;
}