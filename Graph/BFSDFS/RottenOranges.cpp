#include<bits/stdc++.h>
using namespace std;
class RottenOranges
{
public:
	int getRottenOranges(vector<vector<int>> &grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		int time1 = 0;
		queue <pair<pair<int,int>,int>> q;
		vector<vector<int>> visited(m,vector<int>(n,0));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(grid[i][j]==2)
				{
					visited[i][j]=2;
					q.push({{i,j},0});
				}
			}
		}
		
		
		while(!q.empty())
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int oldtime = q.front().second;
			time1 = max(time1,oldtime);
			q.pop();
			for(int i=0; i<4; i++)
			{
				int x1 = x+xaxis[i];
				int y1 = y+yaxis[i];
				if(x1>=0 && x1<m && y1>=0 && y1<n && grid[x1][y1]==1 && visited[x1][y1]==0)
				{
					q.push({{x1,y1},++oldtime});
					grid[x1][y1]=2;
					visited[x1][y1]=2;
				} 
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(grid[i][j]==1)
					return -1;
			}
		}
		return time1;
	}

};
int main()
{
	vector<vector<int>> grid = {{2,1,1},
								{1,1,0},
								{0,1,1}};
	RottenOranges robj;
	cout<<robj.getRottenOranges(grid)<<endl;
	return 0;
}