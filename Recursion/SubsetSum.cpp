/*input
3
5 2 1
*/
#include<bits/stdc++.h>
using namespace std;
class SubsetSum
{
	/* 

		Each level with new number add or no add
 		Level 0                           x
  		Level 5                 5                     x
		Level 2          5 2          5       2                 x
		Level 1     [5 2 1]   [5 2]  [5 1]    [5]  [2 1]   [2]          [1]    [x]
 					X
			5				X

					5 2 1             x


	*/
	void genSSRecursive(vector<int> &answer, int sum, int n, vector<int> arr, int i)
	{
		//cout<<"sum: "<<sum<<endl;
		if(i==n)
		{
			answer.push_back(sum);
			return;
		}
		genSSRecursive(answer, sum+arr[i], n, arr,i+1);
		genSSRecursive(answer, sum, n, arr,i+1);
	}
public:
	vector<int> generateSubsetSum(vector<int> arr, int n)
	{
		vector<int> answer;
		genSSRecursive(answer, 0, n, arr, 0);
		sort(answer.begin(), answer.end());
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
	SubsetSum sObj;
	vector<int> answer = sObj.generateSubsetSum(arr, n);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}