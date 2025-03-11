#include<bits/stdc++.h>
using namespace std;
class CourseSchedule1
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<int> indegree(numCourses, 0);
		vector<int> graph[numCourses];
		for(int i=0;i<prerequisites.size();i++)
		{
			graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

		}
		for(int i=0;i<numCourses;i++)
		{
			for(auto it: graph[i])
			{
				indegree[it]++;
			}
		}
		queue<int> q;
		for(int i=0;i<numCourses;i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int course = q.front();
			q.pop();
			for(int it: graph[course])
			{
				indegree[it]--;
				if(indegree[it]==0)
				{
					q.push(it);
				}
			}
		}
		for(int i=0;i<numCourses;i++)
		{
			if(indegree[i]!=0)
				return false;
		}
		return true;
	}


};
int main()
{
	int numCourses = 2;
	vector<vector<int>> prerequisites = {{1,0}};
	CourseSchedule1 cobj;
	cout<< cobj.canFinish(numCourses, prerequisites)<<endl;
	return 0;
}