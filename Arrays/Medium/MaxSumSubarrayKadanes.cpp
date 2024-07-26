/*input
1
9
-2 1 -3 4 -1 2 1 -5 4
*/
#include<bits/stdc++.h>
using namespace std;
class MaxSumSubarrayKadanes
{
public:
	vector <long long> kadanesMaxSumSubarray(vector<int> arr)
	{
		vector<long long> answer;
		long long maxi = LONG_MIN;
		long long sum = 0;

		int start = 0;
		int ansstart=-1,ansend=-1;
		for(int i=0;i<arr.size();i++)
		{
			if(sum==0)
				start = i;
			sum += arr[i];
			if(sum>maxi)
			{
				maxi=sum;
				ansstart = start;
				ansend = i;
			}
			if(sum<0)
			{
				sum = 0;
			}
		}

		answer.push_back(maxi);
		answer.push_back(ansstart);
		answer.push_back(ansend);
		return answer;
	}

};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		MaxSumSubarrayKadanes mssk_obj;
		vector <long long> answer = mssk_obj.kadanesMaxSumSubarray(arr);
		cout<<"Maximum sum of subarray: "<<answer[0]<<endl;
		cout<<"Below is the subarray:"<<endl;

		for(int i=answer[1];i<=answer[2];i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}