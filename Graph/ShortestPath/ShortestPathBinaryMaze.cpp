#include<bits/stdc++.h>
using namespace std;
class ShortestPathBinaryMaze
{
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n,1e9));
        if(grid[0][0]==1 || grid[m-1][n-1])
        	return -1;
        q.push({0,{0,0}});
        dist[0][0]=0;
        while(!q.empty())
        {
        	int currDis = q.front().first;
        	int currRow = q.front().second.first;
        	int currCol = q.front().second.second;
        	q.pop();
        	for(int i=-1;i<=1;i++)
        	{
        		int nrow = currRow+i;
        		for(int j=-1;j<=1;j++)
        		{
        			int ncol = currCol+j;
        			if(nrow>=0 && ncol>=0 && nrow<m && ncol<m && grid[nrow][ncol]==0 && dist[nrow][ncol] > currDis+1)
        			{
        				dist[nrow][ncol]=currDis+1;
        				q.push({dist[nrow][ncol],{nrow,ncol}});
        			}
        		}
        	}

        }
        if(dist[m-1][n-1]==1e9)
        	return -1;

        return dist[m-1][n-1]+1;
    }
};
int main()
{
	vector<vector<int>> grid = {
		{0,0,0},
		{1,1,0},
		{1,1,0}
	};
	ShortestPathBinaryMaze mobj;
	cout<<mobj.shortestPathBinaryMatrix(grid);
	return 0;
}