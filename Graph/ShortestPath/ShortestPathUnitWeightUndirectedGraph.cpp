#include<bits/stdc++.h>
using namespace std;
class ShortestPathUnitWeightUndirectedGraph
{
public:
	vector<int> shortestPath(vector<vector<int>> graph, int src)
	{
		int V = graph.size();
		vector<int> distance(V,INT_MAX);
		queue<int> q;
		q.push(src);
		distance[src]=0;
		while(!q.empty())
		{
			int node = q.front();
			q.pop();
			int nodeDist = distance[node];
			for(int it:graph[node])
			{
				if(distance[it]>nodeDist+1)
				{
					q.push(it);
					distance[it]=nodeDist+1;
				}
			}
		}
		for(int i=0;i<V;i++)
		{
			cout<<"hi";
			if(distance[i]==INT_MAX)
			{
				distance[i]=-1;
			}
		}
		return distance;
	}
};
int main()
{
	ShortestPathUnitWeightUndirectedGraph sobj;
	vector<vector<int>> graph = {{},{},{},{4},{3},{},{}};
	vector<int> answer = sobj.shortestPath(graph, 1);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}