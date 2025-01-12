/*input
4 7
2 3 6 7
*/
#include<bits/stdc++.h>
using namespace std;
class CombinationSum1
{
/*
reuse the same element mutiple times
																		[](0){7}
													[2](0){5}												[](1)
										[2,2](0){3}
						[2,2,2](0){1}		[2,2](1)()
				x
*/
private:
	void generateCS(vector<vector<int>> &answer, vector<int> &temp, vector<int> arr, int target, int n, int ind)
	{
		if(target==0 && n==ind)
			answer.push_back(temp);
		if(n==ind || target<0)
			return;
		temp.push_back(arr[ind]);
		generateCS(answer, temp, arr, target-arr[ind], n, ind); //resuing same element twice
		temp.pop_back();
		generateCS(answer, temp, arr, target, n, ind+1);
	}
public:
	vector<vector<int>> getCombinationSum(vector<int> arr, int target, int n)
	{
		vector<vector<int>> answer; 
		vector<int> temp;
		generateCS(answer, temp, arr, target, n, 0);
		return answer;
	}
};
int main()
{
	int n;
	cin>>n;
	int target;
	cin>>target;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	CombinationSum1 cObj;
	vector<vector<int>> answer = cObj.getCombinationSum(arr,target,n);
	for(int i=0;i<answer.size();i++)
	{
		for(int j=0;j<answer[i].size();j++)
			cout<<answer[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	return 0;
}