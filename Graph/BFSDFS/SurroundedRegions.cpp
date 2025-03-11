#include<bits/stdc++.h>
using namespace std;
class SurroundedRegions
{
public:
	void solve(vector<vector<char>>& board)
	{
		int m = board.size();
		int n = board[0].size();
		vector<vector<int>> visited(m, vector<int>(n,0));
		//Traverse all borders
		//Traverse first and last column
		for(int i=0;i<m;i++)
		{
			if(board[i][0]=='O' && visited[i][0]==0)
			{
				findDFS(board, i, 0, visited);
			}
			if(board[i][n-1]=='O' && visited[i][n-1]==0)
			{
				findDFS(board,i,n-1, visited);
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(board[0][i]=='O' && visited[0][i]==0)
			{
				findDFS(board, 0, i, visited);
			}
			if(board[m-1][i]=='O' && visited[m-1][i]==0)
			{
				findDFS(board, m-1, i, visited);
			}
		}

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]=='O' && visited[i][j]==0)
				{
					board[i][j]='X';
				}
			}
		}

	}
private:
	void findDFS(vector<vector<char>>& board , int srcx, int srcy, vector<vector<int>> &visited )
	{
		int m = board.size();
		int n = board[0].size();
		visited[srcx][srcy]=1;
		queue<pair<int,int>> q;
		q.push({srcx,srcy});
		int xaxis[] = {0,0,1,-1};
		int yaxis[] = {1,-1,0,0};
		while(!q.empty())
		{
			int currx = q.front().first;
			int curry = q.front().second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int newx = currx+xaxis[i];
				int newy = curry+yaxis[i];
				if(newx>=0 && newx<m && newy>=0 && newy<n && board[newx][newy]=='O' && visited[newx][newy]==0)
				{
					visited[newx][newy]=1;
					q.push({newx,newy});
				}
			}

		}
	}
};
int main()
{
	
    vector<vector<char>> mat{
        {'O', 'O'}, 
        {'O', 'O'}
    };
    SurroundedRegions sobj;
    sobj.solve(mat);
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