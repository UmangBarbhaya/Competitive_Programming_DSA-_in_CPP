#include<bits/stdc++.h>
using namespace std;
class BipartiteGraphBFS
{
public:
	bool isBipartite(vector<vector<int>> &graph)
	{
		int N = graph.size();
		vector<int> visited(N,-1);
		bool ans = true;
		for(int i=0;i<N;i++)
		{
			if(visited[i]==-1)
			{
				ans = ans && bfs(graph, visited, i);
			}

		}
		return ans;
	}
private:
	bool bfs(vector<vector<int>> &graph, vector<int> &visited, int node)
	{
		queue<int> q;
		q.push(node);
		visited[node]=0;
		while(!q.empty())
		{
			int node = q.front();
			int parentcolor = visited[node];
			q.pop();
			for(auto it: graph[node])
			{
				if(visited[it]==parentcolor)
				{
					return false;
				}
				if(visited[it]==-1)
				{
					q.push(it);
					visited[it] = (parentcolor+1)%2;
				}

			}
		}
		return true;

	}
};
int main()
{
	BipartiteGraphBFS bobj;

	vector<vector<int>>adj = {{1,3},{0,2},{1,3},{0,2}};
	

	cout<<bobj.isBipartite(adj)<<endl;
	return 0;
}