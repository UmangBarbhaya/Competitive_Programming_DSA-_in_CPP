/*input
2
5 14
1 2 3 8 6
3 100
1 2 3
*/
#include<bits/stdc++.h>
using namespace std;
class TwoSum
{
public:
	vector <int> findTwoSumHashing(vector <int> arr, int target)
	{
		
		map <int,int> remMap;
		for(int i=0;i<arr.size();i++)
		{
			if(remMap.find(arr[i])!=remMap.end())
			{
				vector<int> answer ={remMap[arr[i]],i};
				return answer; 
			}
			remMap[target-arr[i]]=i;
		}
		vector<int> answer ={-1,-1};
		return answer;
	}
	bool findTwoSumSortTwoPointer(vector <int> arr, int target) 	
	{
		sort(arr.begin(), arr.end());
    	int left = 0, right = arr.size() - 1;
	    while (left < right) {
	        int sum = arr[left] + arr[right];
	        if (sum == target) {
	            return true;
	        }
	        else if (sum < target) left++;
	        else right--;
	    }
	    return false;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, target;
		cin>>n;
		cin>>target;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		TwoSum ts_obj;
		vector <int> answer = ts_obj.findTwoSumHashing(arr,target);
		cout<<answer[0]<<" "<<answer[1]<<endl; 
		bool answer2 = ts_obj.findTwoSumSortTwoPointer(arr,target);
		cout<<answer2<<endl; 
	}
	return 0;
}