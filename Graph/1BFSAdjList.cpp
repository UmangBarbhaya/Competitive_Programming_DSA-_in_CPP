/*input
6
5
1 3
0 2
3 5
2 5
2 1
*/
/*
0-2-1-3-5  4
  |     | 
  ------- 
*/
class BFSAdjList
{
public:
	void BFSAdjList(vector<int> graph[])
	{
		
	}
};
void addEdge(vector<int> graph[], int x, int y)
{
	graph[x].push_back(y);
	graph[y].push_back(x);
}
int main()
{
	int N;
	cin>>N;
	int edges;
	cin>>edges;
	vector<int> graph[N];
	for(int i=0;i<edges;i++)
	{
		int x,y;
		cin>>x;
		cin>>y;
		addEdge(graph,x,y);
	}
	return 0;
}