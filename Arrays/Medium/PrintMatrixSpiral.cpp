/*input
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/
#include<bits/stdc++.h>
using namespace std;
class PrintMatrixSpiral
{
	public:
		vector<int> getMatrixSpiralFormat(vector<vector<int>> mat)
		{
			vector<int> ans;
			int n = mat.size();
			int m = mat[0].size();
			int top = 0;
			int left =0;
			int right = m-1;
			int bottom = n-1;
			while(top<=bottom && left<=right)
			{
				for(int i=left;i<=right;i++)
				{
					ans.push_back(mat[top][i]);
				}
				top++;
				for(int i=top;i<=bottom;i++)
				{
					ans.push_back(mat[i][right]);
				}
				right--;
				if(top<=bottom)
				{
					for(int i=right;i>=left;i--)
					{
						ans.push_back(mat[bottom][i]);
					}
					bottom--;
				}
				if(left<=right)
				{
					for(int i=bottom; i>=top;i--)
					{
						ans.push_back(mat[i][left]);
					}
					
					left++;
				}
			}
			return ans;
		}
};
void print(vector<int> arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	vector <vector<int>> mat(n);
	for(int i=0;i<n;i++)
	{
		mat[i] = vector<int>(m);
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	PrintMatrixSpiral pmsObj;
	vector<int> ans = pmsObj.getMatrixSpiralFormat(mat);
	print(ans);
	return 0;
} 