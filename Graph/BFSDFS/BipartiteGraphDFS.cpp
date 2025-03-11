#include<bits/stdc++.h>
using namespace std;
class BipartiteGraphDFS
{
public:
	bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> visited(nodes,-1);
        bool ans=true;
        for(int i=0;i<nodes;i++)
        {
        	if(visited[i]==-1)
        	ans = ans && dfs(graph, visited, i, -1);
        }
        return ans;

    }
private:
	bool dfs(vector<vector<int>>& graph, vector<int> &visited, int curr, int parentcolor)
	{
		if(visited[curr]!=-1 && visited[curr] == parentcolor)
			return false;
		if(visited[curr]!=-1 && visited[curr] != parentcolor)
			return true;
		int newcolor = (parentcolor+1)%2;
		visited[curr] = newcolor;
		bool ans = true;
		for(auto it : graph[curr])
		{
			ans = ans && dfs(graph, visited, it, newcolor);
		}
		return ans;
	}
};
int main()
{
	BipartiteGraphDFS bobj;

	vector<vector<int>>adj = {{1,3},{0,2},{1,3},{0,2},};
	

	cout<<bobj.isBipartite(adj)<<endl;

	return 0;
}