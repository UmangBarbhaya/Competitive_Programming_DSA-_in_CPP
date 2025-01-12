/*input
6
4
0 1
1 2
2 3
0 4
*/
#include<bits/stdc++.h>
using namespace std;
class DFS
{
private:
	void DFSHelper(vector<int> adjList[], int nodes, int start, int visited[], vector<int> &answer)
	{
		stack<int> s;
		s.push(start);
		visited[start] =1;
		while(!s.empty())
		{
			int curr = s.top();
			s.pop();
			answer.push_back(curr);
			for(int i = 0;i<adjList[curr].size();i++)
			{
				int neighbour = adjList[curr][i];
				if(visited[neighbour] == 1)
					continue;
				s.push(neighbour);
				visited[neighbour] = 1;
			}
		}
	}
public:
	vector<int> findDFS(vector<int> adjList[], int nodes)
	{
		int visited[nodes]={0};
		vector<int> answer;

		for(int i=0;i<nodes;i++)
		{
			if(visited[i]==0)
			{
				DFSHelper(adjList, nodes, i, visited, answer);
			}
		}
		return answer;
	}
};
void addEdge(vector<int> adjList[], int u, int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
int main()
{
	int nodes;
	cin>>nodes;
	int edges;
	cin>>edges;
	vector<int> adjList[nodes];
	for(int i = 0; i<edges; i++)
	{
		int u,v;
		cin>>u;
		cin>>v;
		addEdge(adjList,u,v);
	}
	DFS dobj;
	vector<int> answer = dobj.findDFS(adjList,nodes);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}