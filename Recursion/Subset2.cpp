/*input
6
1 2 2 3 3 4
*/
#include<bits/stdc++.h>
using namespace std;
class Subset2
{
	/* level with size
						[]

		1 		2 		2 		2 		3 		3 		4 
	q
	*/
	void findingSubset(vector<vector<int>> &answer, int ind, int n, vector<int> arr, vector<int> &temp)
	{
		answer.push_back(temp);
		for(int i=ind;i<n;i++)
		{
			if(i!=ind && arr[i]==arr[i-1]) continue;
			temp.push_back(arr[i]);
			findingSubset(answer, i+1, n, arr, temp);
			temp.pop_back();
		}
	}
public:
	vector<vector<int>> generateUniqueSubset(vector<int> arr, int n)
	{
		vector<int> temp;
		vector<vector<int>> answer;
		sort(arr.begin(), arr.end()); 
		findingSubset(answer, 0, n, arr, temp);
		return answer;
	}
};
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Subset2 sObj;
	vector<vector<int>> answer = sObj.generateUniqueSubset(arr,n);
	for(int i=0;i<answer.size();i++)
	{
		for(int j=0;j<answer[i].size();j++)
			cout<<answer[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	return 0;
}