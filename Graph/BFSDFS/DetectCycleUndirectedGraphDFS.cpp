#include<bits/stdc++.h>
using namespace std;
class DetectCycle
{
public:
	bool isCycle(vector<vector<int>> adj)
	{
		int n =  adj.size();
		vector<int> visited(n);
		bool answer = false;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
				answer = answer || isCycleDFS(adj, visited, i);
		}
		return answer;
	}
private:
	bool isCycleDFS(vector<vector<int>> adj, vector<int> &visited, int src)
	{
		stack <pair<int,int>> s;
		s.push({src,-1});
		visited[src] = 1;
		while(!q.empty())
		{
			int curr = s.top().first;
			int parent = s.top().second;
			s.pop();
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
	DetectCycle dobj;
	return 0;
}