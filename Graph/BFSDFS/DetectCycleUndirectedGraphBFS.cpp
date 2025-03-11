#include<bits/stdc++.h>
using namespace std;
class DetectCycleUndirectedGraph
{
public:
    // Function to detect cycle in an undirected graph.
    public:
	bool isCycle(vector<vector<int>> &adj)
	{
		int n = adj.size();
		vector<int> visited(n);
		bool answer = false;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
				answer = answer || detectCycleBFS(adj, visited, i);
		}
		return answer;

	}
private:
	bool detectCycleBFS(vector<vector<int>> adj, vector<int> &visited, int src)
	{
		queue<pair<int,int>> q;
		q.push({src,-1});
		visited[src] = 1;
		while(!q.empty())
		{
			int curr = q.front().first;
			int parent = q.front().second;
			q.pop();
			for(int node : adj[curr])
			{
				if(visited[node]==1 && parent!=node)
				{
					return true;
				}
				if(visited[node]==0)
				{
				    visited[node]=1;
				    q.push({node,curr});
				}
			}

		}
		return false;
	}
};
int main()
{

}