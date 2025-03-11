#include<bits/stdc++.h>
using namespace std;
class DijkstrasPQ
{
public:
	vector<int> findShortestPath(vector<vector<pair<int, int>>> &adj, int src)
	{
		int V = adj.size();
		vector<int> dist(V,1e9);
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
		dist[src] = 0;
		minh.push({0,src});
		while(!minh.empty())
		{
			int node = minh.top().second;
			
			int wt = minh.top().first;
			minh.pop();
			for(auto it: adj[node])
			{
				int newnode = it.first;
				int newWeight = it.second+wt;
				if(dist[newnode]>newWeight)
				{
					dist[newnode] = newWeight;
					minh.push({newWeight, newnode});
				}
			}
		}

		return dist;
	}
};
int main()
{
	vector<vector<pair<int,int>>> adj = {
										{{1, 1}, {2, 6}}, 
										{{2, 3}, {0, 1}}, 	
										{{1, 3}, {0, 6}}};
	int src = 2;
	DijkstrasPQ obj;

        vector<int> res = obj.findShortestPath(adj,src);
        for (auto x : res) {
            cout << x << " ";
        }
	return 0;
}

/*
  1   3
0 - 1 - 2
|       |
 -------
 	6
src = 2;

We have two data structure, min_heap and distance vector

0 	1 	2
xx xx   0
*/