#include<bits/stdc++.h>
using namespace std;
class DetectCycleDirectedGraphBFS
{
public:
	bool isCyclic(vector<vector<int>> &graph)
	{
		int V=graph.size();
		vector<int> indegree(V,0);
		for(int i=0;i<V;i++)
		{
			for(auto it: graph[i])
			{
				indegree[it]++;
			}
		}
		queue<int> q;
		for(int i=0;i<V;i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int node = q.front();
			q.pop();
			for(auto it: graph[node])
			{
				indegree[it]--;
				if(indegree[it]==0)
					q.push(it);
			}
		}
		for(int i=0;i<V;i++)
		{
			if(indegree[i]!=0)
				return false;
		}
		return true;
	}


};
int main()
{
	vector<vector<int>> graph = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	DetectCycleDirectedGraphBFS dobj;
	cout<<dobj.isCyclic(graph);
	return 0;
}