/*input
11
1 1 0 1 1 1 0 1 1 1 1
*/
#include<bits/stdc++.h>
using namespace std;
class MaximumConsecutiveOnes
{
public:
	int findMaximumConsecutiveOnes(vector<int> arr)
	{
		int answer = 0;
		int count = 0;
		for(int i=0;i<arr.size();i++)
		{
			if(arr[i]==0)
			{
				answer=max(answer,count);
				count =0;
			}
			else
				count++;
		}
		answer = max(answer,count);
		return answer;
	}
};
int main()
{
	int n;
	cin>>n;
	vector <int> inputArr(n);
	for(int i=0;i<n;i++)
	{
		cin>>inputArr[i];
	}
	MaximumConsecutiveOnes mco_obj;
	cout<<"Maximum Consecutive Ones: "<<mco_obj.findMaximumConsecutiveOnes(inputArr)<<endl;
	return 0;
}