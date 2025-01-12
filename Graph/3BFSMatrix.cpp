/*input
*/
#include<bits/stdc++.h>
using namespace std;
class BFSMatrix
{
public:
	vector<int> BFS(int arr[4][5])
	{
		vector<int> answer;
		queue<pair<int,int>> q;
		int n = 4;
		int m = 5;
		int visited[n][m] = {{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}};
		q.push({0,0});
		visited[0][0]=1;
		while(!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			answer.push_back(arr[x][y]);
			q.pop();
			for(int i=-1;i<=1;i++)
			{
				for(int j=-1;j<=1;j++)
				{
					int xnew = x+i;
					int ynew = y+j;
					if(xnew>-1 && xnew<n && ynew>-1 && ynew<m &&!visited[xnew][ynew])
					{
						//cout <<"hhfg"<<endl;
						q.push({xnew,ynew});
						visited[xnew][ynew] = 1;
					}
				}
			}
		}
		return answer;
	}

};
void print(vector<int> answer)
{
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int arr[4][5] = 
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};
	BFSMatrix bobj;
	print(bobj.BFS(arr));
	return 0;
}