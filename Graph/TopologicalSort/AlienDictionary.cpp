#include<bits/stdc++.h>
using namespace std;
class AlienDictionary
{
public:
	vector<char> decipherAlienWordPrecedence(int N, int K, vector<string> dict)
	{
		vector<char> answer;
		vector<int> graph[K];
		for(int i=0;i<N-1;i++)
		{
			string string1 = dict[i];
			string string2 = dict[i+1];
			int size = min(string1.size(), string2.size());
			for(int j=0;j<size;j++)
			{
				if(string1[j]!=string2[j])
				{
					graph[string1[j]-'a'].push_back(string2[j]-'a');
					break;
				}
			}

		}
		vector<int> indegree(K,0);
		for(int i=0;i<K;i++)
		{
			for(auto it: graph[i])
			{
				indegree[it]++;
			}

		}
		queue<int> q;
		for(int i=0;i<K;i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int node = q.front();
			answer.push_back(char(node+'a'));
			q.pop();
			for(int it: graph[node])
			{
				indegree[it]--;
				if(indegree[it]==0)
				{
					q.push(it);
				}
			}
		}
		return answer;
	}
};
int main()
{
	AlienDictionary aobj;
	int N = 5;
	int K = 4;
	vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};

	vector<char> answer = aobj.decipherAlienWordPrecedence(N,K,dict);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}