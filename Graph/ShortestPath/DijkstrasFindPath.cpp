#include<bits/stdc++.h>
using namespace std;
class DijkstrasFindPath
{
public:
	vector<int> findShortestPath(int src, int dest, vector<vector<pair<int,int>>> adj)
	{
		int V = adj.size();
		vector<int> dist(V,1e9);
		vector<int> parent(V,0);
		dist[src]=0;
		priority_queue<pair<int,int>> pq;
		pq.push({0,src});
		parent[src] = -1;
		while(!pq.empty())
		{
			int node = pq.top().second;
			int nodewt = pq.top().first;
			pq.pop();
			for(auto it: adj[node])
			{
				int newnode = it.first;
				int newnodewt = it.second;
				if(dist[newnode]>newnodewt+nodewt)
				{
					dist[newnode]=newnodewt+nodewt;
					pq.push({dist[newnode],newnode});
					parent[newnode] = node;
				}
			}
		}
		vector<int> ans;
		int i = dest;
		for(int x:parent)
		{
			cout<<x<<" ";
		}
		cout<<endl;
		while(i!=-1 && dist[i]!=1e9)
		{
			ans.push_back(i);
			i = parent[i];
		}
		reverse(ans.begin(),ans.end());
		return ans;
	}
};
int main()
{
	vector<vector<pair<int,int>>> adj = {
								{{1,1},{2,6}},
								{{0,1},{2,3}},
								{{0,6},{1,3}}
							};
	int src = 2;
	DijkstrasFindPath dobj;
	vector<int> ans = dobj.findShortestPath(0,2,adj);
	for(int ele: ans)
	{
		cout<<ele<<" ";
	}
	cout<<endl;
	return 0;
}
/*
  1 3
0--1--2
|     |
-------
   6
*/