/*input
2
4
1 3
2 6
8 10
15 18
2
1 4
4 5
*/
#include<bits/stdc++.h>
using namespace std;
class MergeOverlappingSubIntervals
{
	public:
		vector<vector<int>> mergeOverlappingSubIntervals(vector<vector<int>> arr)
		{
			int n = arr.size();
			vector<vector<int>> answer;
			sort(arr.begin(), arr.end());
			for(int i=0;i<n;i++)
			{
				if(answer.empty() || answer.back()[1]<arr[i][0])
				{
					answer.push_back(arr[i]);
				}
				else
				{
					answer.back()[1] = max(answer.back()[1], arr[i][1]);
				}
			}
			return answer;
		}

};
void print(vector<vector<int>> ans)
{
	cout<<"[";
	for(int i=0;i<ans.size();i++)
	{
		cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"],";
	}
	cout<<"]"<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<vector<int>> arr(n);
		for(int i=0;i<n;i++)
		{
			arr[i] = vector<int>(2);
			cin>>arr[i][0];
			cin>>arr[i][1];
		}
		MergeOverlappingSubIntervals mosObj;
		vector<vector<int>> ans = mosObj.mergeOverlappingSubIntervals(arr);
		print(ans);
	}
	return 0;
}