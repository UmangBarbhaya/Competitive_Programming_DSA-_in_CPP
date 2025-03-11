#include<bits/stdc++.h>
using namespace std;
class DijkstrasSet
{
public:
	vector<int> findShortestPath(vector<vector<pair<int,int>>> adj, int src)
	{
		int V = adj.size();
		vector<int> dist(V, 1e9);
		dist[src] = 0;
		set<pair<int,int>> st;
		st.insert({0,src});
		while(!st.empty())
		{
			auto it = *(st.begin());
			int node = it.second;
			int weight = it.first;
			st.erase(it);
			for(auto elem: adj[node])
			{
				int newnode = elem.first;
				int newweight = elem.second;
				if(dist[newnode] > newweight+weight)
				{
					if(dist[newnode]!=1e9)
					{
						st.erase({dist[newnode],newnode});
					}
					dist[newnode]= newweight+weight;

					st.insert({newweight+weight, newnode});
				}
			}
		}
		return dist;
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
	DijkstrasSet dobj;
	vector<int> ans = dobj.findShortestPath(adj, src);
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