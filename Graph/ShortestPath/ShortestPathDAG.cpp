/*input
1
10
24
0 2 6
0 3 7
0 4 9
0 6 8
0 7 6
1 2 6
1 3 7
1 5 10
1 6 1
1 7 4
2 3 3
2 6 10
2 8 8
2 9 10
3 5 3
3 6 10
3 7 5
5 6 9
5 7 7
6 7 7
6 8 8
6 9 8
7 9 1
8 9 6
*/
#include<bits/stdc++.h>
using namespace std;
class ShortestPathDAG
{
public:
	vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
	{
        // code here
  		//Find the graph 
  		vector<pair<int, int>> graph[V];
  		for(int i=0;i<E;i++)
  		{
  			graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
  		}

  		//Find the topo sort
  		stack<int> st = topoSort(graph,V);
  		vector < int > dist(V);
      for (int i = 0; i < V; i++) {
        dist[i] = 1e9;
      }

  		dist[0] = 0;
  		while(!st.empty())
  		{
  			int node = st.top();
  			st.pop();
  			for(auto it: graph[node])
  			{
  				if(dist[it.first] > dist[node]+it.second)
  				{
  					dist[it.first] = dist[node]+it.second;
  				}
  			}
  		}
  		for(int i=0;i<V;i++)
  		{
  		    if(dist[i]==1e9)
  		    {
  		        dist[i]=-1;
  		    }
  		}
  		return dist;
    }
private:
	stack<int> topoSort(vector<pair<int, int>> graph[], int V)
	{
		cout<<max(INT_MAX,(int)1e9)<<endl;
		stack<int> ansst;
		vector<int> visited(V,0);
		for(int i=0;i<V;i++)
		{

			if(visited[i]==0)
				dfs(graph, i, visited, ansst);
		}
		return ansst;
	}
	void dfs(vector<pair<int, int>> graph[], int src, vector<int> &visited, stack<int> &ansst)
	{

		visited[src]=1;
		for(auto it: graph[src])
		{
			if(!visited[it.first])
			{
				dfs(graph, it.first, visited, ansst);
			}
		}

		ansst.push(src);
	}
};
int main()
{
	int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) 
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) 
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        ShortestPathDAG obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
             return 0;
         }
}