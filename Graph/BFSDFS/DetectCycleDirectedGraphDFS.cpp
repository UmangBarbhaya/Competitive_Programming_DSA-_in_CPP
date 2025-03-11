#include<bits/stdc++.h>
using namespace std;
class DetectCycleDirectedGraphDFS
{
public:
	bool isCycle(vector<vector<int>> &graph)
	{
		int V = graph.size();
		vector<int> visited(V, 0);
		vector<int> pathVisited(V, 0);
		bool ans = false;
		for(int i=0;i<V;i++)
		{
			ans = ans|| dfs(graph, visited, pathVisited, i);
		}
		return ans;
	}
private:
	bool dfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited, int node)
	{
		visited[node] = 1;
		pathVisited[node] = 1;
		for(auto it: graph[node])
		{
			if(!visited[it])
			{
				pathVisited[it] = 1;
				if(dfs(graph, visited, pathVisited, it))
					return true;
			}
			else if(pathVisited[it]==1)
			{
				return true;
			}
		}
		pathVisited[node] = 0;
	return false;
	}
};
int main()
{
	vector<vector<int>> graph = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	DetectCycleDirectedGraphDFS dobj;
	cout<<dobj.isCycle(graph)<<endl;
	return 0;
}