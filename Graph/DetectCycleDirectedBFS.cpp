/*input
*/
#include<bits/stdc++.h>
using namespace std;
class DetectCycleDirectedBFS
{
private:
	bool isCycle( vector<int> adj[], int start, vector<int> &vis)
	{
		queue <pair<int,int>> q;
		q.push({start,-1});
		vis[start]=1;
		while(!q.empty())
		{
			int curr = q.front().first;
			int parent = q.front().second;
			q.pop();
			for(auto elem : adj[curr])
			{
				if(!vis[elem])
				{
					q.push({elem, curr});
					vis[elem] = 1;
				}
				else if(parent!=elem)
				{
						return true;
				}
			}
		}
		return false;
	}
public:
	bool isCycle(int V, vector<int> adj[])
	{
		vector<int> vis(V,0);
		vis[0]=1;
		
		for(int i=0;i<V;i++)
		{
			if(!vis[i])
			{
				if(isCycle(adj, i, vis))
					return true;
			}
		}
		return false;
	}
};
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int V = 8;
	vector<int> adj[V];
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,2,5);
	addEdge(adj,3,4);
	addEdge(adj,3,6);
	addEdge(adj,5,7);
	addEdge(adj,6,7);

	DetectCycleDirectedBFS dObj;
	cout<<dObj.isCycle(V, adj)<<endl;
	return 0;
}