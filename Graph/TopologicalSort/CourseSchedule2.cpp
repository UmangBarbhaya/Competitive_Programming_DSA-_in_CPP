#include<bits/stdc++.h>
using namespace std;
class CourseSchedule2
{
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
	{
    	vector<int> graph[numCourses];
		for(int i=0;i<prerequisites.size();i++)
		{
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

		}

    	vector<int> answer;
    	vector<int> indegree(numCourses,0);
    	for(int i=0;i<numCourses;i++)
    	{
    		for(int it:graph[i])
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
    		int node = q.front();
    		answer.push_back(node);
    		q.pop();
    		for(auto it: graph[node])
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
            {
                vector<int> temp;
                return temp;
            }
				
		}
    	return answer;   
        
    }

};
int main()
{
	int numCourses = 2;
	vector<vector<int>> prerequisites = {{1,0}};
	CourseSchedule2 cobj;
	vector<int> answer = cobj.findOrder(numCourses, prerequisites);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}