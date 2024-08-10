/*input
1
8
1 2 3 1 2 2 1 3
*/
#include<bits/stdc++.h>
using namespace std;
class ElementsGreaterThanFloorOfNBy3
{
public:	
	vector<int> bruteForce(vector<int> arr)
	{
		int n = arr.size();
		vector<int> answer;
		for(int i=0;i<n;i++)
		{
			if(answer.size()==0 || answer[0]!=arr[i])
			{
				int count=0;
				for(int j=0;j<n;j++)
				{
					if(arr[i]==arr[j])
					{
						count++;
					}
				}
				if(count>(n/3))
					answer.push_back(arr[i]);

			}
			if(answer.size()==2)
				break;
		}
		return answer;
	}
	vector<int> hashing(vector<int> arr)
	{
		int n = arr.size();
		vector<int> answer;
		map <int,int> mpp;
		for(int i=0;i<n;i++)
		{
			mpp[arr[i]]++;
			if(mpp[arr[i]]>n/3)
			{
				answer.push_back(arr[i]);
			}
		}
		sort(answer.begin(),answer.end());
		return answer;
	}
	vector<int> optimalMooreVoting(vector<int> arr)
	{
		int n = arr.size();
		vector<int> answer;
		int count1=0;
		int count2=0;
		int element1;
		int element2;
		for(int i=0;i<n;i++)
		{
			if(count1==0 && element2!=arr[i])
			{
				count1 = 1;
				element1 = arr[i];
			}
			else if(count2==0 && element1!=arr[i]) 
			{
				count2=1;
				element2=arr[i];
			}
			else if(element1==arr[i])
			{
				count1++;
			}
			else if(element2==arr[i])
			{
				count2++;
			}
			else
			{
				count1--;
				count2--;
			}
		}
		count1=0;
		count2=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==element1)
				count1++;
			else if(arr[i]==element2)
				count2++;
		}
		if(count1>n/3)
			answer.push_back(element1);
		if(count2>n/3)
			answer.push_back(element2);
		return answer;
	}
};
void print(vector<int> arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
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
		ElementsGreaterThanFloorOfNBy3 e3Obj;
		vector<int> ans = e3Obj.bruteForce(arr);
		print(ans);
		ans = e3Obj.hashing(arr);
		print(ans);
		ans = e3Obj.optimalMooreVoting(arr);
		print(ans);
	}
	return 0;
}