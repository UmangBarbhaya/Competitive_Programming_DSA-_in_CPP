/*input
7 8
10 1 2 7 6 1 5
*/
#include<bits/stdc++.h>
using namespace std;
class CombinationSum2
{
/*
1. Sort the array
2. Since no duplicate the pick no pick will take extra TC of KLogK to remove the duplicate and sort it
3. Pick each level pick based on size of output

1 2 2 3 target 3

size 10																[](){0}
size 1								[1](2){1}      					[2](1){2}						[3][0][3]    (answer) 
size 2 		        (answer)[1 2]{0}{2} [1 3] {-1}          [2,2](-1){3}  [2,3](-2){4}              return
size 3				return           return					return           return					
size 4
*/
private:
	void generateCS(vector<vector<int>> &answer, vector<int> &temp, vector<int> arr, int target, int n, int ind)
	{
		if(target==0)
			answer.push_back(temp);
		if(target<0)
			return;
		for(int i=ind;i<n;i++)
		{
			if(i!=ind && arr[i]==arr[i-1])continue;
			temp.push_back(arr[i]);
			generateCS(answer, temp, arr, target-arr[i], n, i+1);
			temp.pop_back();
		}
	}
public:
	vector<vector<int>> getCombinationSum(vector<int> arr, int target, int n)
	{
		vector<int> temp;
		vector<vector<int>> answer;
		sort(arr.begin(), arr.end());
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
	CombinationSum2 cObj;
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