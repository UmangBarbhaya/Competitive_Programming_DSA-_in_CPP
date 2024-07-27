/*input
6
10 22 12 3 0 6
*/
#include<bits/stdc++.h>
using namespace std;
class LeadersinArray
{
public:
	vector<int> findLeader(vector<int> arr)
	{
		vector<int> answer;
		int max = INT_MIN;
		for(int i=arr.size()-1;i>=0;i--)
		{
			if(arr[i]>max)
			{
				max= arr[i];
				answer.push_back(arr[i]);
			}
		}
		reverse(answer.begin(),answer.end());
		return answer;
	}
};
void print(vector <int> arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	LeadersinArray LAObj;
	vector<int> answer = LAObj.findLeader(arr);
	print(answer);
	return 0;
}