#include<bits/stdc++.h>
using namespace std;
class NumberofEnclaves
{
public:
	int numEnclaves(vector<vector<int>>& grid) 
	{
     	int m = grid.size();
     	int n = grid[0].size();
     	vector<vector<int>> visited(m,vector<int>(n,0));
     	for(int i=0;i<m;i++)
     	{
     		if(grid[i][0]==1 && visited[i][0]==0)
     		{
     			getDFS(grid, visited, i, 0, m, n);
     		}
     		if(grid[i][n-1]==1 && visited[i][n-1]==0)
     		{
     			getDFS(grid, visited, i, n-1, m, n);
     		}
     	}
     	for(int j=0;j<n;j++)
     	{
     		if(grid[0][j] == 1 && visited[0][j]==0)
     		{
     			getDFS(grid, visited, 0, j, m, n);
     		}
     		if(grid[m-1][j] == 1 && visited[m-1][j]==0)
     		{
     			getDFS(grid, visited, m-1, j, m, n);
     		}
     	}
     	int enclaves=0;
     	for(int i=0;i<m;i++)
     	{
     		for(int j=0;j<n;j++)
     		{
     			if(grid[i][j]==1 && visited[i][j]==0)
     			{
     				++enclaves;
     			}
     		}
     	}
     	return enclaves;	   
    }
private:
	void getDFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int sx, int sy, int m, int n)
	{
		stack<pair<int,int>> st;
		st.push({sx,sy});
		visited[sx][sy]=1;
		int xaxis[] = {0,0,-1,1};
		int yaxis[] = {1,-1,0,0};
		while(!st.empty())
		{
			int currx = st.top().first;
			int curry = st.top().second;
			st.pop();
			for(int i=0;i<4;i++)
			{
				int newx=currx+xaxis[i];
				int newy=curry+yaxis[i];
				if(newx>=0 && newy>=0 && newx<m && newy<n && visited[newx][newy]==0 && grid[newx][newy]==1)
				{
					visited[newx][newy]=1;
					st.push({newx,newy});
				}
			}

		}
	}
};
int main()
{
	NumberofEnclaves nobj;
	vector<vector<int>> grid{
        {1, 1},
        {1, 1}};
        cout<<nobj.numEnclaves(grid)<<endl;
	return 0;
}