/*input
4
1 2 3 4
4 1 1 1
20 1 40 30
*/
#include<bits/stdc++.h>
using namespace std;
class Job
{
	public:
		int id;
		int deadline;
		int profit;
};
class JobSequencingProblem
{
private:
	bool static comparator(Job j1, Job j2)
	{
		if(j1.profit < j2.profit)
			return true;
		return false;
	}
public:
	vector<int> profit(int n, Job jobs)
	{
		sort(jobs, jobs+n, comparator);
		
	}
};
int main()
{
	return 0;
}