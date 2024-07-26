/*input
1
15
7 7 5 7 5 1 5 7 5 5 7 7 5 5 5
*/
#include<bits/stdc++.h>
using namespace std;
class ElementGreaterThanHalfofn
{
public:
	int mooresVotingApproach(vector<int> arr)
	{
		int n = arr.size();
		int element = 0;
		int count = 0;
		for(int i=0;i<n;i++)
		{
			if(count==0)
			{
				element=arr[i];
				count++;
			}
			else if(arr[i]==element)
				count++;
			else
				count--;
		}
		int count2=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==element)
				count2++;
		}
		if(count2>n/2)
			return element;
		return -1;

	}
	int hashMapApproach(vector <int> arr)
	{
		int n = arr.size();
		map<int,int> mpp;
		for(int i=0;i<n;i++)
		{
			mpp[arr[i]]++;
		}
		for(auto it: mpp)
		{
			if(it.second>n/2)
			{
				return it.first;
			}
		}
		return -1;
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
		vector <int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ElementGreaterThanHalfofn eghn_obj;
		cout<<"Using Maps: "<<eghn_obj.hashMapApproach(arr)<<endl;
		cout<<"Using Moore's Voting Algorithm: "<<eghn_obj.mooresVotingApproach(arr)<<endl;
	}
	
	return 0;
}
