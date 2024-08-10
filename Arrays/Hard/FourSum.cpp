/*input
2
5 8
2 2 2 2 2
6 0
-1 0 1 2 -1 4
*/
#include<bits/stdc++.h>
using namespace std;
class FourSum
{
public:
	vector<vector<int>> bruteForce4Sum(vector<int>arr, int target)
	{
		int n = arr.size();
		set<vector<int>> st;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					for(int l=k+1;l<n;l++)
					{
						int sum = arr[i] + arr[j] + arr[l] + arr[k];
						if(sum == target)
						{
							vector<int> temp = {arr[i], arr[j], arr[l], arr[k]};
							sort(temp.begin(), temp.end());
							st.insert(temp);
						}
					}
				}
			}
		}
		vector<vector<int>> answer (st.begin(), st.end());
		return answer;
	}
	vector<vector<int>> better4Sum(vector<int> arr, int target)
	{
		set<vector<int>> st;
		int n = arr.size();
		for(int i=0;i<n;i++)
		{
			for(int j=i+1; j<n;j++)
			{
				set<int> hashset;
				for(int k=j+1;k<n;k++)
				{

					long long sum = arr[i]+arr[j]+arr[k];
					long long fourth = target-sum;
					if(hashset.find(fourth)!=hashset.end())
					{

						vector<int> temp = {arr[i], arr[j], arr[k], (int)(fourth)};
						sort(temp.begin(), temp.end());
						st.insert(temp);
					}
					hashset.insert(arr[k]);
				}
				
			}
		}
		vector<vector<int>> answer (st.begin(), st.end());
		return answer;
	}
	vector<vector<int>> optimal4Sum(vector<int> arr, int target)
	{
		int n = arr.size();
		vector<vector<int>> answer;
		sort(arr.begin(), arr.end());
		for(int i=0;i<n;i++)
		{
			if(i!=0 && arr[i]==arr[i-1]) continue;
			for(int j=i+1;j<n;j++)
			{
				if(j>i+1 && arr[j]==arr[j-1]) continue;
				int start = j+1;
				int end = n-1;
				while(start < end)
				{
					long long sum = arr[i]+arr[j]+arr[start]+arr[end];
					if(sum<target)
						start++;
					else if(sum>target)
						end--;
					else
					{
						vector<int> temp = {arr[i], arr[j], arr[start], arr[end]};
						answer.push_back(temp);
						start++;
						end--;
						while(start<end && arr[start]==arr[start-1])start++;
						while(start<end && arr[end] == arr[end+1]) end--;
					}
				}
			}
		}
		return answer;
	}
};
void print(vector<vector<int>> arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<"["<<arr[i][0]<<","<<arr[i][1]<<","<<arr[i][2]<<","<<arr[i][3]<<"]"<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cout<<"Test Case"<<endl;
		int n;
		cin>>n;
		int target;
		cin>>target;
		vector <int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		FourSum fs;
		cout<<"BruteForce Approach"<<endl;
		vector<vector<int>> answer = fs.bruteForce4Sum(arr, target);
		print(answer);
		cout<<"Better Approach"<<endl;
	    answer = fs.better4Sum(arr, target);
		print(answer);
		cout<<"Optimal Approach"<<endl;
		answer = fs.optimal4Sum(arr, target);
		print(answer);
	}
	return 0;
}