/*input
2
6
-1 0 1 2 -1 4
4
-1 0 1 0
*/
#include<bits/stdc++.h>
using namespace std;
class ThreeSum
{
public:
	vector<vector<int>> bruteForce3Sum(vector<int> arr)
	{
		int n = arr.size();
		set<vector<int>> st;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					if(arr[i]+arr[j]+arr[k] == 0)
					{
						vector<int> temp = {arr[i], arr[j], arr[k]};
						sort(temp.begin(),temp.end());
						st.insert(temp);

					}
				}
			}
		}
		vector<vector<int>> answer(st.begin(), st.end());
		return answer;
	}
	vector<vector<int>> better3Sum(vector<int> arr)
	{
		int n = arr.size();
		set<vector<int>> st;
		for(int i=0;i<n;i++)
		{
			set<int> hashset;
			for(int j=i+1;j<n;j++)
			{
				int third = -(arr[i]+arr[j]);
				if(hashset.find(third) != hashset.end())
				{
					vector<int> temp = {arr[i],arr[j],third};
					sort(temp.begin(),temp.end());
					st.insert(temp);
				}
				hashset.insert(arr[j]);
			}
			
		}
		vector<vector<int>> answer(st.begin(), st.end());
		return answer;
	}
	vector<vector<int>> optimal3Sum(vector<int> arr)
	{
		int n = arr.size();
		vector<vector<int>> answer;
		sort(arr.begin(), arr.end());
		for(int i=0;i<n;i++)
		{
			if(i!=0 && arr[i]==arr[i-1]) continue;
			int j=i+1;
			int k = n-1;
			while(j<k)
			{
				int sum = arr[i]+arr[j]+arr[k];
				if(sum<0) j++;
				else if(sum>0) k--;
				else
				{
					vector <int> temp = {arr[i], arr[j], arr[k]};
					answer.push_back(temp);
					j++;
					k--;
					while(j<k && arr[j] == arr[j-1]) j++;
					while(j<k && arr[k] == arr[k+1]) k--;
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
		cout<<"["<<arr[i][0]<<","<<arr[i][1]<<","<<arr[i][2]<<"]"<<endl;
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
		vector <int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ThreeSum ts;
		cout<<"BruteForce Approach"<<endl;
		vector<vector<int>> answer = ts.bruteForce3Sum(arr);
		print(answer);
		cout<<"Better Approach"<<endl;
	    answer = ts.better3Sum(arr);
		print(answer);
		cout<<"Optimal Approach"<<endl;
		answer = ts.optimal3Sum(arr);
		print(answer);
	}
	return 0;
}