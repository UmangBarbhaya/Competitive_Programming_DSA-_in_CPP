/*input
1
9
104 103 2 1 1 4 102 3 104
*/
#include<bits/stdc++.h>
using namespace std;
class LongestConsecutiveSequence
{
	private:
		bool linearSearch(vector<int> arr, int elem)
		{
			for(int i=0;i<arr.size();i++)
			{
				if(arr[i]==elem)
					return true;
			}
			return false;
		}
	public:
		int findLCSBruteForce(vector <int> inputArr)
		{
			int n = inputArr.size();
			if(n==0)
				return 0;
			int answer=1;
			
			for(int i=0;i<n;i++)
			{
				int x = inputArr[i];
				int cnt = 1;
				while(linearSearch(inputArr,x+1))
				{
					cnt++;
					x++;
				}
				answer = max(answer,cnt);
			}
			return answer;
		}
		int findLCSBetter(vector <int> inputArr)
		{
			int n = inputArr.size();
			if(n==0)
				return 0;
			int answer=1;
			int lastSmallest = INT_MIN;
			int cnt =0;
			sort(inputArr.begin(), inputArr.end());
			for(int i=0;i<n;i++)
			{
				if(inputArr[i]-1 == lastSmallest)
				{
					cnt++;
					lastSmallest = inputArr[i];
				}
				else if(inputArr[i] == lastSmallest)
				{

				}
				else
				{
					cnt=1;
					lastSmallest = inputArr[i];
				}
				answer = max(answer,cnt);
			}
			
			return answer;
		}
		int findLCSOptimal(vector <int> inputArr)
		{
			int n = inputArr.size();
			if(n==0)
				return 0;
			unordered_set <int> st;
			for(int i=0;i<n;i++)
			{
				st.insert(inputArr[i]);
			}
			int answer=1;
			for(auto it: st)
			{
				if(st.find(it-1) == st.end())
				{
					int cnt = 1;
					int x = it;
					while(st.find(x+1)!=st.end())
					{
						cnt++;
						x++;
					}
					answer = max(answer,cnt);
				}
			}
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
		vector<int> inputArr(n);
		for(int i=0;i<n;i++)
		{
			cin>>inputArr[i];
		}
		LongestConsecutiveSequence lcsObj;
		cout<<lcsObj.findLCSBruteForce(inputArr)<<endl;
		cout<<lcsObj.findLCSBetter(inputArr)<<endl;
		cout<<lcsObj.findLCSOptimal(inputArr)<<endl;
	}
	return 0;
}