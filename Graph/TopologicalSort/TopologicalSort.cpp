#include<bits/stdc++.h>
using namespace std;
class TopologicalSort
{
public:
	vector<int> topologicalSort(vector<vector<int>> &graph)
	{
		int V = graph.size();
		vector<int> visited(V,0);
		stack<int> ansSt;
		for(int i=0;i<V;i++)
		{
			if(visited[i] == 0)
			{
				dfs(graph, visited, ansSt, i);
			}
		}
		vector<int> answer;
		while(!ansSt.empty())
		{
			answer.push_back(ansSt.top());
			ansSt.pop();
		}
		return answer;
	}
private:
	void dfs(vector<vector<int>> &graph, vector<int> &visited, stack<int> &ansSt, int node)
	{
		if(visited[node]==1)
		{
			return;
		}
		
		visited[node]=1;
		for(auto it: graph[node])
		{
			dfs(graph, visited, ansSt, it);
		}
		ansSt.push(node);
	}
};
int main()
{
	TopologicalSort tobj;
	vector<vector<int>> graph = {{},{3},{3},{},{0,1},{0,2}};
	vector<int> answer = tobj.topologicalSort(graph);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}