#include<bits/stdc++.h>
using namespace std;
class NumberOfDistinctIslands
{
public:
	int findNoIslands(vector<vector<char>> &grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> visited(m, vector<int>(n,0));
		int cnt=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(visited[i][j]==0 && grid[i][j]=='1')
				{
					cnt++;
					bfs(i,j, grid, visited);
				}
			}
		}
		return cnt;
	}
private:
	void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
	{
		int m = grid.size();
		int n = grid[0].size();
		visited[row][col] =1;
		queue<pair<int,int>> q;
		q.push({row,col});
		while(!q.empty())
		{
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			for(int rowi=-1;rowi<=1;rowi++)
			{
				for(int coli=-1;coli<=1;coli++)
				{
					int nrow = row+rowi;
					int ncol = col+coli;
					if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]==0 && grid[nrow][ncol]=='1')
					{
						visited[nrow][ncol] = 1;
						q.push({nrow,ncol});
					}
				}
			}
		}

	}
};
int main()
{
	vector<vector<char>> grid = 
	{
		{'1','0','0','1','1'},
		{'1','0','0','0','1'},
		{'1','0','1','1','0'},
		{'1','0','1','0','0'},
		{'1','0','0','0','1'}
	};
	NumberOfDistinctIslands nobj;
	cout<<nobj.findNoIslands(grid)<<endl;
	return 0;
}
