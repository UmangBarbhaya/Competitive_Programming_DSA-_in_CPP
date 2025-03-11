#include<bits/stdc++.h>
using namespace std;
class Matrix01
{
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
	{
		int m = mat.size();
		int n = mat[0].size();
		vector<vector<int>> answer(m, vector<int>(n,0));
		vector<vector<int>> visited(m, vector<int>(n,0));

		
		findBFS(mat, answer, visited, m, n);
				
		return answer;
	}
public:
	void findBFS(vector<vector<int>>& mat, vector<vector<int>> &answer, vector<vector<int>> &visited, int m, int n)
	{
		queue<pair<pair<int,int>,int>> q;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{	
				if(mat[i][j]==0)
				{
					q.push({{i,j},0});
					visited[i][j] = 1;
				}
			}
		}
		int xaxis[] = {0,0,-1,1};
			int yaxis[] = {1,-1,0 ,0};
		while(!q.empty())
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dist = q.front().second;
			
			answer[x][y]=dist;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int x1 = x+xaxis[i];
				int y1 = y+yaxis[i];
				if(x1>=0 && x1<m && y1>=0 && y1<n && visited[x1][y1]==0)
				{
					visited[x1][y1]=1;
						
					q.push({{x1,y1},dist+1});

				}
			}

		}
	}
};
int main()
{
	vector<vector<int>> mat = {{0,0,0},	
								{0,1,0},
								{1,1,1}};
	Matrix01 mobj;
	mat = mobj.updateMatrix(mat);
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[0].size();j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}