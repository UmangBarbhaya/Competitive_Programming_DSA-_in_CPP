#include<bits/stdc++.h>
using namespace std;
class DFSMatrix
{
public:
	vector<int> getDFS(vector<vector<int>> graph, int N)
	{
		vector<int> answer;
		vector<int> visited(N);
		for(int i=0;i<N;i++)
		{
			if(visited[i]==0)
			{
				
				getDFSUtil(graph,N,i,visited,answer);
			}
		}
		return answer;

	}
private:
	void getDFSUtil(vector<vector<int>> graph, int N, int src, vector<int> &visited, vector<int> &answer)
	{
		stack <int> s;
		s.push(src);
		visited[src] = 1;
		while(!s.empty())
		{
			int curr = s.top();
			s.pop();
			
			answer.push_back(curr);
			for(int i=0;i<N;i++)
			{
				if(graph[curr][i]==1 && visited[i]==0)
				{
					s.push(i);
					visited[i]=1;
				}
			}
		}
	}
};
int main()
{
	vector<vector<int>> graph = 
	{
		{0,1,0,0,1,0},
		{1,0,1,0,1,0},
		{0,1,0,1,1,0},
		{0,0,1,0,1,0},
		{1,1,1,1,1,0},
		{0,0,0,0,0,0}
	};
	int N = 6;
	DFSMatrix dobj;
	vector<int> answer = dobj.getDFS(graph, N);
	for(int i=0; i<answer.size(); i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}