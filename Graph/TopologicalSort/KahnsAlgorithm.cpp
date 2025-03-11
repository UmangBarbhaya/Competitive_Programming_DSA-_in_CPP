#include<bits/stdc++.h>
using namespace std;
class KahnAlgo
{
public:
	vector<int> topologicalSort(vector<vector<int>> graph)
	{
		int V = graph.size();
		vector<int> indegree (V,0);
		for(int i=0;i<V;i++)
		{
			for(auto it: graph[i])
			{
				++indegree[it];
			}
		}
		//Now do BFS traversal by taking indegree0;
		queue<int> q;
		for(int i=0;i<V;i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
			}
		}
		vector<int> answer;
		while(!q.empty())
		{
			int node = q.front();
			answer.push_back(node);
			q.pop();
			for(auto it: graph[node])
			{
				indegree[it]--;
				if(indegree[it]==0)
				{
					q.push(it);
				}
			}
		}
		return answer;
	}
};
int main()
{
	KahnAlgo kobj;
	vector<vector<int>> graph = {{},{3},{3},{},{0,1},{0,2}};
	vector<int> answer = kobj.topologicalSort(graph);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}