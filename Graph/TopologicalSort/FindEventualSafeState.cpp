#include<bits/stdc++.h>
using namespace std;
class FindEventualSafeState
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj)
    {
    	int V = adj.size();
    	vector<int> answer;

    	//reverse graph to make outdegree to indegree
    	vector<int> graph[V];
    	for(int i=0;i<V;i++)
    	{
    		for(int it: adj[i])
    		{
    			graph[it].push_back(i);
    		}
    	}
    	vector<int> indegree(V,0);
    	for(int i=0;i<V;i++)
    	{
    		for(int it: graph[i])
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
    			answer.push_back(i);
    		}
    	}
    	while(!q.empty())
		{
			int node = q.front();
			q.pop();
			for(int it: graph[node])
			{
				indegree[it]--;
				if(indegree[it]==0)
				{
					answer.push_back(it);
					q.push(it);
				}
			}
		}
		sort(answer.begin(),answer.end());
		return answer;
    	
    }
};
int main()
{
	vector<vector<int>> adj = {{1,2},{2,3},{5},{0},{5},{},{}};
	FindEventualSafeState fobj;
	vector<int> answer = fobj.eventualSafeNodes(adj);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}